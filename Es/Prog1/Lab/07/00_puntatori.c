#include <stdio.h>

int main (){
    size_t index = 2;
    size_t* p = &index;

    // stampa i valori di index e p
    printf("Il valore di index è %zu e p è %p\n", index, p);

    // vogliamo incrementare il valore di index accedendo ad esso tramite il puntatore p
    // possiamo farlo dereferenziando il puntatore e incrementando il valore
    // ma, se scriviamo quanto segue, incrementiamo il valore del puntatore
    // questo accade poiché l'operatore di incremento ++ ha una priorità maggiore 
    // dell'operatore di dereferenziazione *
    // il compilatore darà un warning di "expression result unused".
    // ciò può essere interpretato come un campanello di allarme che indica che il codice potrebbe non fare ciò che ci si aspetta.
    *p++;
    printf("Il valore puntato da p è %zu e il suo indirizzo di memoria è %p\n", *p, p);

    // inizializziamo di nuovo il puntatore
    p = &index;

    // il modo corretto per farlo è aggiungere le parentesi
    // in modo che prima applichiamo l'operatore di dereferenziazione e 
    // poi incrementiamo il valore a cui punta
    (*p)++;
    printf("Il valore puntato da p è %zu e il suo indirizzo di memoria è %p\n", *p, p);

    // possiamo anche incrementare nel seguente modo il valore puntato
    *p += 1;
    printf("Il valore puntato da p è %zu e il suo indirizzo di memoria è %p\n", *p, p);

    // se scriviamo quanto segue, incrementiamo il valore del puntatore
    // il compilatore darà un warning di "expression result unused".
    // ciò può essere interpretato come un campanello di allarme che indica che il codice potrebbe non fare ciò che ci si aspetta.
    *(p++);
    printf("Il valore puntato da p è %zu e il suo indirizzo di memoria è %p\n", *p, p);
}