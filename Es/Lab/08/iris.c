#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define ROWS 3
#define COLS 18

//------------------------------------------------------------------
// Prototipi delle funzioni
//------------------------------------------------------------------

// Calcola la media dei valori nell'array a[] di lunghezza aLen
// corrispondente alla riga r-esima della matrice.
float media_specie(const size_t aLen, const float a[]);

// trova il minimo ed il massimo dei valori alla riga r
// della matrice. I valori trovati sono scritti in *pMin e *pMax
void minmax_specie(const float mat[ROWS][COLS],
                   const size_t r,
                   float *pMin, float *pMax);

// Filtra la riga r della matrice in un nuovo array a[],
// allocato dinamicamente su heap, mantenendo solo gli elementi
// strettamente maggiori di min e strettamente minori di max.
// La funzione restituisce il puntatore all'array a[] appena allocato
// di lunghezza *p_aLen.
// Nota: il chiamante e' responsabile di liberare la memoria
// allocata per l'array restituito.
float *filtra_specie_minmax(float mat[ROWS][COLS],
                            const size_t r,
                            float min, float max,
                            size_t *p_aLen);

//------------------------------------------------------------------

int main(void)
{
    // Lunghezze dei petali degli Iris in cm.
    // fonte dei dati: "The use of multiple measurements
    //   in taxonomic problems", Ronald Aylmer Fisher, 1936. [estratto]
    // Contenuto matrice:
    // - ogni riga e' una specie;
    // - gli elementi di ciascuna riga sono i campioni statistici raccolti.
    float mat[ROWS][COLS] = {
        // Iris Setosa
        {
            1.0,
            1.4,
            1.3,
            1.5,
            1.4,
            1.7,
            1.4,
            1.5,
            1.4,
            1.5,
            1.5,
            1.6,
            1.4,
            1.1,
            1.2,
            1.5,
            1.3,
            1.7,
        },
        // Iris Versicolor
        {
            4.7, 4.5, 4.9, 4.0, 4.6, 4.5, 4.7, 3.3, 4.6, 3.9,
            3.5, 4.2, 4.0, 4.7, 3.6, 4.4, 4.5, 4.1},
        // Iris Virginica
        {
            6.9, 5.1, 5.9, 5.6, 5.8, 6.6, 4.5, 6.3, 5.8, 6.1,
            5.1, 5.3, 4.5, 5.0, 5.1, 5.3, 5.5, 6.7},
    };

    // nomi delle specie di Iris considerate
    const char *specie[ROWS] = {
        "Iris Setosa", "Iris Versicolor", "Iris Virginica"};

    // Calcola medie e valori estremi dai dati raccolti
    // per le tre specie di Iris.
    float min_vals[ROWS], max_vals[ROWS];
    for (size_t i = 0; i < ROWS; i++)
    {
        minmax_specie(mat, i, &min_vals[i], &max_vals[i]);
    }

    // Stampa i risultati prima dell'eliminazione dei
    // campioni con valori estremi
    puts("Specie                  Media  Estremi");
    for (size_t i = 0; i < ROWS; i++)
    {
        printf("%-20s    %.2f   (min: %.2f max: %.2f)\n",
               specie[i],
               media_specie(COLS, mat[i]),
               min_vals[i], max_vals[i]);
    }

    puts("\nDopo eliminazione valori estremi:");
    // Stampa nuovamente le medie dopo l'eliminazione dei
    // campioni con valori estremi
    puts("Specie                  Media");

    size_t aLen = 0;
    float *a = NULL;
    for (size_t i = 0; i < ROWS; i++)
    {
        // Filtra i valori estremi
        a = filtra_specie_minmax(mat, i, min_vals[i], max_vals[i], &aLen);

        if (a != NULL)
        {
            printf("%-20s    %.2f (su %zu campioni non-estremi)\n",
                   specie[i],
                   media_specie(aLen, a),
                   aLen);

            free(a);
            a = NULL;
        }
    }
}

// completare
//------------------------------------------------------------------
float media_specie(const size_t aLen, const float a[])
{
    float val = 0;
    for (size_t i = 0; i < aLen; i++)
    {
        val += a[i];
    }
    return val / aLen;
}

//------------------------------------------------------------------
void minmax_specie(const float mat[ROWS][COLS],
                   const size_t r,
                   float *pMin, float *pMax)
{
    for (size_t i = 0; i < COLS; i++)
    {
        if (i == 0 || mat[r][i] < *pMin)
        {
            *pMin = mat[r][i];
        }
        if (i == 0 || mat[r][i] > *pMax)
        {
            *pMax = mat[r][i];
        }
    }
}

//------------------------------------------------------------------
float *filtra_specie_minmax(float mat[ROWS][COLS],
                            const size_t r,
                            float min, float max,
                            size_t *p_aLen)
{
    size_t cont = 0;
    *p_aLen = 0;
    for(size_t i = 0; i < COLS; i++){
        if(mat[r][i] < max && mat[r][i] > min){
            cont++;
        }
    }

    float *a = malloc(cont *sizeof(float));
    for(size_t i = 0; i < COLS; i++){
        if(mat[r][i] < max && mat[r][i] > min){
            a[*p_aLen] = mat[r][i];
            (*p_aLen)++;
        }
    }
    return a;
}

//------------------------------------------------------------------
