#include <stdlib.h>
#include <stdio.h>
#include "./alberi.h"

/**
 * @brief Dato un albero binario restituisce le profondità minima e massima delle sue foglie
 * (considerate entrambe -1 se l’albero è vuoto).
 */
void minMaxLevel_rec(IntTree tree, ReportPtr ret, int depth){

    if(tree == NULL) return;

    if(!tree->left && !tree->right){
        if(depth < ret->min || ret->min == -1) ret->min = depth;
        if(depth > ret->max || ret->max == -1) ret->max = depth;
    }

    minMaxLevel_rec(tree->left,ret, depth+1);
    minMaxLevel_rec(tree->right, ret, depth+1);
}


ReportPtr minMaxLevel(IntTree tree){

    ReportPtr ret = (ReportPtr)malloc(sizeof(Report));
    ret->min = -1;
    ret->max = -1;

    if(tree == NULL) return ret;

    minMaxLevel_rec(tree, ret, 0);

    return ret;
}

/**
 * @brief Mette nell'albero l'elemento 'e' nella  posizione identificata
 * da 'path' (una stringa di caratteri 'L' per left e 'R' per right).
 * Ovvero:
 *  - se 'path' porta a un nodo, assegna 'e' al campo 'data' di quel nodo
 *  - se 'path' porta fuori dall'albero, inserisce come figlio della foglia da cui si è usciti
 *    dall'albero un nuovo nodo che contiene 'e'.
 * Restituisce:
 * - ADDED se ha aggiunto un nuovo nodo,
 * - OVERWRITTEN se ha modificato il nodo esistente,
 * - OUT_OF_MEMORY se la malloc fallisce,
 * - ERROR se 'path' contiene un carattere diverso da 'L' o 'R' prima di uscire dall'albero.
 */
Response put(IntTree *treePtr, char *path, int e){

}

/**
 * @brief Controlla se il secondo albero è una "potatura" del primo
 */
_Bool isPruning(IntTree tree, IntTree pruned){
    if(!tree || (tree && !pruned)) return 0;

    int pruning = 1;
    if(tree->data == pruned->data){
        if(isPruning(tree->left, pruned)){
            
        }
    }

    return pruning;
}

/**
 * @brief Dato un ARB restituisce un array che contiene tutti gli elementi dell'ARB
 * in un ordine tale che, se gli elementi sono tutti distinti, allora
 * inserendoli in quell'ordine nell'ARB vuoto si ricostruisce l'ARB originale.
 */
int *arbToArray(IntTree tree){

}


int countNodi(IntTree tree){
    if(!tree) return 0;
    return 1 + countNodi(tree->left) + countNodi(tree->right);
}

int height_rec(IntTree tree, int depth){
    if(!tree) return depth-1;
    if(!tree->left && !tree->right) return depth;

    int dLeft = height_rec(tree->left, depth + 1);
    int dRight = height_rec(tree->right, depth + 1); 

    return (dLeft > dRight) ? dLeft : dRight;
}

int height(IntTree tree){
    return height_rec(tree, 0);
}