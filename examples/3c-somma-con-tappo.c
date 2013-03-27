// Somma di numeri naturali con tappo
// Input: una sequenza di numeri interi che termina con 0 (da terminale)
// Output: la somma dei numeri interi letti (su schermo)

// Inclusione della libreria per l'input/output
#include <stdio.h>

int main() {
  int xi= 0;     // Dichiarazione della variabile in input
  int somma= 0;  // Dichiarazione della variabile in output

// Calcolo della somma
  do {
	 printf("Inserisci il numero (0 per terminare): ");
	 scanf("%d", &xi);
	 somma= somma + xi;
  } while (xi != 0);
// Visualizzazione dell'output
  printf("La somma dei numeri inseriti e': %d\n", somma);

// Uscita
  return 0;
}
