#include "./esonero2.h"

/* INSERIRE QUI EVENTUALI ALTRI #include <...> */
/* INSERT HERE MORE #include <...> IF NEEDED */

void freeList(List l){
    if(!l) return;
    freeList(l->next);
    free(l);
    l = NULL;
}

List createList(char str[], int size){
    List ret = NULL;
    for(int i = size-1; i >= 0; i--){
        List node = malloc(sizeof(ListNode));
        node->data = str[i];
        node->next = ret;
        ret = node;
    }
    return ret;
}

/* INSERIRE QUI EVENTUALI FUNZIONI AUSILIARIE */
/* INSERT HERE AUXILIARY FUNCTIONS IF NEEDED */

/**
 * Date due liste di caratteri l ed r, restituire una nuova lista p (senza
 * modificare le liste l ed r) che contenga il più lungo prefisso di l per
 * cui nessun suo carattere ha un carattere uguale nella posizione
 * corrispondente di r.
 * 
 * Si definisce "prefisso" di una lista una qualunque sotto-lista di nodi dall'inizio.
 * Non considera l'eventualità che la malloc fallisca.
 *
 * ESEMPI (rappresentando le liste senza separare i caratteri, per compattezza):
 * (1) date l=[] e s=[], restituisce p=[]
 * (2) date l=[] e s=[p,i,p,p,o], restituisce p=[]
 * (3) date l=[p,i,p,p,o] e s=[], restituisce p=[p,i,p,p,o]
 * (4) date l=[p,i,p,p,o] e s=[p,i,p,p,o], restituisce p=[]
 * (5) date l=[s,u,p,e,r,p,i,p,p,o] e s=[p,l,u,t,o], restituisce p=[s,u,p,e,r,p,i,p,p,o]
 * (6) date l=[p,l,u,t,o] e s=[s,u,p,e,r,p,i,p,p,o], restituisce p=[p,l,u,t,o]
 * (7) date l=[s,u,p,e,r,p,i,p,p,o] e s=[p,i,p,p,o], restituisce p=[s,u], perché la p seguente è in comune
 * (8) date l=[p,i,p,p,o] e s=[s,u,p,e,r,p,i,p,p,o], restituisce p=[p,i], perché la p seguente è in comune
 * 
 * NOTA: questa funzione compare negli errori di compilazione come "student_antiPrefix"
 * NOTA: questa funzione viene testata indipendentemente dal vostro main
 * IMPORTANTE: cercate sempre di far compilare il vostro codice per poter vedere il
 * risultato dei test, anche a costo di commentare parte del codice di questa funzione
 */
 List antiPrefix(List l, List r) {
    if(!l) return NULL;
    if(!r){
        List p = (List)malloc(sizeof(ListNode));
        p->data = l->data;
        p->next = antiPrefix(l->next, r);
        return p;
    };
    if(l->data != r->data){
        List p = (List)malloc(sizeof(ListNode));
        p->data = l->data;
        p->next = antiPrefix(l->next, r->next);
        return p;
    }
    return NULL;
}


/**
 * Invoca la funzione antiPrefix su uno o più casi a scelta, controllando che
 * il suo effetto come risultato e argomenti rispetti la specifica corretta.
 * Può essere sufficiente anche un unico caso, se sufficientemente generale per
 * individuare quali programmi sono corretti e quali no.
 * Se la funzione è corretta, come ultima cosa deve stampare "TEST PASSED\n".
 * Se invece la funzione non risulta corretta, deve stampare "TEST FAILED\n".
 * NON STAMPARE ALTRO SU STANDARD OUTPUT.
 * Se avete necessità di fare stampe di debug, potete farle su standard error.
 *
 * NOTA: dovete invocare "antiPrefix" e NON "student_antiPrefix"
 * NOTA: questa funzione compare negli errori di compilazione come "student_main"
 * NOTA: il main viene testato indipendentemente dalla vostra funzione antiPrefix
 * IMPORTANTE: cercate sempre di far compilare il vostro codice per poter vedere il
 * risultato dei test, anche a costo di commentare parte del codice di questa funzione
 */
int main() {

    List l = createList("pippo", 5);
    List r = createList("superpippo", 10);
    
    List res = antiPrefix(l, r);
    
    int ok = 1;
    if (res == NULL || res->data != 'p') ok = 0;
    if (ok && (res->next == NULL || res->next->data != 'i')) ok = 0;
    if (ok && (res->next->next != NULL)) ok = 0;
    
    freeList(l);
    freeList(r);
    freeList(res);
    
    r = createList("pippo", 5);
    
    res = antiPrefix(NULL, r);
    
    if(res != NULL) ok = 0;
    
    freeList(r);

    if (ok) printf("TEST PASSED\n");
    else printf("TEST FAILED\n");


    return 0;
}
