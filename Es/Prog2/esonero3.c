#include <stdio.h>

typedef struct treeNode TreeNode, *Tree;

struct treeNode{
    Tree left;
    int data;
    Tree right;
};

typedef struct listNode ListNode, *List;

struct listNode{
    int data;
    List next;
};

/* INSERIRE QUI EVENTUALI ALTRI #include <...> */
/* INSERT HERE MORE #include <...> IF NEEDED */

/* INSERIRE QUI EVENTUALI FUNZIONI AUSILIARIE */
/* INSERT HERE AUXILIARY FUNCTIONS IF NEEDED */
void freeList(List l){
    if(l == NULL) return;
    freeList(l->next);
    free(l);
}

void freeAlb(Tree t){
    if(t == NULL) return;
    freeAlb(t->left);
    freeAlb(t->right);
    free(t);
}

Tree createNode(int data){
    Tree t = malloc(sizeof(TreeNode));
    t->data = data;
    t->left = NULL;
    t->right = NULL;
    
    return t;
}

int checkList(List l, int expected[], int size){
    for(int i = 0; i < size; i++){
        if(!l || l->data != expected[i]) return 0;
        l = l->next;
    }
    return 1;
}

/**
 * Dato un albero binario t, restituire una nuova lista p (senza modificare t)
 * che contenga il percorso entro t che parte dalla radice, e procede a sinistra
 * se il valore in un nodo è dispari, e a destra altrimenti.
 *
 * Gli alberi sono rappresentati tramite parentesi, con "-" per indicare un figlio mancante.
 * Non considera l'eventualità che la malloc fallisca.
 *
 * ESEMPI (rappresentando le liste senza separare i caratteri, per compattezza):
 * (1) dato t={}, restituisce l=[]
 * (2) dato t={-1-}, restituisce l=[1]
 * (3) dato t={[-3-]1-[-4-]}, restituisce l=[1,3]
 * (4) dato t={[-3-]2-[-4-]}, restituisce l=[1,4]
 *
 * NOTA: questa funzione compare negli errori di compilazione come "student_parityPath"
 * NOTA: questa funzione viene testata indipendentemente dal vostro main
 * IMPORTANTE: cercate sempre di far compilare il vostro codice per poter vedere il
 * risultato dei test, anche a costo di commentare parte del codice di questa funzione
 *
 * <ENGLISH VERSION>
 *
 * Given a binary tree t, return a new list p (without modifying t)
 * containing the path within t that starts from the root and proceeds
 * to the left if the value in a node is odd, and to the right otherwise.
 *
 * Trees are represented using parentheses, with "-" indicating a missing child.
 * It does not consider the possibility that malloc may fail.
 *
 * EXAMPLES (representing lists without separating characters, for compactness):
 * (1) given t={}, returns l=[]
 * (2) given t={-1-}, returns l=[1]
 * (3) given t={[-3-]1-[-4-]}, returns l=[1,3]
 * (4) given t={[-3-]2-[-4-]}, returns l=[1,4]
 *
 * NOTE: this function appears in compilation errors as "student_parityPath"
 * NOTE: this function is tested independently of your main
 * IMPORTANT: always try to make your code compile so you can see the
 * test results, even if it means commenting out part of this function's code
 */
 List parityPath(Tree t) {

    /* INSERIRE QUI IL CODICE */
    /* INSERT YOUR CODE HERE */
    if(t == NULL) return NULL;
    List p = malloc(sizeof(ListNode));
    p->data = t->data;
    if(t->data % 2 == 0) p->next = parityPath(t->right);
    else p->next = parityPath(t->left);

    return p;
}


/**
 * Invoca la funzione parityPath su uno o più casi a scelta, controllando che
 * il suo effetto come risultato e argomenti rispetti la specifica corretta.
 * Può essere sufficiente anche un unico caso, se sufficientemente generale per
 * individuare quali programmi sono corretti e quali no.
 * Se la funzione è corretta, come ultima cosa deve stampare "TEST PASSED\n".
 * Se invece la funzione non risulta corretta, deve stampare "TEST FAILED\n".
 * NON STAMPARE ALTRO SU STANDARD OUTPUT.
 * Se avete necessità di fare stampe di debug, potete farle su standard error.
 *
 * NOTA: dovete invocare "parityPath" e NON "student_parityPath"
 * NOTA: questa funzione compare negli errori di compilazione come "student_main"
 * NOTA: il main viene testato indipendentemente dalla vostra funzione parityPath
 * IMPORTANTE: cercate sempre di far compilare il vostro codice per poter vedere il
 * risultato dei test, anche a costo di commentare parte del codice di questa funzione
 *
 * <ENGLISH VERSION>
 *
 * Invokes the parityPath function on one or more selected test cases, checking
 * that its effect as result and arguments respects the correct specification.
 * A single test case may be enough, if it sufficiently general to single out
 * which programs are correct and which are not.
 * If the function is correct, as the final step it must print "TEST PASSED\n".
 * If instead the function is not correct, it must print "TEST FAILED\n".
 * DO NOT PRINT ANYTHING ELSE ON STANDARD OUTPUT.
 * If you need to print debug information, use standard error.
 *
 * NOTE: you have to invoke "parityPath" and NOT "student_parityPath"
 * NOTE: this function appears in compilation errors as "student_main"
 * NOTE: the main is tested independently of your parityPath function
 * IMPORTANT: always try to make your code compile so that you can see the test
 * results, even if that means commenting out part of the code of this function
 */
int main() {

    /* INSERIRE QUI IL CODICE */
    /* INSERT YOUR CODE HERE */

    Tree t = createNode(1);
    t->left = createNode(4);
    t->left->right = createNode(3);

    List l = parityPath(t);
    
    int expected[] = {1,4,3};
    
    if(checkList(l, expected, sizeof(expected)/sizeof(int))){
        printf("TEST PASSED\n");
    }else{
        printf("TEST FAILED\n");
    }
    
    freeList(l);
    l = NULL;
    
    freeAlb(t);
    t = NULL;
    
    return 0;
}
