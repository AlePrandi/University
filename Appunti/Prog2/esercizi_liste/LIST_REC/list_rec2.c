#include "./list_rec.h"

ListNodePtr fromTo_rec(int m, int n){
    if(m > n) return NULL;
    ListNodePtr nodo = (ListNodePtr *)malloc(sizeof(ListNode));
    nodo->data = m;
    nodo->next = fromTo_rec(m+1,n);
    return nodo;
}

ListNodePtr fromTo(int m, int n){
    if(m > n) return NULL;
    ListNodePtr nodo = (ListNodePtr *)malloc(sizeof(ListNode));
    nodo->next = fromTo_rec(m+1,n);
    nodo->data = m;
    return nodo;
}


_Bool included_rec(ListNodePtr ls1, ListNodePtr ls2){
    if(!ls1) return true;
    if(!ls2) return false;
    if(ls1->data == ls2->data) return included_rec(ls1->next, ls2->next);
    else return included_rec(ls1, ls2->next);
}

ListNodePtr reverse_rec(ListNodePtr ls){ // ?
    if(!ls) return NULL;
    ListNodePtr nodo = (ListNodePtr)malloc(sizeof(ListNode));
    ListNodePtr primo = ls;
    nodo->next = reverse_rec(ls->next);
    nodo->data = primo->data;
    return nodo;
}

ListNodePtr zipSum_rec(ListNodePtr ls1, ListNodePtr ls2){
    if(!(ls1 && ls2)) return NULL;
    ListNodePtr nodo = (ListNodePtr *)malloc(sizeof(ListNode));
    if(!nodo) return NULL;
    nodo->data = ls1->data + ls2->data;
    nodo->next = zipSum_rec(ls1->next, ls2->next);
    return nodo;
}

ListNodePtr zipSum(ListNodePtr ls1, ListNodePtr ls2){
    if(!(ls1 && ls2)) return NULL;
    ListNodePtr nodo = (ListNodePtr *)malloc(sizeof(ListNode));
    if(!nodo) return NULL;
    nodo->next = zipSum(ls1->next, ls2->next);
    nodo->data = ls1->data + ls2->data;
    return nodo;
}

int occurrences_rec(ListNodePtr ls, int x){
    if(!ls) return 0;
    return (ls->data == x) ? 1 + occurrences_rec(ls->next, x) : 0 + occurrences_rec(ls->next, x);
}

// Toglie tutte le occorrenze di @x dalla lista *@p_ls (modifica *@p_ls).
void remove_all_rec(ListNodePtr *p_ls, int x){
    if(!p_ls || !(*p_ls)) return;
    if((*p_ls)->data == x){
        ListNodePtr temp = (*p_ls);
        (*p_ls) = (*p_ls)->next;
        free(temp);
        temp = NULL;
        remove_all_rec((*p_ls), x);
    }else{
        remove_all_rec(&((*p_ls)->next), x);
    }
}