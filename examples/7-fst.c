// Programma per il calcolo dell'F_ST
// Input: un file "dati-fst.txt" contenente una sequenza di
// coppie di numeri p g rappresentanti la sottopopolazione e il
// genotipo di un individuo appartenente alla sottopopolazione
// in un locus fisso e unico per tutto il file. (0=AA, 1=Aa, 2=aa)
// Output: F_ST

#include <stdio.h>
#include <stdbool.h>

bool leggi_e_calcola_frequenze_alleliche(int freq[2][10], int* n_pop);

bool leggi_e_calcola_frequenze_alleliche(int freq[2][10], int* n_pop) {
// "Pulisci" le frequenze e il numero di sottopopolazioni
  for (int i= 0; i<10; ++i) {
	 freq[0][i]= 0;
	 freq[1][i]= 0;
  }
  *n_pop= 0;

// 1. Apertura file
  FILE* file= fopen("dati-fst.txt", "r");

  if (file == NULL) {
	 printf("Impossibile aprire il file!\n");
	 return false; // Esco con un errore
  }

// 2. Lettura del file
  while ( !feof(file) ) {
	 int p= 0, g= 0;
	 fscanf(file, "%d %d\n", &p, &g);
// Controlla se e' una nuova sottopopolazione
	 if (*n_pop<p) {
		*n_pop= p;
	 }
	 if (g == 0) { // g = AA
		freq[0][0] += 2;
		freq[0][p] += 2;
	 } else if (g == 1) { // g = Aa
		freq[0][0] += 1;
		freq[0][p] += 1;
		freq[1][0] += 1;
		freq[1][p] += 1;
	 } else if (g == 2) { // g = aa
		freq[1][0] += 2;
		freq[1][p] += 2;
	 }
  }

// 3. Chiusura del file
  fclose(file);

  return true;
}

double calcola_fst(int freq[2][10], int n_pop);

double calcola_fst(int freq[2][10], int n_pop) {
  double exp_het[10]= {};

  for (int i= 0; i<=n_pop; ++i) {
	 double n_alleles= freq[0][i]+freq[1][i];
	 exp_het[i] = 2.0*(freq[0][i]/n_alleles)*(freq[1][i]/n_alleles);
  }

  double Hs= 0.0;
  for (int i= 1; i<=n_pop; ++i) {
	 double n_indiv= (freq[0][i]+freq[1][i])/2;
	 Hs += exp_het[i]*n_indiv;
  }
  Hs = Hs / ((freq[0][0]+freq[1][0])/2);

  double Ht= exp_het[0];

  double Fst= (Ht - Hs)/Ht;

  return Fst;
}


// Corpo principale
int main() {
// Freq. alleliche assolute
// freq[i][p] = numero di alleli i nella popolazione p
// se p=0, allora popolazione completa
// se p>0, allora sottopopolazione
  int freq[2][10] = {};
// Numero di sottopopolazioni
  int n_pop= 0;

  bool success= leggi_e_calcola_frequenze_alleliche(freq, &n_pop);

  if (!success) {
	 return 1;
  }

  double fst= calcola_fst(freq, n_pop);

  printf("F_ST = %f\n", fst);

  return 0;
}
