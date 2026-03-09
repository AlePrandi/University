#include <stdio.h>

/**
 * @brief Converte una stringa in intero (data la base).
 *
 * Calcola il numero intero rappresentato dalla stringa `s` nella base `b` (tra 2 e 36):
 * − saltando gli eventuali spazi bianchi iniziali;
 * − riconoscendo l'eventuale (singolo) carattere del segno (+ o -);
 * − fermandosi al raggiungimento del primo carattere non cifra nella base data
 *   (le cifre per la base 36 sono 0,..,9,A,..,Z, invece a-z non sono cifre valide);
 * - deve essere presente almeno una cifra nella base data.
 *
 * Restituisce:
 * - 0 se uno degli argomenti non è valido, e in tal caso il valore in salvato in `r` non è significativo;
 * - altrimenti, il numero di caratteri letti dalla stringa (inclusi spazi e segni), salvando in `r` il risultato.
 * 
 * Notare che la conversione della stringa c_n ... c_2 c_1 c_0 in base b è il numero:
 * c_n * b^n + ... * c_2 * b^2 + c_1 * b + c_0.
 *
 * La funzione non si accorge di eventuali overflow numerici (restituendo in questo caso un risultato scorretto).
 *
 * @param s una stringa da convertire.
 * @param b la base (tra 2 e 36).
 * @param r l'indirizzo dell'intero dove memorizzare il risultato.
 * @return  il numero di caratteri letti dalla stringa
 *
 * NOTA: questa funzione compare negli errori di compilazione come "student_stoib"
 * NOTA: questa funzione viene testata indipendentemente dal vostro main
 * IMPORTANTE: cercate sempre di far compilare il vostro codice per poter vedere il
 * risultato dei test, anche a costo di commentare parte del codice di questa funzione
 */
int stoib(char *s, unsigned short b, int *r);