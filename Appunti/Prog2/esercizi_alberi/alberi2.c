#include <stdlib.h>
#include <stdio.h>

typedef struct tree Tree, *TreePtr;
typedef struct list List, *ListPtr;

struct tree{
    int data;
    TreePtr left;
    TreePtr right;
};

struct list{
    int data;
    ListPtr next;
};

TreePtr creaNodo(int data){
    TreePtr node = (TreePtr)malloc(sizeof(Tree));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void printTree(TreePtr tPtr){
    if(!tPtr) {
        printf("x");
        return;
    }
    printf("%d", tPtr->data);
    if(tPtr->left || tPtr->right){
        printf(" : [");
        printTree(tPtr->left);
        printf(",");
        printTree(tPtr->right);
        printf("]");
    }
}

void printList(ListPtr lPtr){
    if(!lPtr){
        printf("NULL");
        return;
    }
    printf("%d --> ", lPtr->data);
    printList(lPtr->next);
}

void freeList(ListPtr *lPtr){
    if(!(*lPtr)) return;
    freeList(&(*lPtr)->next);
    free(*lPtr);
    *lPtr = NULL;
}

void freeTree(TreePtr *tPtr){
    if(!(*tPtr)) return;
    freeTree(&(*tPtr)->left);
    freeTree(&(*tPtr)->right);
    free(*tPtr);
    *tPtr = NULL;
}


/**
 * @brief funzione che dato un albero inverte i figli destri con i sinistri
 * @param tPtr puntatore all'albero
 */
void switchTree(TreePtr tPtr){
    if(!tPtr) return;
    TreePtr temp = tPtr->left;
    tPtr->left = tPtr->right;
    tPtr->right = temp;
    switchTree(tPtr->left);
    switchTree(tPtr->right);
}



/**
 * @brief funzione che dato un'albero restituisce la lista in ordine crescente dei suoi parametri
 * @param tPtr puntatore all'albero
 */
void tree2list(TreePtr tPtr, ListPtr *head, ListPtr *tail){
    if(!tPtr) return;
    tree2list(tPtr->left, head, tail);
    ListPtr node = (ListPtr)malloc(sizeof(List));
    node->data = tPtr->data; 
    if(!(*head)){
        (*head) = node;
    }else{
        (*tail)->next = node;
    }
    (*tail) = node;
    tree2list(tPtr->right, head, tail);
}

ListPtr wrapper(TreePtr tPtr){
    ListPtr head = NULL;
    ListPtr tail = NULL;
    tree2list(tPtr, &head, &tail);
    return head;
}

int main(void){

    TreePtr alb1;
    alb1 = creaNodo(10);
    alb1->left = creaNodo(5);
    alb1->left->left = creaNodo(3);
    alb1->left->right = creaNodo(7);
    alb1->right = creaNodo(12);
    alb1->right->right = creaNodo(15);
    
    ListPtr l = wrapper(alb1);

    printTree(alb1);
    puts("");
    switchTree(alb1);
    printTree(alb1);
    puts("");
    printList(l);
    puts("");

    freeTree(&alb1);
    freeList(&l);

    return 0;
}