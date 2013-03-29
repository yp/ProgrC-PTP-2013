// Programma per mostrare cosa succede se sbaglio a
// gestire le dimensioni delle stringhe
// Input: none.
// Output: none.

#include <stdio.h>
#include <string.h>

int main() {
  char s1[]= "Nulla at eros leo. ";
  char s2[]= "Ut convallis feugiat ligula vel dignissim.";

// La stringa s1 non ha abbastanza spazio per concatenarvi s2!!
  strcat(s1, s2);
  printf("La stringa s1 ora e' '%s'\n", s1);
  printf("La stringa s2 ora e' '%s'\n", s2);

// La stringa s1 aveva gia' finito lo spazio!!
  strcat(s1, s2);
  printf("La stringa s1 ora e' '%s'\n", s1);
  printf("La stringa s2 ora e' '%s'\n", s2);

  return 0;
}
