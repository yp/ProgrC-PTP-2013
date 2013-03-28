// Calcolo del massimo comun divisore di due numeri (con funzione)
// Input: due numeri positivi a e b (da terminale)
// Output: il loro MCD (su schermo)

// Inclusione della libreria per l'input/output
#include <stdio.h>

// Prototipo
int calcola_MCD(int a, int b);

// Definizione
int calcola_MCD(int a, int b) {
// L'MCD e' sicuramente minore o uguale del
// minimo tra a e b
  int MCD= a;
  if (b<MCD) {
	 MCD= b;
  }
// L'MCD deve dividere esattamente (resto=0)
// sia a che b.
// Se uno dei due resti non e' 0, allora decremento l'MCD e provo ancora.
// Termina certamente perche' 1 e' sicuramente un divisore comune di a e b
  while ((a % MCD)>0 || (b % MCD)>0) {
	 MCD= MCD-1;
  }
// Dato che la condizione del while e' falsa,
// significa che a%MCD e b%MCD e' 0, cioe' MCD e' un divisore
// comune. E' il piu' grande divisore comune perche' ho considerato
// tutti dal piu' grande al piu' piccolo
  return MCD;
}


int main() {
  int a= 0, b= 0; // Dichiarazione delle variabili in input
  int MCD= 0;     // Dichiarazione della variabile in output

// Lettura dell'input
  printf("Inserisci due numeri naturali: ");
  scanf("%d %d", &a, &b);

// Controllo
  if ((a<=0) || (b<=0)) {
	 printf("I due numeri devono essere positivi!\n");
  } else {
// Calcolo dell'MCD (usando la funzione)
	 int MCD= calcola_MCD(a, b);
// Visualizzazione dell'output
	 printf("Il massimo comun divisore di %d e %d e': %d\n",
			  a, b, MCD);
  }

// Uscita
  return 0;
}
