#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>
#include <assert.h>


//------------------------------------------------------------------
// Prototipi delle funzioni
//------------------------------------------------------------------

// stampa gli aLen elementi dell'array a[]
void stampa_array(const size_t aLen, const int a[]);

// Copia nell'array b[], allocato dinamicamente su heap, 
// tutti gli elementi di a[] (array di lunghezza aLen) che sono non-negativi
// (ciòe' sono maggiori o uguali a 0).
// La funzione restituisce il puntatore all'array b appena allocato
// di lunghezza *p_bLen. 
// Se non ci sono elementi selezionati, la funzione restituisce NULL
// e *p_bLen viene settato a 0.
// Nota: il chiamante e' responsabile di liberare la memoria
// allocata per l'array restituito.
int* copia_nonnegativi(size_t aLen, const int a[], 
                       size_t* p_bLen);


// Trasforma gli elementi di a[] (array di lunghezza aLen)
// nel loro quadrato, e restituisce un nuovo array
// allocato dinamicamente su heap, contenente questi valori.
// La funzione restituisce il puntatore all'array b appena allocato
// di lunghezza *p_bLen (uguale ad aLen).
// Nota: il chiamante e' responsabile di liberare la memoria
// allocata per l'array restituito.                       
int* trasforma_in_quadrati(const size_t aLen, const int a[], 
                           size_t* p_bLen);     
                       

// Inserisce nell'array b[] (allocato dinamicamente su heap)
// gli indici degli elementi di a[] (array di lunghezza aLen)
// che sono maggiori del valore_cercato.
// La funzione restituisce il puntatore all'array b appena allocato
// di lunghezza *p_bLen.
// Nota: il chiamante e' responsabile di liberare la memoria
// allocata per l'array restituito.                       
int* trova_indici_maggiori_di(const size_t aLen, const int a[],
                              const int valore_cercato,
                              size_t* p_bLen);  
                              

// Copia nell'array b[] (allocato dinamicamente su heap)
// gli elementi di a[] (array di lunghezza aLen),
// eliminando gli elementi duplicati se adiacenti.   
// La funzione restituisce il puntatore all'array b appena allocato
// di lunghezza *p_bLen.
// Nota: il chiamante e' responsabile di liberare la memoria
// allocata per l'array restituito.                           
int* copia_univoci_se_adiacenti(const size_t aLen, const int a[],
                              size_t* p_bLen);                              

//------------------------------------------------------------------

#define A_CAP  10

int main(void){

    puts("-------------");
    int a1[A_CAP] = { -73, 10, 77, -10, -41, 0, -58, 41, 78, 97 };
    size_t aLen = A_CAP;

    puts("Stampa di a1[]:");
    stampa_array(aLen, a1);

    // copia gli elementi non negativi
    size_t bLen = 0;
    int* b = copia_nonnegativi(aLen, a1, &bLen);
    puts("\nCopia non-negativi:");
    if (b != NULL) {
        stampa_array(bLen, b);
        puts("10 77 0 41 78 97    [atteso]\n");
        printf("La dimensione dell'array copiato e': %zu\n", bLen);
        puts("La dimensione dell'array copiato e': 6    [atteso]\n");
        free(b);
        b = NULL;
    }

    bLen = 0;
    b = copia_nonnegativi(0, a1, &bLen);

    if (b != NULL) {
        // non dovrebbe entrare qui
        stampa_array(bLen, b);
        free(b);
        b = NULL;
    } else {
        printf("Array vuoto, dimensione restituita: %zu\n", bLen);
        puts("Array vuoto, dimensione restituita: 0    [atteso]");
    }
    puts("-------------\n");

    puts("-------------");
    size_t a2Len = 5;
    int a2[] = { 3, -4, 5, -6, 7 };

    puts("Stampa di a2[]:");
    stampa_array(a2Len, a2);

    // trasforma in quadrati
    bLen = 0;
    b = trasforma_in_quadrati(a2Len, a2, &bLen);
    puts("\nTrasforma in quadrati:");
    if (b != NULL) {
        stampa_array(bLen, b);
        puts("9 16 25 36 49    [atteso]\n");
        printf("La dimensione dell'array trasformato e': %zu\n", bLen);
        puts("La dimensione dell'array trasformato e': 5    [atteso]\n");
        free(b);
        b = NULL;   
    }
    puts("-------------\n");

    puts("-------------");
    int a3[A_CAP] = { 12, 5, 8, 20, 3, 7, 15, 1, 30, 4 };
    size_t a3Len = A_CAP;
    puts("Stampa di a3[]:");
    stampa_array(a3Len, a3);

    // trova indici maggiori di 9
    const int valore_cercato = 7;
    bLen = 0;
    b = trova_indici_maggiori_di(a3Len, a3, valore_cercato, &bLen);
    puts("\nIndici degli elementi maggiori di 7:");
    if (b != NULL) {
        stampa_array(bLen, b);
        puts("0 2 3 6 8    [atteso]\n");
        printf("La dimensione dell'array di indici e': %zu\n", bLen);
        puts("La dimensione dell'array di indici e': 5    [atteso]\n");
        free(b);
        b = NULL;   
    }
    puts("-------------\n");

    puts("-------------");
    int a4[] = { 5, 5, 10, 10, 10, 20, 20, 30, 5, 7 };
    size_t a4Len = A_CAP;
    puts("Stampa di a4[]:");
    stampa_array(a4Len, a4);

    // copia univoci se adiacenti
    bLen = 0;
    b = copia_univoci_se_adiacenti(a4Len, a4, &bLen);
    puts("\nCopia univoci se adiacenti:");
    if (b != NULL) {
        stampa_array(bLen, b);
        puts("5 10 20 30 5 7    [atteso]\n");
        printf("La dimensione dell'array copiato e': %zu\n", bLen);
        puts("La dimensione dell'array copiato e': 6    [atteso]\n");
        free(b);
        b = NULL;   
    }


}


//------------------------------------------------------------------

void stampa_array(const size_t aLen, const int a[])
{
    for (size_t i=0; i<aLen; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

//------------------------------------------------------------------

int* copia_nonnegativi(size_t aLen, const int a[], 
                       size_t* p_bLen)
{
    // COMPLETARE
    int count = 0;
    for(size_t i = 0; i < aLen;i++){
        if (a[i] >= 0)
        {
            count++;
        }
    }
    int* b = malloc(count * sizeof(int));
    for(size_t j = 0; j < aLen;j++){
        if(a[j] >= 0){
            b[*p_bLen] = a[j];
            (*p_bLen)++;
        }
    }
    return b;
}

//------------------------------------------------------------------

int* trasforma_in_quadrati(const size_t aLen, const int a[], 
                           size_t* p_bLen)
{
    // COMPLETARE
    int* b= malloc(aLen * sizeof(int)); 
    for (size_t i = 0; i < aLen; i++)
    {
        b[*p_bLen] = a[i] * a[i];
        (*p_bLen)++;
    }

    return b;
}

//------------------------------------------------------------------

int* trova_indici_maggiori_di(const size_t aLen, const int a[],
                              const int valore_cercato,
                              size_t* p_bLen)
{
    // COMPLETARE
    int count = 0; 
    for(size_t i = 0;i < aLen; i++){
        if(a[i] > valore_cercato){
            count++;
        }
    }
    int* b= malloc(count * sizeof(int));
    for(size_t i = 0; i < aLen; i++){
        if(a[i] > valore_cercato){
            b[*p_bLen] = i;
            (*p_bLen)++;
        }
    }
    return b;
}

//------------------------------------------------------------------

int* copia_univoci_se_adiacenti(const size_t aLen, const int a[],
                              size_t* p_bLen)
{
    // COMPLETARE
    int count = 0;
    for(size_t i = 0; i < aLen; i++){
        if(a[i] != a[i+1] && i + 1 < aLen){
            count++;
        }
    }

    int* b= malloc(count * sizeof(int));
    for(size_t i = 0; i < aLen; i++){
        if(a[i] != a[i+1] && i + 1 <= aLen){
            b[*p_bLen] = a[i];
            (*p_bLen)++;
        }
    }
    return b;
}
