


# Le funzioni



---

## Le funzioni

**Funzione:** blocco di codice identificato da un nome simbolico che incapsula una _funzionalità ben definita_ e che comunica con il resto del codice mediante un'_interfaccia ben definita_.

_Prototipo:_ specifica del nome e dell'interfaccia della funzione.
_Definizione:_ specifica del codice della funzione.
{: .lesserspacebefore}

    !c
    // Prototipo
    <tipoRitorno> <nome>(<tipo1> <param1>[, <tipo2> <param2>..]);
    
    // Definizione
    <tipoRitorno> <nome>(<tipo1> <param1>[, <tipo2> <param2>..]) {
        <corpo>
        return <expressione>;
    }


---

## Le funzioni

    !c
    // Prototipo
    <tipoRitorno> <nome>(<tipo1> <param1>[, <tipo2> <param2>..]);
    
    // Definizione
    <tipoRitorno> <nome>(<tipo1> <param1>[, <tipo2> <param2>..]) {
        <corpo>
        return <expressione>;
    }

`<tipoN>` `<paramN>` è la dichiarazione di ciascun parametro in ingresso (_input_)

`<tipoRitorno>` è la dichiarazione del tipo del valore calcolato dalla funzione o `void` (_valore di ritorno_ / _output_)
{: .lesserspacebefore}

`<corpo>` è il blocco di codice che compone la funzione (_corpo_)
{: .lesserspacebefore}


---

## Le funzioni

_Esempio:_ funzione per la somma di due numeri interi

    !c
    ...
    // Prototipo
    int somma2num(int a, int b);
    
    // Definizione
    int somma2num(int a, int b) {
        int risultato= a+b;
        return risultato;
    }
    ...
    int main() {
        ...
        return 0;
    }


---

## Una funzione speciale

Il _"programma principale"_ è una funzione con un nome (`main`) e un prototipo predefinito (`int main();`).

Il valore di ritorno è _convenzionalmente_ `0` se non ho avuto errori, `>0` altrimenti.


---

## Variabili automatiche

I parametri e le variabili di una funzione sono visibili (_scope_) e vivono (_life_) solo all'interno del blocco che le ha definite.

_Esempio:_ il programma principale _non_ può usare la variabile `risultato`.

    !c
    ...
    int somma2num(int a, int b) {
        int risultato= a+b;
        return risultato;
    }
    ...
    int main() {
        ... // Qua NON posso usare la variabile 'risultato'
    }


---

## Chiamata di una funzione

    !c
    ...
    int somma2num(int a, int b) {
        int risultato= a+b;
        return risultato;
    }
    ...
    int main() {
        ...
        int x1= 0, x2= 0;
        ... // <-- Lettura di x1 e x2
        int somma= somma2num(x1, x2); // Chiamata/invocazione
        ...
    }

`somma2num(x1, x2)`: _invocazione_

`a` e `b`: parametri _formali_
{: .lesserspacebefore}

`x1` e `x2`: parametri _attuali_ (_actual_)
{: .lesserspacebefore}


---

## Chiamata di una funzione

    !c
    int somma2num(int a, int b) {
        int risultato= a+b;
        return risultato;
    }
    ...
    int main() {
        ...
        int somma= somma2num(x1, x2); // Chiamata/invocazione
        ...
    }

Cosa succede?

1. i parametri attuali vengono copiati nei corrispondenti parametri formali (_call-by-value_, **sempre**)
{: .quitesmaller}
2. l'esecuzione della procedura _chiamante_ viene "sospesa"
{: .quitesmaller}
3. viene eseguito il corpo della funzione _chiamata_
{: .quitesmaller}
4. quando si incontra l'istruzione `return` il valore viene "ritornato" alla funzione _chiamante_ che riprende l'esecuzione
{: .quitesmaller}


---

## Esercizio intermedio

Completare lo spezzone di codice della slide precedente per la somma di due numeri (quindi definendo e utilizzando la funzione `somma2num(...)`).


---

## Chiamate annidate

Una funzione può chiamare un'altra funzione.    

    !c
    ...
    int somma2num(int a, int b); // Solo il prototipo!
    
    int somma3num(int a, int b, int c); // Prototipo

    int somma3num(int a, int b, int c) { // Definizione
        return somma2num( somma2num(a, b),
                          c );
    }

    int somma4num(int a, int b, int c, int d); // Prototipo

    int somma4num(int a, int b, int c, int d) { // Definizione
        return somma2num( somma3num(a, b, c),
                          d );
    }
    ...


---

## Astrazione e incapsulamento (cenni)

Il prototipo specifica come la funzione _"comunica" con il resto del programma_.

La definizione specifica come la funzione _svolge il suo lavoro_.

Posso cambiare la definizione di una funzione per, ad esempio, renderla più efficiente.
Se non ne cambio il prototipo, non devo cambiare _nulla_ nel resto del programma (anche se è chiamata più volte).


---

## Modularizzazione (cenni)

Posso "spezzare" il programma in _moduli_ (=gruppi di funzioni).

I prototipi vanno in un _header file_ (estensione: `.h`), mentre le definizioni in un file di codice (estensione: `.c`).
{: .lesserspacebefore}

Nel file dove _chiamo_ le funzioni devo includere l'header che le ha dichiarate con: `#include "nomedelfile.h"`

È quello che facciamo con la libreria di sistema.
{: .lesserspacebefore}

Devo ricordarmi di compilare tutto assieme!
(in Windows: progetti, in SO evoluti: Makefiles (o simili))


---

## Modularizzazione (cenni)

    !c
    // File: somma.h
    #ifndef __SOMMA_H__ // Evita inclusioni multiple
    int somma2num(int a, int b);
    #endif
    
    // File: somma.c
    int somma2num(int a, int b) {
        return a+b;
    }
    
    // File: programma.c
    #include "somma.h"
    int main() {
        int x1= 0, x2= 0;
        int somma= somma2num(x1, x2);
    }

Compilo con:
`gcc -c -o somma.o somma.c`
`gcc -o programma programma.c somma.o`


---

## Ricorsione (cenni)

Definizione di **ricorsione**: vedi _ricorsione_.

    !c
    ...
    int somma_primi_n_numeri(int n) {
        if (n==0) {
            return 0;
        } else {
            return n + somma_primi_n_numeri(n-1);
        }
    }
    ...

_Ricorsione_ e _iterazione_ sono equivalenti!

A volte è più facile usarne una a volte l'altra.


---

## Ricorsione (cenni)

    !c
    
    void indovina_il_numero(int low, int high) {
        if (low+1 == high) {
            printf("Il numero e' %d\n", low);
        } else {
            int mid= (low + high)/2;
            printf("Come e' il numero %d rispetto a "
                   "quello che hai pensato?\n", mid);
            printf("(0 se uguale, -1 se minore, "
                   "1 se maggiore): ");
            int risp= 0;
            scanf("%d", &risp);  
            if (risp==0) {
                printf("Ho indovinato!\n");
            } else if (risp == -1) {
                indovina_il_numero(mid+1, high);
            } else {
                indovina_il_numero(low, mid);
            }
        }
    }



---

## Ricorsione (cenni)

L'efficienza della versione ricorsiva puo' essere pari alla versione iterativa.

In particolare se ho una _tail-recursion_:

    !c
    ...
    int somma_primi_n_numeri_tail(int n, int somma) {
        if (n==0) {
            return somma;
        } else {
            return somma_primi_n_numeri_tail(n-1, n + somma);
        }
    }
    ...


---

## Esercizio

Scrivere un programma che definisca (e utilizzi) una funzione `MCD(a, b)` per il calcolo del _massimo comun divisore_ tra due numeri \\(a\\) e \\(b\\).

Pensare prima all'algoritmo!
Serve un costrutto iterativo? Se sì, quale?

