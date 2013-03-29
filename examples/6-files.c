// Programma che legge dal file "coppie.txt" una sequenza di
// coppie di numeri e che le stampa a schermo
// Input: una sequenza di coppie di numeri interi con una coppia
// per ciascuna riga (da file "coppie.txt")
// Output: le coppie lette (a schermo)

#include <stdio.h>

// Corpo principale
int main() {
  int p= 0, g= 0;   // Input: i due numeri di ciascuna coppia
// Output? nessuna variabile


// 1. Apertura file
  FILE* file= fopen("coppie.txt", "r");

  if (file == NULL) {
	 printf("Impossibile aprire il file!\n");
	 return 1; // Esco con un errore
  }

// 2. Lettura del file
  while ( !feof(file) ) {
	 int p= 0, g= 0;
	 fscanf(file, "%d %d\n", &p, &g);
	 printf("Ho letto %d e %d.\n", p, g);
  }

// 3. Chiusura del file
  fclose(file);

  return 0;
}
