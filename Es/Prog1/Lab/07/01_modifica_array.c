#include <stdio.h>
#include <stdbool.h>

//------------------------------------------------------------------
// Prototipi delle funzioni
//------------------------------------------------------------------

// stampa gli aLen elementi dell'array a[]
void stampa_array(const size_t aLen, const int a[]);

// Copia nell'array b[] (con capacita' bCap) tutti gli
// elementi di a[] (array di lunghezza aLen) che sono non-negativi
// (ciòe' sono maggiori o uguali a 0).
// Alla fine il valore puntato da *p_bLen viene aggiornato con
// il numero di elementi copiati in b[]. 
void copia_nonnegativi(const size_t aLen, const int a[], 
                       size_t* p_bLen, const size_t bCap, int b[]);

// Rimuovi in-place dall'array a[] (di dimensione *p_aLen) tutti
// gli elementi che non sono maggiori del valore passato come argomento.
// (quindi mantieni sono gli elementi "maggiori_di")
// Alla fine il valore puntato da *p_aLen viene aggiornato con
// il numero di elementi rimasti in a[]. 
void filtra_maggiori_di(size_t* p_aLen, int a[], const int maggiori_di);

// Copia tutti gli elementi da a[] (dimensione: aLen) nel buffer
// b (con capacita' bCap), copiando due volte di seguito
// gli elementi che sono pari
// Alla fine il valore puntato da *p_bLen viene aggiornato con
// il numero di elementi copiati in b[]. 
void duplica_pari(const size_t aLen, const int a[], 
                  size_t* p_bLen, const size_t bCap, int b[]);

// Restituisce true se i due array a[] e b[] sono uguali, cioè se
// hanno la stessa lunghezza e se tutti gli elementi 
// di a[] (dimensione aLen) sono uguali ai corrispondenti elementi 
// di b[] (dimensione bLen). Restituisce false altrimenti.
bool array_equal(const size_t aLen, const int a[],
                 const size_t bLen, const int b[]);

//------------------------------------------------------------------

#define NBUF_A  10
#define NBUF_B  3
#define NBUF_C  20

int main(void) {
    int a1[NBUF_A] = { -73, 10, 77, -10, -41, 0, -58, 41, 78, 97 };
    size_t a1Len = NBUF_A;

    puts("Stampa di a1[]:");
    stampa_array(a1Len, a1);

    // copia gli elementi nonnegativi
    int a2[NBUF_A];
    size_t a2Len = 0;
    copia_nonnegativi(a1Len, a1, &a2Len, NBUF_A, a2);
    puts("\nCopia non-negativi:");
    stampa_array(a2Len, a2);
    puts("10 77 0 41 78 97    [atteso]\n");

    // copia gli elementi nonnegativi in un buffer più piccolo
    int a3[NBUF_B];
    size_t a3Len = 0;
    copia_nonnegativi(a1Len, a1, &a3Len, NBUF_B, a3);
    puts("Copia non-negativi (con buffer di capacita\' insufficiente):");
    stampa_array(a3Len, a3);
    puts("10 77 0             [atteso]\n");

    // filtra gli elementi maggiori di 10
    filtra_maggiori_di(&a1Len, a1, 10);
    puts("Filtra da a1 elementi maggori di 10:");
    stampa_array(a1Len, a1);
    puts("77 41 78 97         [atteso]\n");

    int a4[NBUF_A] = { 63, 99, 56, 98, 59, 51, 57, 12, 10, 85 };
    const size_t a4Len = NBUF_A;

    puts("\nStampa di a4[]:");
    stampa_array(a4Len, a4);
    puts("");

    // duplica gli elementi pari di a4
    int a5[NBUF_C];
    size_t a5Len = 0;
    duplica_pari(a4Len, a4, &a5Len, NBUF_C, a5);
    puts("Duplicazione pari:");
    stampa_array(a5Len, a5);
    puts("63 99 56 56 98 98 59 51 57 12 12 10 10 85    [atteso]\n");

    // duplica gli elementi pari di a4 in un buffer di capacita' insufficiente
    int a6[NBUF_A];
    size_t a6Len = 0;
    duplica_pari(a4Len, a4, &a6Len, NBUF_A, a6);
    puts("Duplicazione pari (con buffer di capacita\' insufficiente):");
    stampa_array(a6Len, a6);
    puts("63 99 56 56 98 98 59 51 57 12                [atteso]\n");


#   define LENRISP1  4
    int risp1[LENRISP1] = { 77, 41, 78, 97 };
    puts("Confronti tra array:");
    printf("%d  [atteso: 1]\n", array_equal(a1Len, a1, LENRISP1, risp1));
    printf("%d  [atteso: 0]\n", array_equal(a1Len, a1, a2Len, a2));
    int a7[LENRISP1] = { 77, 41, 0, 97 };
    printf("%d  [atteso: 0]\n", array_equal(a1Len, a1, LENRISP1, a7));
}

//------------------------------------------------------------------

void stampa_array(const size_t aLen, const int a[])
{
    // COMPLETARE
    for(size_t i = 0; i < aLen; i++){
        printf("%d ", a[i]);
    }
    puts("");
}

//------------------------------------------------------------------

void copia_nonnegativi(const size_t aLen, const int a[], 
                       size_t* p_bLen, const size_t bCap, int b[])
{
    // COMPLETARE
    for(size_t i = 0; i < aLen && *p_bLen < bCap;i++){
        if(a[i] >= 0){
            b[*p_bLen] = a[i];
            (*p_bLen)++;
        }
    }
}

//------------------------------------------------------------------

void filtra_maggiori_di(size_t* p_aLen, int a[], const int maggiori_di)
{
    // COMPLETARE
    size_t j = 0;
    for(size_t i = 0; i < *p_aLen; i++){
        if(a[i] > maggiori_di){
            a[j] = a[i];
            j++;
        }
    }
    *p_aLen = j;
}

//------------------------------------------------------------------

void duplica_pari(const size_t aLen, const int a[], 
                  size_t* p_bLen, const size_t bCap, int b[])
{
    // COMPLETARE
    for(size_t i = 0; i < aLen && *p_bLen < bCap;i++){
        b[*p_bLen] = a[i];
        (*p_bLen)++;
        if(a[i] % 2 == 0 && *p_bLen < bCap){
            b[*p_bLen] = a[i];
            (*p_bLen)++;
        }
    }
}

//------------------------------------------------------------------

bool array_equal(const size_t aLen, const int a[],
                 const size_t bLen, const int b[])
{
    // COMPLETARE
    bool ret = true;
    if(aLen != bLen){
        ret = false;
    }else{
        for(size_t i = 0; i < aLen; i++){
            if(a[i] != b[i]){
                ret = false;
            }
        }
    }
    return ret;
}

//------------------------------------------------------------------
