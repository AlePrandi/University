#include "list_rec.h"

// Ritorna una lista contenente tutti i numeri interi 
// compresi tra @m ed @n, estremi inclusi. 
ListNodePtr fromTo_rec(int m, int n){
    if(m>n) return NULL;

    ListNodePtr newnode = malloc(sizeof(ListNode));
    newnode->data = m;
    newnode->next = fromTo_rec(m+1, n);

    return newnode;
}

//VERSIONE ricorsiva di coda
ListNodePtr fromTo(int m, int n){
    if(m>n) return NULL;

    ListNodePtr newnode = malloc(sizeof(ListNode));
    newnode->next = fromTo(m+1, n);
    newnode->data = m;

    return newnode;
}

// Ritorna true se tutti gli elementi nella lista @ls1 
// compaiono nello stesso ordine anche nella lista @ls2.
_Bool included_rec(ListNodePtr ls1, ListNodePtr ls2){
    if(!ls1) return true;
    if(!ls2) return false;

    if(ls1->data == ls2->data)
        included_rec(ls1->next, ls2->next);
    else
        included_rec(ls1, ls2->next);
     
}

// Ritorna una nuova lista con gli elementi di @ls 
// in ordine inverso (non modifica la lista @ls).
ListNodePtr reverse_rec(ListNodePtr ls){



}