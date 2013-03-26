


# I costrutti di selezione e iterazione



---

## Il costrutto di selezione

Costrutto di **selezione**: esecuzione condizionale di un blocco.

    !c
    if (<condizione>)
        <blocco ALLORA>
    [ else
        <blocco ALTRIMENTI>
    ]

_Semantica:_ se l'espressione `<condizione>` viene valutata `true`, allora viene eseguito il blocco `<blocco ALLORA>` altrimenti viene eseguito il blocco `<blocco ALTRIMENTI>`.

L'`else` (la parte tra parentesi quadre) è opzionale.


---

## Il costrutto di selezione

_Esempio:_

    !c
    int a= 0, b= 5;

    if (a >= b) {
        printf("a e' maggiore o uguale a b\n");
    } else {
        printf("a e' minore di b\n");
    }


---

## `if` "in cascata"

_Esempio:_

    !c
    int a= 0, b= 5;

    if (a > b) {
        printf("a e' maggiore di b\n");
    } else if (a == b) {
        printf("a e' uguale a b\n");
    } else {
        printf("a e' minore di b\n");
    }


---

## Esercizio

Trovare (se possibile) la soluzione di un'equazione di primo grado \\(ax + b = 0\\) dati i suoi coefficienti \\(a, b\\) o stampare un messaggio di errore se non è una equazione di primo grado valida (cioè se \\( a = 0 \\)).

Attenzione:

1. Pensate all'algoritmo prima!
2. Provate l'implementazione su esempi significativi!


---

## Il costrutto iterativo `while`

Costrutto **iterativo**: ripetizione di un blocco regolato da una condizione

    !c
    
    while (<condizione>)
        <blocco CICLO>

_Semantica:_

1. viene valutata l'espressione `<condizione>`
2. se `true` viene eseguito il blocco `<blocco CICLO>` e si torna al punto 1
3. se `false` si prosegue con la prima istruzione dopo `<blocco CICLO>`


---

## Il costrutto iterativo `while`

_Esempio:_

    !c
    int i= 0;
    while (i<=4) {
        printf("Ho ripetuto il ciclo %d volte.\n", i);
        i= i+1;  // potevo usare i++  o  ++i  o  i+= 1
    }
    printf("Ho finito di ripetere il ciclo e 'i' vale %d.\n", i);

_Output:_

    Ho ripetuto il ciclo 0 volte.
    Ho ripetuto il ciclo 1 volte.
    Ho ripetuto il ciclo 2 volte.
    Ho ripetuto il ciclo 3 volte.
    Ho ripetuto il ciclo 4 volte.
    Ho finito di ripetere il ciclo e 'i' vale 5.


---

## Il costrutto iterativo `do ... while`

Come `while` ma con controllo in coda

    !c
    
    do
        <blocco CICLO>
    while (<condizione>)

_Semantica:_

1. viene eseguito il blocco `<blocco CICLO>`
2. viene valutata l'espressione `<condizione>`
3. se `true` si torna al punto 1
4. se `false` si prosegue con l'istruzione successiva


---

## Il costrutto iterativo `do ... while`

I cicli `while` e `do...while` sono equivalenti ma:

* `while` ha il controllo in testa e il corpo del ciclo _potrebbe non venire mai eseguito_
{: .highline}
* `do...while` ho il controllo in coda e il corpo del ciclo _viene eseguito sempre almeno una volta_

A seconda dei casi è più appropriato l'uno o l'altro.


---

## Esercizi

Scrivere un programma che sommi i primi \\(n\\) numeri naturali (con \\(n\\) letto da terminale).

Scrivere un programma che sommi \\(n\\) numeri interi letti da terminale (con \\(n\\) letto da terminale prima della sequenza di numeri).

Scrivere un programma che sommi una sequenza di numeri interi letti da terminale e terminante con il numero `0`.

Quali costrutti iterativi è meglio usare? Perché?


---

## Il costrutto iterativo `for`

È solo "syntactic-sugar"

    !c
    for (<init>; <cond>; <final>)
        <blocco CICLO>

Equivalente a:

    !c
    <init>;
    while (<cond>) {
        <blocco CICLO>
        <final>
    }

con `<init>`, `<cond>`, e `<final>` espressioni
e con `<blocco CICLO>` blocco di istruzioni


---

## Il costrutto iterativo `for`

_Esempio:_

    !c
    int i= 0;
    for (i= 0; i<=4; i= i+1) {
        printf("Ho ripetuto il ciclo %d volte.\n");
    }
    printf("Ho finito di ripetere il ciclo e 'i' vale %d.\n", i);

_Output:_

    Ho ripetuto il ciclo 0 volte.
    Ho ripetuto il ciclo 1 volte.
    Ho ripetuto il ciclo 2 volte.
    Ho ripetuto il ciclo 3 volte.
    Ho ripetuto il ciclo 4 volte.
    Ho finito di ripetere il ciclo e 'i' vale 5.


---

## Il costrutto iterativo `for`

La dichiarazione di una variabile in `<init>` è permessa a partire da C99 ma **non** può essere usata "fuori" dal ciclo.
(lo scope di variabili lo affronteremo poi)

    !c
    for (int i= 0; i<=4; i= i+1) {
        printf("Ho ripetuto il ciclo %d volte.\n");
    }
    // L'istruzione seguente genera un errore di compilazione !!
    printf("Ho finito di ripetere il ciclo e 'i' vale %d.\n", i);

In Orwell Dev-C++, si imposta lo standard con:
`Tools` > `Compiler options` > `Settings` >
&nbsp;&nbsp;&nbsp;&nbsp; > `Code generation` > `Language standard`


---

## Il costrutto iterativo `for`

Cicli `while`, `do..while` e `for` sono equivalenti ma:

* cicli `while`/`do..while` si usano quando non si conosce a priori il numero delle iterazioni
{: .highline}
* ciclo `for` si usa quando si conosce a priori il numero delle iterazioni (è lo "scorrimento")
{: .highline}

_Domanda:_ in quale degli esercizi precedenti sulla somma di una sequenza di numeri era "appropriato" un ciclo `for`?


---

## Esercizi di riepilogo

Scrivere un programma che determini il minimo di una sequenza di \\(n\\) numeri interi letti da terminale (con \\(n\\) letto da terminale prima della sequenza di numeri).
(Hint: posso accettare \\(n=0\\)?)
{: .medline}

Scrivere un programma che determini il minimo **e** il massimo di una sequenza di numeri interi che termina con il valore `0` (il valore "tappo" **non** fa parte della sequenza).
(Attenzione: cosa succede se il primo valore è `0`?)
{: .medline}

Scrivere un programma che determini se una sequenza di numeri interi che termina con il valore `0` è ordinata _in senso crescente_.
{: .medline}
