// Programma che calcola la somma di una sequenza di numeri interi
// memorizzati in un array
// Input: la lunghezza n della sequenza, una sequenza di n interi
// Output: la somma dei numeri della sequenza

// Utilizza array e funzioni (anche se non strettamente necessarie)

#include <stdio.h>

// Prototipo
int somma_array(int array[], int lunghezza);

// Definizione
int somma_array(int array[], int lunghezza) {
  int somma= 0;
  for (int i= 0; i<lunghezza; ++i) {
	 somma = somma + array[i];
  }
  return somma;
}


// Corpo principale
int main() {
  int n= 0;         // Input: lunghezza della sequenza
  int seq[100]= {}; // Input: sequenza (lunghezza massima: 100)
  int somma= 0;     // Output

// Lettura di n.
// Devo controllare che non sia minore di 0 o maggiore di 100
  do {
	 printf("Quanto e' lunga la sequenza? (min: 0, max: 100) ");
	 scanf("%d", &n);
  } while ((n<0)||(n>100));

// Lettura della sequenza
  for (int i= 0; i<n; ++i) {
	 printf("Inserisci il %do numero: ", i+1);
	 scanf("%d", &seq[i]);
  }

// Calcolo della somma (con la funzione)
  somma= somma_array(seq, n);

// Stampo output
  printf("La somma dei numeri inseriti e': %d\n", somma);

  return 0;
}
