


# Le basi del linguaggio C



---

## Sintassi, semantica e errori

Linguaggi di programmazione hanno una:

* **Sintassi:** regole che determinano se un programma è _ben formato_ (valido)
* **Semantica:** regole che determinano il _significato_ di un programma _ben formato_

_Errori:_

* **di sintassi:** il programma non rispetta la sintassi (non è ben formato)
* **logici:** il programma è ben formato ma non fa quel che dovrebbe


---

## Errare è umano

Gli errori di sintassi li "trova" il compilatore, noi dobbiamo trovare e eliminare gli errori logici.

Però...

_Prevenire è meglio che curare_
{: .larger .center}


---

## "Anatomia" di un programma

    !c
    // Questo e' un commento
    /* Questo e' un commento multilinea.
       Cio' che e' scritto qui viene ignorato dal
       compilatore   */
    #include <stdio.h>   // libreria di sistema
   
    int main() { // Inizio corpo del programma
        /* Corpo del programma:
            - inizia sempre con int main()
            - e' racchiuso tra { e }   */
            
        printf("Hello world!\n");
        // Istruzione (termina sempre con ;)

        printf("Hello world 2!\n");
        // Altra istruzione

        return 0; // Esci dal programma
    } // Fine corpo del programma


---

## Istruzioni, sequenza e blocchi

**Istruzione:** singolo "comando" che verrà eseguito. Termina sempre con `;`

**Sequenza:** successione di istruzioni eseguite in sequenza

**Blocco:** sequenza (eventualmente vuota) di istruzioni compresa tra parentesi graffe `{` e `}`


---

## Variabili

**Variabile:** locazione di memoria identificata da un nome simbolico e contenente un valore.

**Identificatore:** sequenza che:

* contiene solo lettere, numeri o '_'
* non inizia con un numero
* non è una delle 44 "parole riservate" (es: `if`, `while`, ...)
  [lista completa](http://en.wikipedia.org/wiki/C_%28programming_language%29#Keywords)

_Ogni variabile deve avere un nome significativo!_
_Sono case-sensitive!_
{: .center}

---

## Tipo di una variabile

_C_ è un linguaggio _tipizzato_: ogni variabile ha un _tipo_

**Tipo** di una variabile: specifica dei _valori_ che la variabile può assumere e delle _operazioni_ che posso effettuare su di essa.

"Tipi" di tipi:

* tipi primitivi
* tipi non primitivi (composti)


---

## Tipi primitivi

Tipi primitivi:

* numerici interi: `int`, `long`, ...
* numerici decimali: `float`, `double`, ...
* carattere (ASCII): `char`, ...
* boolean (Vero/Falso): `_Bool`/`bool`, introdotto in C99
  (lo "shorthand" `bool` richiede l'header `<stdbool.h>`)
{: .highline}


---

## Limiti dei tipi primitivi

L'insieme dei valori che può assumere un tipo primitivo *è dipendente dal compilatore*, con alcuni vincoli:

* `int`: almeno 16 bit, range= \\([-2^{15}, 2^{15}-1]\\)
* `long`: almeno 32 bit, range= \\([-2^{31}, 2^{31}-1]\\)
* `double`: numero in virgola mobile in doppia precisione

Tipi "speciali" (architecture dependent, header `<stddef.h>`):

* `size_t`: dimensione di un array
* `ptrdiff_t`: differenza tra puntatori


---

## Costanti letterali

**Costanti letterali:** valori costanti (hanno un tipo implicito!)

_Esempi:_

    !c
    0      181002   // int
    0x01A  0123     // int esadecimale e ottale (risp.)
    0.5    123.4    // float
    'y'    '\0'     // char
    true   false    // _Bool/bool richiede stdbool.h

**Attenzione!**
`0` è diverso da `0.0` &nbsp;&nbsp;&nbsp; `1` è diverso da `1.0` ...
{: .center}


---

## Dichiarazione di una variabile

Dichiarazione e inizializzazione di una variabile:
    
    !c
    <tipo> <identificatore>= <valore iniziale> (, <id>= <val>...);
    
_Semantica:_

* crea una variabile con nome `<identificatore>` e tipo `<tipo>`
{: .highline}
* inizializza la variabile al valore `<valore iniziale>`.

Una variabile _va sempre inizializzata!_
(anche se non richiesto)
{: .center}

---

## Dichiarazione di una variabile

_Esempi:_

    !c
    int a= 123, b1= -123;
    int b2= a;
    char c1= 'y', c2= ' ';
    double pi= 3.1415926535;
    double d= 125.000;
    bool b_vero= true, b_falso= false;


---

## Assegnamento

**Assegnamento:** concetto alla base del paradigma imperativo (insieme alla sequenza).

    !c
    <l-value>= <r-value>;        // Definizione generale
    <variabile>= <espressione>;  // Definizione "pragmatica"

_Semantica:_
L'espressione `<espressione>` viene valutata e il risultato viene assegnato (memorizzato) alla locazione di memoria identificata dalla variabile `<variabile>`


---

## Assegnamento

_Esempi:_

    !c
    int a= 10, b= 5;
    a= a + 5;
    a= (a + a) / a;
    a= (a + a) / (a + a - a) * (b + 1);
    
    double d= 5.0;
    d= (d + 3.0) / 2;
    d= d + 3.0 / 2;
    
    double e= 1;  // OK. Promozione di tipo.


---

## Espressioni

Operatori _aritmetici_:

* operatore unario: `-` (cambio di segno)
* operatori binari: `+`, `-`, `*`, `/`, `%` (modulo o resto)
* precedenza (quasi) come alle elementari


---

## Il caso della divisione

_Attenzione:_ l'operatore di divisione `/` rappresenta 

* la divisione intera se _tutti_ i suoi operandi sono interi
* la divisione decimale se _almeno_ un operando è decimale

_Esempi:_

    !c
    3 / 2
    3.0 / 2
    3 / 2.0
    3 / ( 5 / 2 )


---

## Il caso della divisione

_Attenzione:_ l'operatore di divisione `/` rappresenta 

* la divisione intera se _tutti_ i suoi operandi sono interi
* la divisione decimale se _almeno_ un operando è decimale

_Esempi:_

    !c
    3 / 2           // 1
    3.0 / 2         // 1.5
    3 / 2.0         // 1.5
    3 / ( 5 / 2 )   // -> 3 / 2 -> 1


---

## Altri operatori

Operatori _logici_:

* `!` (not, unario), `&&` (and), `||` (or)
* _Attenzione:_ `&&` e `||` sono di corto circuito

Operatori _relazionali_:

* `<`, `<=`, `>`, `>=`, `==`, `!=`
* _Attenzione:_ l'uguaglianza è "`==`" **non** "`=`"

Operatori _bitwise_:

* `~` (not, unario), `&` (and), `|` (or), `^` (xor),
  `<<` (left shift), `>>` (right shift)


---

## Espressioni "composte"

_C_ non mette limiti a come comporre operatori di tipo diverso ma non tutte le espressioni hanno senso logico!

    !c
    int a= 0, b= 10, c= 20;
    bool c1= (a >= b);
    bool c2= (a + 10) >= b;
    bool c3= (a <= b) && (b <= c);
    int d= (a <= b) * b | a + 1;   // ???


---

## Operatori di incremento/decremento

Operatori di incremento/decremento: `++`, `--`

Se usati come _prefisso_: incrementano/decrementano di uno la variabile e ritornano il valore _risultante_

    !c
    int a= 0;
    int b= ++a; // a e b valgono 1

Se usati come _suffisso_: incrementano/decrementano di uno la variabile e ritornano il valore _originale_

    !c
    int a= 0;
    int b= a++; // a vale 1 e b vale 0


---

## Operatori composti

Per molti operatori esiste l'operatore di _assegnamento composto_ (`+=`, `-=`, `*=`, ...)

_Esempio:_

    !c
    
    int c= 0;
    
    c += 1;     // equivalente a:  c= c + 1;


---

## La libreria standard

**Libreria standard:** collezione di funzionalità rese disponibili dal linguaggio in tutte le sue implementazioni.

In _C_ è "scomposta" in diversi file (_header files_) "monotematici".

Per accedere alla libreria dobbiamo "includere" ciascun file che ci serve con la direttiva (prima di tutto il programma):
{: .lessspacebefore}

    !c
    #include <nomedelfile>

Documentazione estensiva è disponibile online [qui](http://en.wikipedia.org/wiki/C_Standard_Library) e [qui](http://www.cplusplus.com/reference/clibrary/)


---

## Stampare su schermo

Per "comunicare con l'esterno" il file da includere è: `stdio.h`

Per stampare a schermo:

    !c
    printf(<stringa di formato>, <expr1>, <expr2>, ...);

dove la stringa di formato è una sequenza di caratteri delimitati da doppi apici (`"`) e contenente appositi "segnaposti":

* `%d`, per espressioni numeriche _intere_
* `%lf`, per espressioni numeriche _decimali_ `double`
* `%c`, per espressioni "singolo carattere"

[Documentazione completa `printf`](http://www.cplusplus.com/reference/cstdio/printf/)
{: .note .smaller}


---

## Stampare su schermo

_Esempi:_
{: .lesserspaceafter}

    !c
    #include <stdio.h>
    
    ...
    
    int v1= 29, v2= 30;
    double media= (v1 + v2) / 2.0;
        // usiamo 2.0 perché vogliamo una divisione decimale

    printf("La media tra %d e %d è %lf\n", v1, v2, media);
    // Stampa: ('\n' è il carattere per mandare a capo)
    // La media tra 29 e 30 è 29.500000
    
    // Equivalente:
    printf("La media tra %d e %d è %lf\n", v1, v2, (v1+v2)/2.0);


---

## Leggere da terminale

Leggere da terminale (tastiera):

    !c
    scanf(<stringa di formato>, &<var1>, &<var2>, ...);

Note:

* Attenzione all'operatore `&`
* La stringa di formato segue le regole di prima
* Caratteri non segnaposto devono essere presenti nell'input
* Non visualizza alcun messaggio

[Documentazione completa `scanf`](http://www.cplusplus.com/reference/cstdio/scanf/)
{: .note .smaller}


---

## Leggere da terminale

_Esempi:_
{: .lessspaceafter}

    !c
    #include <stdio.h>
    ...
    int v1= 0, v2= 0;
    double c= 0.0;
    scanf("%d %d %lf", &v1, &v2, &c);
      // Legge due numeri interi e uno decimale
      // separati da spazi/tab/a capo
    scanf("N1:%d N2:%d N3:%lf", &v1, &v2, &c);
      // Legge (e scarta) "N1:"
      // poi un numero intero
      // poi uno o più spazi/tab/a capo
      // poi legge (e scarta) "N2:"
      // poi un numero intero
      // poi uno o più spazi/tab/a capo
      // poi legge (e scarta) "N3:"
      // poi un numero decimale


---

## Il primo programma completo


    !c
    // Somma di due numeri
    // Input: due numeri interi (da terminale)
    // Output: la loro somma (su schermo)
    #include <stdio.h>
    int main() {
        int a= 0, b= 0; // Dichiarazione delle variabili in input
        int somma= 0;   // Dichiarazione della variabile in output
        // Lettura dell'input
        printf("Inserisci il primo numero: ");
        scanf("%d", &a);
        printf("Inserisci il secondo numero: ");
        scanf("%d", &b);
        // Calcolo della somma
        somma= a+b;
        // Visualizzazione dell'output
        printf("La somma di %d e %d e': %d\n", a, b, somma);
        // Esci
        return 0;
    }


---

## Provare il programma

Proviamolo:

* Copiare l'ambiente di sviluppo (cartella `Dev-Cpp`)
* `devcppPortable.exe` > `File` > `New` > `Source file`
* Scrivere il programma
* Salvare: `File` > `Save as..` > `somma2num.c`
* Compilare e eseguire: `Execute` > `Compile&Execute`
* Provare con diversi input: funziona anche con numeri negativi? e se premo `invio` prima di scrivere un numero? e se inserisco un numero decimale?
* Creare un nuovo programma `somma3num.c` per sommare 3 numeri


---

## L'operatore di casting

È possibile forzare il compilatore a considerare una variabile come se avesse un altro tipo.
{: .medline}


    !c
    double d= 47.9;
    int i= (int)d;
    // Funziona anche senza, meglio metterlo, i vale 47

    int a= 5, b= 2;
    double r= (double)a/(double)b; // r vale 2.5

La conversione di tipo (implicita o esplicita) si dovrebbe usare abbastanza raramente, i risultati possono essere sorprendenti.
{: .medline}

    !c
    int i=    16777217;
    printf("%f\n", (float)i);
    // Stampa 16777216.000000


---

## La virgola mobile e l'uguaglianza

La rappresentazione in virgola mobile non è esatta:

* `0.1` **non** è rappresentabile esattamente in un `double`
* il confronto `==` e `!=` di numeri in virgola mobile non dovrebbe **mai** avvenire

Piuttosto confrontare la differenza dei valori assoluti rispetto a un \\( \varepsilon \\) (piccolo) pre-fissato:

    !c
    #include <math.h>
    ...
    double a = 0.0;
    if (fabs(a - 0.0)<= 0.00001) {
    ...    


---

## Tipi primitivi (più in dettaglio)

Elenco più dettagliato dei tipi primitivi:

    !c
    (signed|unsigned| ) char              // almeno 8 bit
    (signed|unsigned| ) short (int)?      // almeno 16 bit
    (signed|unsigned| ) int               // almeno 16 bit
    (signed|unsigned| ) long (int)?       // almeno 32 bit
    (signed|unsigned| ) long long (int)?  // almeno 64 bit (C99)

    float         // single precision
    double        // double precision
    long double   // extended or quadruple precision

Gli header `limits.h` e `float.h` forniscono costanti per determinare i limiti dei valori rappresentabili (es: `INT_MIN`, `INT_MAX`, `UINT_MAX`, ...)

Documentazione [`limits.h`](http://www.cplusplus.com/reference/climits/) e [`float.h`](http://www.cplusplus.com/reference/cfloat/)
{: .note .smaller}


---

## Esercizio (più avanzato)

Aiutandosi con la documentazione on-line, scrivere un programma che stampa a schermo una variabile `double` contenente il valore `0.3` con 20 cifre di precisione.
{: .medline}

Aiutandosi con la documentazione on-line, scrivere un programma che visualizza il numero più grande e più piccolo memorizzabile in una variabile `int` e il numero più grande e più piccolo (in valore assoluto) memorizzabile in una variabile `double`.
{: .medline}

Usare, rispettivamente, `long` e `long double` espande il range dei numeri memorizzabili?
{: .medline}

