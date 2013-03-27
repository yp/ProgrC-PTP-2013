// Somma dei primi n numeri naturali
// Input: un numero naturale n (da terminale)
// Output: la somma dei primi n numeri (su schermo)

// Inclusione della libreria per l'input/output
#include <stdio.h>

int main() {
  int n= 0;      // Dichiarazione della variabile in input
  int somma= 0;  // Dichiarazione della variabile in output

// Lettura dell'input
  printf("Inserisci il numero di numeri che vuoi sommare: ");
  scanf("%d", &n);

// Controllo
  if (n<0) {
	 printf("Il numero non deve essere negativo!\n");
  } else {
// Calcolo della somma
	 int i= 0;
	 while (i<=n) {
		somma= somma + i;
		i= i+1;
	 }
// Visualizzazione dell'output
	 printf("La somma dei primi %d naturali e': %d\n", n, somma);
  }

// Uscita
  return 0;
}
