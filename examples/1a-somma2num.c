// Somma di due numeri
// Input: due numeri interi (da terminale)
// Output: la loro somma (su schermo)

// Inclusione della libreria per l'input/output
#include <stdio.h>

int main() {
  int a= 0, b= 0; // Dichiarazione delle variabili in input
  int somma= 0;   // Dichiarazione della variabile in output

// Lettura dell'input
  printf("Inserisci il primo numero: ");
  scanf("%d", &a);
  printf("Inserisci il secondo numero: ");
  scanf("%d", &b);

// Calcolo della somma
  somma= a+b;

// Visualizzazione dell'output
  printf("La somma di %d e %d e': %d\n", a, b, somma);

// Uscita
  return 0;
}
