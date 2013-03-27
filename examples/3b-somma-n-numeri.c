// Somma di n numeri naturali
// Input: un numero naturale n e una sequenza di n numeri interi (da terminale)
// Output: la somma degli n numeri interi (su schermo)

// Inclusione della libreria per l'input/output
#include <stdio.h>

int main() {
  int n= 0, xi= 0; // Dichiarazione delle variabili in input
  int somma= 0;    // Dichiarazione della variabile in output

// Lettura dell'input
  printf("Inserisci il numero di numeri che vuoi sommare: ");
  scanf("%d", &n);

// Controllo
  if (n<0) {
	 printf("Il numero non deve essere negativo!\n");
  } else {
// Calcolo della somma
	 int i= 0;
	 while (i<n) {
		printf("Inserisci il numero: ");
		scanf("%d", &xi);
		somma= somma + xi;
		i= i+1;
	 }
// Visualizzazione dell'output
	 printf("La somma dei numeri inseriti e': %d\n", somma);
  }

// Uscita
  return 0;
}
