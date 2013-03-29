// Programma per mostrare il funzionamento di alcune funzioni
// predefinite che lavorano su stringhe
// Input: none.
// Output: none.

#include <stdio.h>
#include <string.h>

int main() {
  char s1[100]= "Ciao";
  char s2[100]= "Mario";

  int s1len= strlen(s1);
  printf("La stringa '%s' e' di %d caratteri.\n", s1, s1len);

// Concatena a s1 la stringa (costante) " da "
  strcat(s1, " da ");
  printf("La stringa s1 ora e' '%s'\n", s1);

// Copia in s2 la stringa (costante) "Pippo"
// (il contenuto precedente viene perso)
  strcpy(s2, "Pippo");
  printf("La stringa s2 ora e' '%s'\n", s2);

// Concatena a s1 la stringa s2
  strcat(s1, s2);
  printf("La stringa s1 ora e' '%s'\n", s1);

// Confronta s1 con s2 (ordine lessicografico)
//  0 --> s1 = s2
// <0 --> s1 < s2
// >0 --> s1 > s2
  char s3[100]= "Pluto";
  int cmp= strcmp(s2, s3);
  if (cmp == 0) {
	 printf("'%s' e '%s' sono uguali.\n", s2, s3);
  } else if (cmp < 0) {
	 printf("'%s' e' minore di '%s'.\n", s2, s3);
  } else { // cmp > 0
	 printf("'%s' e' maggiore di '%s'.\n", s2, s3);
  }

  return 0;
}
