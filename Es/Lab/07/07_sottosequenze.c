#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

//------------------------------------------------------------------
// Prototipi delle funzioni
//------------------------------------------------------------------

// Stampa la sottosequenza [left, right) degli elementi di a[]
void stampa_sseq(const size_t left, const size_t right, const int a[]);

// Altera l'intervallo [left, right) passato per puntatore come
// [*pLeft, *pRight) affinche' valgano le seguenti regole:
//  - gli elementi in [0. left) siano tutti zeri
//  - gli elementi in [right, aLen) siano tutti zeri
// Assumere che [*pLeft, *pRight) sia inizializzato come [0, aLen)
void escludi_zeri_estremi(size_t* pLeft, size_t* pRight, const int a[]);

// Incrementa di k tutti i valori nell'intervallo semiaperto [left, right)
void incrementa_sseq(const size_t left, const size_t right, 
                     int a[], const int k);

// Restituisce true se tutti i valori nell'intervallo semiaperto [left, right)
// sono pari e maggiori di val. Restituisce false altrimenti
bool test_sseq(const size_t left, const size_t right, 
               const int a[], const int val);

// Copia gli elementi dispari dall'intervallo semiaperto [left, right)
// di a[] in un'array b[] di capacita' bCap. Restituisce in *p_bLen
// il numero di elementi copiati.
void copia_dispari_sseq(const size_t left, const size_t right, const int a[], 
                        size_t* p_bLen, const size_t bCap, int b[]);

// Copia gli elementi dall'intervallo semiaperto [left, right) di a[]
// in un nuovo array b[] allocato dinamicamente su heap.
// La funzione restituisce il puntatore all'array b appena allocato
// di lunghezza *p_bLen.
// Se non ci sono elementi nell'intervallo, la funzione restituisce NULL
// e *p_bLen viene settato a 0.
// Nota: il chiamante e' responsabile di liberare la memoria
// allocata per l'array restituito.
int* copia_sseq(const size_t left, const size_t right, const int a[],
                size_t* p_bLen);    
                

// Copia fino a max_count elementi dall'intervallo semiaperto [0, right) di a[]
// che sono minori di valore_cercato in un nuovo array b[] 
// allocato dinamicamente su heap.
// La funzione restituisce il puntatore all'array b appena allocato
// di lunghezza *p_bLen.
// Se non ci sono elementi selezionati, la funzione restituisce NULL
// e *p_bLen viene settato a 0.
// Nota: il chiamante e' responsabile di liberare la memoria
// allocata per l'array restituito.               
int* copia_prefisso_minori_di(const size_t right, const int a[],
                              const int valore_cercato,
                              const size_t max_count,
                              size_t* p_bLen);                

//------------------------------------------------------------------

#define A1MAX 8
#define A2MAX 3
#define A3MAX 5
#define B1MAX 6
#define B2MAX 4

int main(void) {

    puts("------------- ESCLUDI ZERI ESTREMI -------------");
    int a1[A1MAX] = { 0, 0, 10, 15, 25, 0, 0, 0 };
    size_t left=0, right=A1MAX;
    escludi_zeri_estremi(&left, &right, a1);
    printf("[%zu, %zu):  ", left, right);
    stampa_sseq(left, right, a1);
    puts("[2, 5):  10 15 25    [atteso]\n");

    int a2[A2MAX] = { 4, 7, 8 };
    left=0;
    right=A2MAX;
    escludi_zeri_estremi(&left, &right, a2);
    printf("[%zu, %zu):  ", left, right);
    stampa_sseq(left, right, a2);
    puts("[0, 3):  4 7 8       [atteso]\n");

    int a3[A3MAX] = { 0 ,0 ,0 ,0 ,0 };
    left=0;
    right=A3MAX;
    escludi_zeri_estremi(&left, &right, a3);
    printf("[%zu, %zu):  ", left, right);
    stampa_sseq(left, right, a3);
    puts("[x, x):              [atteso]\n");
    // un intervallo semiaperto [x, x) è vuoto, per qualsiasi valore x

    puts("------------- INCREMENTA SOTTOSEQUENZA -------------");
    incrementa_sseq(0, A1MAX, a1, 5);
    incrementa_sseq(2, A1MAX-2, a1, 100);
    stampa_sseq(0, A1MAX, a1);
    puts("5 5 115 120 130 105 5 5    [atteso]\n");

    puts("------------- TEST SOTTOSEQUENZA -------------");
    printf("%d  [atteso 1]\n", test_sseq(3, A1MAX-3, a1, 110));
    printf("%d  [atteso 0]\n", test_sseq(1, A1MAX-1, a1, 10));
    printf("%d  [atteso 0]\n", test_sseq(2, A1MAX-2, a1, 200));


    puts("------------- COPIA DISPARI SOTTOSEQUENZA -------------");
    int b1[B1MAX], b2[B2MAX];
    size_t b1Len, b2Len;
    copia_dispari_sseq(1, A1MAX-1, a1, &b1Len, B1MAX, b1);
    stampa_sseq(0, b1Len, b1);
    puts("5 115 105 5         [atteso]\n");

    copia_dispari_sseq(0, A1MAX, a1, &b1Len, B1MAX, b1);
    stampa_sseq(0, b1Len, b1);
    puts("5 5 115 105 5 5     [atteso]\n");

    copia_dispari_sseq(0, A1MAX, a1, &b2Len, B2MAX, b2);
    stampa_sseq(0, b2Len, b1);
    puts("5 5 115 105         [atteso]\n");

    puts("------------- COPIA SOTTOSEQUENZA -------------");
    size_t b3Len = 0;
    int* b3 = copia_sseq(2, A1MAX-2, a1, &b3Len);
    if (b3 != NULL) {
        stampa_sseq(0, b3Len, b3);
        puts("115 120 130 105    [atteso]\n");
        free(b3);
        b3 = NULL;
    } 

    b3 = copia_sseq(4, 4, a1, &b3Len);
    if (b3 == NULL) {
        printf("Array vuoto, dimensione restituita: %zu\n", b3Len);
        puts("Array vuoto, dimensione restituita: 0    [atteso]\n");
    }

    b3 = copia_sseq(0, 1, a1, &b3Len);
    if (b3 != NULL) {
        stampa_sseq(0, b3Len, b3);
        puts("5    [atteso]\n");
        free(b3);
        b3 = NULL;
    }

    b3 = copia_sseq(0, A1MAX, a1, &b3Len);
    if (b3 != NULL) {
        stampa_sseq(0, b3Len, b3);
        puts("5 5 115 120 130 105 5 5     [atteso]\n");
        free(b3);
        b3 = NULL;
    }

    puts("------------- COPIA PREFISSO MINORI DI -------------");
    size_t b4Len = 0;
    int* b4 = copia_prefisso_minori_di(A1MAX, a1, 120, 3, &b4Len);
    if (b4 != NULL) {
        stampa_sseq(0, b4Len, b4);
        puts("5 5 115    [atteso]\n");
        free(b4);
        b4 = NULL;
    }

    b4 = copia_prefisso_minori_di(A1MAX-2, a1, 10, 5, &b4Len);
    if (b4 != NULL) {
        stampa_sseq(0, b4Len, b4);
        puts("5 5    [atteso]\n");
        free(b4);
        b4 = NULL;
    }

    b4 = copia_prefisso_minori_di(A1MAX, a1, 0, 4, &b4Len);
    if (b4 == NULL) {
        printf("Array vuoto, dimensione restituita: %zu\n", b4Len);
        puts("Array vuoto, dimensione restituita: 0    [atteso]\n");
    }

    b4 = copia_prefisso_minori_di(3, a1, 15, 5, &b4Len);
    if (b4 != NULL) {
        stampa_sseq(0, b4Len, b4);
        puts("5 5 [atteso]\n");
        free(b4);
        b4 = NULL;
    }

}

//------------------------------------------------------------------

void stampa_sseq(const size_t left, const size_t right, const int a[])
{
    // Completare
}

//------------------------------------------------------------------

void escludi_zeri_estremi(size_t* pLeft, size_t* pRight, const int a[])
{
    // Completare
}

//------------------------------------------------------------------

void incrementa_sseq(const size_t left, const size_t right, 
                     int a[], const int k)
{
    // Completare
}

//------------------------------------------------------------------

bool test_sseq(const size_t left, const size_t right, 
               const int a[], const int val)
{
    // Completare
}

//------------------------------------------------------------------

void copia_dispari_sseq(const size_t left, const size_t right, const int a[], 
                        size_t* p_bLen, const size_t bCap, int b[])
{
    // Completare
}

//------------------------------------------------------------------

int* copia_sseq(const size_t left, const size_t right, const int a[],
                size_t* p_bLen)
{
    // Completare
}

//------------------------------------------------------------------

int* copia_prefisso_minori_di(const size_t right, const int a[],
                              const int valore_cercato,
                              const size_t max_count,
                              size_t* p_bLen)
{
    // Completare
}