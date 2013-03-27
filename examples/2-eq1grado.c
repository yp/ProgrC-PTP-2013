// Risoluzione di un'equazione di primo grado ax + b = c
// Input: i coefficienti dell'equazione (da terminale)
// Output: la soluzione (se esiste) dell'equazione o errore (su schermo)

// Inclusione della libreria per l'input/output
#include <stdio.h>

int main() {
  double a= 0.0, b= 0.0; // Dichiarazione delle variabili in input
  double x= 0.0;         // Dichiarazione della variabile in output

// Lettura dell'input
  printf("Risoluzione dell'equazione ax + b = 0.\n");
  printf("Inserisci il coefficiente 'a': ");
  scanf("%lf", &a);
  printf("Inserisci il termine noto 'b': ");
  scanf("%lf", &b);

// Controllo che a sia diverso da 0
  if (a == 0.0) {
    printf("Il coefficiente 'a' non puo' essere 0!\n");
  } else {
    x = -b/a;
    printf("La soluzione dell'equazione %lf x + %lf = 0.0 e': %lf\n",
           a, b, x);
  }

// Uscita
  return 0;
}
