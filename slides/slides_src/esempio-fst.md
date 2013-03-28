


# Un caso (semi) reale



---

## Calcolo dell'\\(F_{ST}\\)

**Fixation index \\(F_{ST}\\):** measure of population differentiation due
to genetic structure.

Fonte: [Wikipedia](http://en.wikipedia.org/wiki/Fixation_index) [Lectures](http://www.uwyo.edu/dbmcd/popecol/maylects/fst.html)
{: .smaller .note}

$$ F_{ST} = \frac{H_T - H_S}{H_T} $$

\\( H_S = \\) media ponderata delle eterozigosità attese delle singole popolazioni

\\( H_T = \\) eterozigosità attesa in tutta la popolazione


---

## Eterozigosità attesa

Sotto l'ipotesi di HWE (per loci biallelici):

$$ H_{exp} = 2pq $$

dove \\(p\\) e \\(q\\) sono le frequenze (relative) dei due alleli.

Può essere calcolata su tutta la popolazione se le due frequenze si riferiscono alla popolazione intera, o su una sottopopolazione se le frequenze si riferiscono alla sottopopolazione.


---

## Calcoliamo l'\\(F_{ST}\\)


**Problema:** a partire da un file che specifica su ogni linea una coppia `p g`, dove `p` è l'identificativo della popolazione e `g` è il genotipo di un individuo per un locus predeterminato (e unico per tutto il file) codificato con `0` omozigote per l'allele maggiore, `1` eterozigote e `2` omozigote per l'allele minore, calcolare l'\\(F_{ST}\\) per quel gruppo di popolazioni (e quel locus).


---

## Calcoliamo l'\\(F_{ST}\\)

Come fare?

1. Calcolo delle frequenze alleliche \\(p\\) e \\(q\\) per ciascuna sottopopolazione e per la popolazione complessiva.
{: .highline}
2. Calcolo delle eterozigosità attese
3. Calcolo dell'\\( F_{ST} \\)

Una possibile implementazione è disponibile [qui](https://raw.github.com/yp/ProgrC-PTP-2013/master/examples/7-fst.c).
