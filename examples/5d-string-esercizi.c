// Programma per determinare se una parola:
// - contiene piu' 'a' o 'b'
// - e' palindroma
// - contiene lettere ripetute
// Input: una parola (da terminale).
// Output: le risposte alle tre domande.

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Data una parola e un carattere, conta le occorrenze
// di quel carattere nella parola
int conta_occorrenze(char parola[], char chr) {
  int occ= 0;
  int i= 0;
  while (parola[i] != '\0') {
	 if (parola[i] == chr) {
		occ= occ+1;
	 }
	 i= i+1;
  }
  return occ;
}

// Data una parola determina se la parola e' palindroma
bool is_palindroma(char parola[]) {
// Scorre contemporaneamenta da sx->dx e da dx->sx
// per verificare se la parola e' la stessa se letta nei due sensi
  int l= 0, r= strlen(parola)-1;
  while (l<r) { // Mi fermo quando si incontrano in mezzo
	 if (parola[l] != parola[r]) {
// Due caratteri sono diversi, non e' palindroma
		return false;
	 }
	 l= l+1;
	 r= r-1;
  }
// Se non ho incontrato caratteri diversi, la parola e' palindroma
  return true;
}

// Data una parola determina se ha caratteri ripetuti
bool ha_ripetizioni(char parola[]) {
// Scorro la parola da sx->dx e, per ogni carattere, controllo
// se il carattere e' presente nel resto della parola
  int i= 0;
  while (parola[i]!='\0') {
// Controllo i caratteri seguenti, partendo da quello
// immediatamente sucessivo
	 int j= i+1;
	 while (parola[j]!='\0') {
		if (parola[i] == parola[j]) {
// Ho trovato un carattere ripetuto
		  return true;
		}
		j= j+1;
	 }
	 i= i+1;
  }
// Non ho trovato caratteri ripetuti
  return false;
}

int main() {
  char word[100]= "";  // Parola in input

  printf("Inserisci una parola: ");
  scanf("%s", word);

  int occ_a= conta_occorrenze(word, 'a');
  int occ_b= conta_occorrenze(word, 'b');
  if (occ_a < occ_b) {
	 printf("'%s' ha meno 'a' che 'b'.\n", word);
  } else if (occ_a == occ_b) {
	 printf("'%s' ha tante 'a' quante 'b'.\n", word);
  } else {
	 printf("'%s' ha piu' 'a' che 'b'.\n", word);
  }

  if (is_palindroma(word)) {
	 printf("'%s' e' palindroma.\n", word);
  } else {
	 printf("'%s' NON e' palindroma.\n", word);
  }

  if (ha_ripetizioni(word)) {
	 printf("'%s' contiene caratteri ripetuti.\n", word);
  } else {
	 printf("'%s' NON contiene caratteri ripetuti.\n", word);
  }

  return 0;
}
