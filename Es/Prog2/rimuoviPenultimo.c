#include <stdio.h>
#include <stdlib.h>

typedef struct list ListNode, *List;

struct list{
    int data;
    List next;
};

/**
* Modifica *lsPtr togliendo da *lsPtr il suo penultimo nodo, se esiste (ovvero
* se la lista contiene almeno due elementi),e liberando la memoria da esso occupata.
*
* ESEMPIO:
* dato 1 -> 2 -> 3 -> 4 cambia in 1 -> 2 -> 4 e libera la memoria occupata da 3.
* restituisce :
* -1 se lstPtr == NULL;
* 0 se lista vuota o in caso di fallimento
* 1 in caso di successo
*
* ESEMPI
*
* se lsPtr == NULL, dopo l’esecuzione lsPtr == NULL e ritorna -1.
* se *lsPtr == NULL, dopo l’esecuzione *lsPtr == NULL e ritorna 0.
* se *lsPtr == [25], dopo l’esecuzione *lsPtr == [25] e ritorna 0.
* se *lsPtr == [10, 8, 12, 3], dopo l’esecuzione *lsPtr == [10, 8, 3] e restituisce 1.
*/
int eliminaPenultimo(List *lsPtr){
    if(!lsPtr) return -1;
    if(!(*lsPtr) || !(*lsPtr)->next) return 0;
    List curr = *lsPtr;
    if(!curr->next->next){
        List temp = curr;
        *lsPtr = curr->next;
        free(temp);
        return 1;
    }
    List prec = NULL;
    while(curr->next->next){
        prec = curr;
        curr = curr->next;
    }
    List temp = curr;
    prec->next = curr->next;
    curr = curr->next;
    free(temp);
    return 1;
}

typedef struct treeNode IntTreeNode, *IntTree;
struct treeNode {
IntTree left;
int data;
IntTree right;
};

int sumMinMaxRec(IntTree tree, int min, int max, int current){
    if(!tree || current > max) return 0;
    return ((current >= min) ? tree->data : 0) + sumMinMaxRec(tree->left,min,max, current+1) + sumMinMaxRec(tree->right, min,max, current+1);
}

/**
* Dato un albero binario tree, e due numeri interi min e max, restituisce la somma
* di tutti gli elementi che si trovano ad un livello >= min e <= max. Si assuma che il livello della radice sia 0.
*
* ESEMPI: dato
*
*
*       1
*      / \
*     2   3
*    / \
*   4  5
*
*
* 1) per min = 0 e max = 4 restituisce 15
* 2) per min = 1 e max = 3 restituisce 14
* 3) per min = 2 e max = 2 restituisce 9
* 4) per min = 3 e max = 2 restituisce 0
* 5) per min = 2 e max = -5 restituisce 0
* 6) per min = 6 e max = 7 restituisce 0
* 7) tree = NULL, restituisce 0
*/
int sumMinMax (IntTree tree, int min, int max){
    return sumMinMaxRec(tree,min,max, 0);
}