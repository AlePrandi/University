#include <stdio.h>
#include <stdlib.h>

typedef struct listNode ListNode, *List;

struct listNode {
    int data;
    List next;
};

/* INSERIRE QUI EVENTUALI ALTRI #include <...> */
/* INSERT HERE MORE #include <...> IF NEEDED */

/* INSERIRE QUI EVENTUALI FUNZIONI AUSILIARIE */
/* INSERT HERE AUXILIARY FUNCTIONS IF NEEDED */
void freeList(List l){
    if(!l) return;
    freeList(l->next);
    free(l);
}

List creaNodo(int val){
    List node = (List)malloc(sizeof(ListNode));
    node->data = val;
    node->next = NULL;
    return node;
}

_Bool testArrayMerge(List res, int n, int *expected) {
  for (size_t i = 0; i < n; i++) {
    if (res == NULL || res->data != expected[i]) {
      return 0;
    }

    res = res->next;
  }

  return 1;
}
/**
 * Dati due array di interi a e b di uguale lunghezza n, restituire una lista
 * di n interi che contiene nell’ordine gli interi a[n-1], b[1], a[n-3], b[3]...
 * Quindi, alterna tra prendere gli elementi dall'inverso di a e da b.
 *
 * Non considera l'eventualità che la malloc fallisca.
 * Si assuma che a != NULL, b != NULL.
 *
 * ESEMPI:
 * (1) dati a=[], b=[], n=0 restituisce []
 * (2) dati a=[5], b=[3], n=1 restituisce [5]
 * (2) dati a=[10, 20], b=[1, 2], n=2 restituisce [20, 2]
 * (4) dati a=[1, 2, 3, 4], b=[6, 7, 8, 9], n=4 restituisce [4, 7, 2, 9]
 *
 * NOTA: questa funzione compare negli errori di compilazione come "student_arrayMerge"
 * NOTA: questa funzione viene testata indipendentemente dal vostro main
 * NOTA: viene controllato che questa funzione gestisca correttamente la memoria
 * IMPORTANTE: cercate sempre di far compilare il vostro codice per poter vedere il
 * risultato dei test, anche a costo di commentare parte del codice di questa funzione
 *
 * <ENGLISH VERSION>
 *
 * Given two integer arrays a and b of identical length n, return a list of
 * n integers containing (in order) integers a[n-1], b[1], a[n-3], b[3]...
 * That is, alternates between picking elements from the reverse of a and
 * from b.
 *
 * It does not consider the possibility that malloc may fail.
 * Assume that a != NULL, b != NULL.
 *
 * EXAMPLES:
 * (1) given a=[], b=[], n=0 returns []
 * (2) given a=[5], b=[3], n=1 returns [5]
 * (2) given a=[10, 20], b=[1, 2], n=2 returns [20, 2]
 * (4) given a=[1, 2, 3, 4], b=[6, 7, 8, 9], n=4 returns [4, 7, 2, 9]
 *
 * NOTE: this function appears in compilation errors as "student_arrayMerge"
 * NOTE: this function is tested independently of your main
 * NOTE: this function also has to correctly handle memory allocation and freeing
 * IMPORTANT: always try to make your code compile so that you can see the test
 * results, even if that means commenting out part of the code of this function
 */
List arrayMerge(int *a, int *b, int n) {

    /* INSERIRE QUI IL CODICE */
    /* INSERT YOUR CODE HERE */
    List head = NULL;
    List tail = NULL;
    
    for(int i = 0; i < n; i++){
        List node = NULL;
        if(i % 2 == 0){
            node = creaNodo(a[n-i-1]);
        }else{
            node = creaNodo(b[i]);
        }
        if(!head){
            head = node;
        }else{
            tail->next = node;
        }
        tail = node;
    }

    return head;
}

void arrayMergeRec(int *a, int *b, int i, int n, List *head, List *tail){
    if(i >= n) return;
    List node = creaNodo((i % 2 == 0) ? a[n-i-1] : b[i]);
    if(!(*head)){
        (*head) = node;
    }else{
        (*tail)->next = node;
    }
    (*tail) = node;
    arrayMergeRec(a,b,i+1,n,head, tail);
}

List arrayMergeRecWrap(int *a, int *b, int n){
    List head = NULL;
    List tail = NULL;
    arrayMergeRec(a,b,0,n, &head, &tail);
    return head;
}

/**
 * Invoca la funzione "arrayMerge" su uno o più casi a scelta, controllando che
 * il suo effetto come risultato e argomenti rispetti la specifica corretta.
 * Può essere sufficiente anche un unico caso, se sufficientemente generale per
 * individuare quali programmi sono corretti e quali no.
 * Se la funzione è corretta, come ultima cosa deve stampare "TEST PASSED\n".
 * Se invece la funzione non risulta corretta, deve stampare "TEST FAILED\n".
 * NON STAMPARE ALTRO SU STANDARD OUTPUT.
 * Se avete necessità di fare stampe di debug, potete farle su standard error.
 *
 * NOTA: questa funzione compare negli errori di compilazione come "student_main"
 * NOTA: il main viene testato indipendentemente dalla vostra funzione "arrayMerge"
 * NOTA: viene controllato che questa funzione gestisca correttamente la memoria
 * IMPORTANTE: cercate sempre di far compilare il vostro codice per poter vedere il
 * risultato dei test, anche a costo di commentare parte del codice di questa funzione
 *
 * <ENGLISH VERSION>
 *
 * Invokes the "arrayMerge" function on one or more selected test cases, checking
 * that its effect as result and arguments respects the correct specification.
 * A single test case may be enough, if it sufficiently general to single out
 * which programs are correct and which are not.
 * If the function is correct, as the final step it must print "TEST PASSED\n".
 * If instead the function is not correct, it must print "TEST FAILED\n".
 * DO NOT PRINT ANYTHING ELSE ON STANDARD OUTPUT.
 * If you need to print debug information, use standard error.
 *
 * NOTE: this function appears in compilation errors as "student_main"
 * NOTE: the main is tested independently of your "arrayMerge" function
 * NOTE: this function also has to correctly handle memory allocation and freeing
 * IMPORTANT: always try to make your code compile so that you can see the test
 * results, even if that means commenting out part of the code of this function
 */
int main() {
  #define N 5
  int a[N] = {0, 1, 2, 3, 4};
  int b[N] = {5, 6, 7, 8, 9};
  int expected[N] = {4, 6, 2, 8, 0};

  List res = arrayMerge(a, b, N);

  if (testArrayMerge(res, N, expected))
    printf("TEST PASSED\n");
  else
    printf("TEST FAILED\n");

  freeList(res);
  return 0;
}