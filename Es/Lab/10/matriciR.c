#include <stdio.h>
#include <stdbool.h>

//------------------------------------------------------------------
// Prototipi delle funzioni
//------------------------------------------------------------------

// Restituisce true se esiste un elemento pari nell'array a
bool esiste_pari(const size_t aLen, const int a[]); // involucro
bool esiste_pariR(const int a[],const size_t left,const size_t right);

// Restituisce il numero di righe su cui compaiono elementi pari
size_t conta_righe_con_pari(const size_t rows, const size_t cols,
                            const int mat[rows][cols]); // involucro
size_t conta_righe_con_pariR(const size_t rows, const size_t cols,
			     const int mat[rows][cols],size_t R);

//------------------------------------------------------------------

// Restituisce true se tutti gli elementi dell'array 
// appartengono all'intervallo [min, max]
bool tutti_in_intervallo(const size_t aLen, const int a[], 
                         const int min, const int max); // involucro
bool tutti_in_intervalloR(const int a[], 
			  const int min, const int max,size_t left, size_t right);


// Restituisce il numero di righe i cui
// elementi appartengono tutti all'intervallo [min, max]
size_t numero_righe_minmax(const size_t rows, const size_t cols,
			   const int mat[rows][cols], 
			   const int min, const int max); // involuc
size_t numero_righe_minmaxR(const size_t rows, const size_t cols,
			    const int mat[rows][cols], 
			    const int min, const int max,size_t R);


//------------------------------------------------------------------

int main(void) {
    const size_t rowsA = 3, colsA = 6;
    int matA[3][6] = {
      {91,35,51,1,1,1},
      {9,83,75,87,41,65},
      {1,53,96,15,0,0}};

    const size_t rowsB = 4, colsB = 7;
    int matB[4][7] = {
      {19,7,25,59,1,3,5},
      {46,9,2,4},
      {55,1,44,65,1,1,1},
      {85,49,11,42,4,10,30}};

    const size_t rowsC = 5, colsC = 10;
    int matC[5][10] = {
      {29,65,20,12,19,15,30,60,14},
      {10,82,17,78},
      {35,74,68,18,36,94,10,62,93,16},
      {95,1,23,67,1,1,1,1,1,1},
      {92,59,92,81,86,46,24,17,24,51}};

    // Unit test per la conta delle righe con elementi pari
    puts("Righe con elementi pari");
    size_t crpA = conta_righe_con_pari(rowsA, colsA, matA);
    size_t crpB = conta_righe_con_pari(rowsB, colsB, matB);
    size_t crpC = conta_righe_con_pari(rowsC, colsC, matC);
    printf("Matrice A: %2zu  [atteso: 1]\n", crpA);
    printf("Matrice B: %2zu  [atteso: 3]\n", crpB);
    printf("Matrice C: %2zu  [atteso: 4]\n", crpC);

    // Unit test per la conta delle righe con elementi compresi tra min e max
    puts("\nNumero righe minmax");
    size_t NRA = numero_righe_minmax(rowsA, colsA, matA, 5, 75);
    size_t NRB = numero_righe_minmax(rowsB, colsB, matB, 5, 75);
    size_t NRC = numero_righe_minmax(rowsC, colsC, matC, 5, 75);
    printf("Matrice A: %2zu  [atteso: 0]\n", NRA);
    printf("Matrice B: %2zu  [atteso: 2]\n", NRB);
    printf("Matrice C: %2zu  [atteso: 3]\n", NRC);
}

//------------------------------------------------------------------

// da completare (definizione e implementazione)
