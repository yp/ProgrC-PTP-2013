


# I/O su file



---

## I/O su file

Input e output possono avvenire anche da/su file.

È molto simile a quello che da/per terminale.

Header: `<stdio.h>`

Si divide idealmente in 3 fasi:

1. apertura del file
2. lettura/scrittura da/su file
3. chiusura del file

---

## 1. Apertura di un file

_Apertura di un file:_

* tipo `FILE`: tipo di variabili contenenti un "link simbolico" a un file
* funzione `FILE* fopen(char* name, char* mode)`: funzione per aprire un file di nome `name` in lettura (mode: `"r"`) o in scrittura (mode: `"w"`)

_Esempio:_
{: .lesserspaceafter}

    !c
    ...
    FILE* file= fopen("dati.txt", "r"); 
                      //          "r": lettura
                      //          "w": scrittura
    ...

---

## E se il file non esistesse?

Se errore in apertura, `fopen` ritorna `NULL`.

    !c
    ...
    FILE* file= fopen("dati.txt", "r");

    if (file == NULL) {
        printf("Impossibile aprire il file!\n");
        return 1; // Esco con un errore
    }
    ...


---

## 2. Lettura/scrittura

_Lettura scrittura:_

* funzioni `fprintf`/`fscanf`: come le `printf` e `scanf` ma con aggiunto un parametro di tipo `FILE *`
* funzione `bool feof(FILE* file)`: ritorna `true` se ho finito il file (solo in lettura)

_Esempio:_
{: .lesserspaceafter}

    !c
    ...
    while ( !feof(file) ) {
        int p= 0, g= 0;
        fscanf(file, "%d %d", &p, &g);
        printf("Ho letto %d e %d.\n", p, g);
    }
    ...

---

## 3. Chiusura del file

_Chiusura del file:_

* funzione `void fclose(FILE* file)`: chiude il file.

Per usare un file dopo la chiusura dovrei riaprirlo con la `fopen`.

_Esempio:_

    !c
    ...
    fclose(file);
    ...


---

## Esercizio di lettura

In un file di nome `coppie.txt` è memorizzata una lista di coppie di numeri con una coppia per riga, scrivere un programma che legga le coppie e le stampi a schermo.
