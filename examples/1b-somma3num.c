// Somma di tre numeri
// Input: tre numeri interi (da terminale)
// Output: la loro somma (su schermo)

// Inclusione della libreria per l'input/output
#include <stdio.h>

int main() {
  int a= 0, b= 0, c= 0; // Dichiarazione delle variabili in input
  int somma= 0;      // Dichiarazione della variabile in output

// Lettura dell'input
  printf("Inserisci il primo numero: ");
  scanf("%d", &a);
  printf("Inserisci il secondo numero: ");
  scanf("%d", &b);
  printf("Inserisci il terzo numero: ");
  scanf("%d", &c);

// Calcolo della somma
  somma= a+b+c;

// Visualizzazione dell'output
  printf("La somma di %d, %d e %d e': %d\n", a, b, c, somma);

// Uscita
  return 0;
}
