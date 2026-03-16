#include "list_iter.h"


typedef struct listNode ListNode, *ListNodePtr;

struct listNode {
   int data;
   ListNodePtr next;
};

// Ritorna una lista contenente tutti i numeri interi 
// compresi tra @m ed @n, estremi inclusi. 
ListNodePtr fromTo_iter(int m, int n){
    if(m > n) return NULL;

    ListNodePtr head = NULL;
    ListNodePtr tail = NULL;

    for(int i = m; i <= n;i++){
        ListNodePtr newnode = malloc(sizeof(ListNode));
        newnode->data = i;
        newnode->next = NULL;

        if(head == NULL){
            head = newnode;
            tail = newnode;
        }else{
            tail->next = newnode;
            tail = newnode;
        }
    }
    return head;
}

// Ritorna true se tutti gli elementi nella lista @ls1 
// compaiono nello stesso ordine anche nella lista @ls2.
_Bool included_iter(ListNodePtr ls1, ListNodePtr ls2){
    bool allEq = true;
    if(!ls1) return true;
    if(!ls2) return false;
    while(ls2 != NULL){
        if (ls1->data == ls2->data)
        {
            ls1 = ls1->next;
            if(ls1 == NULL) allEq = true;
        }else allEq = false;

        ls2 = ls2->next;
    }

    return allEq;
}

// Ritorna una nuova lista con gli elementi di @ls
// in ordine inverso (non modifica la lista @ls).
ListNodePtr reverse_iter(ListNodePtr ls){
    if(!ls) return NULL;
    ListNodePtr head = NULL;
    while(ls != NULL){
        ListNodePtr Newnode = malloc(sizeof(ListNode));
        Newnode->data = ls->data;

        Newnode->next = head;
        head = Newnode;

        ls = ls->next;
    }
    return head;
}

// Ritorna la lista i cui elementi sono le somme 
// a coppie degli elementi corrispondenti di due liste @ls1 e @ls2 
// di uguale lunghezza (non modifica la liste @ls1 e @ls2).
ListNodePtr zipSum_iter(ListNodePtr ls1, ListNodePtr ls2){
    if(!ls1 || !ls2) return NULL;
    ListNodePtr head = NULL;
    ListNodePtr tail = NULL;
    while(ls1 && ls2){
        ListNodePtr newnode = malloc(sizeof(ListNode));
        newnode->data = ls1->data + ls2->data;
        newnode->next = NULL;
        if(!head){
            head = newnode;
            tail = newnode;
        }else{
            tail->next = newnode;
            tail = newnode;
        }

        ls1 = ls1->next;
        ls2 = ls2->next;
    }
    return head;
}

// Conta il numero di occorrenze di @x nella lista @ls.
int occurrences_iter(ListNodePtr ls, int x){
    if(!ls) return 0;
    int occ = 0;
    while(ls){
        if(ls->data == x)
            occ++;

        ls = ls->next;
    }
    return occ;
}

// Toglie tutte le occorrenze di @x dalla lista *@p_ls  (modifica *@p_ls).
void remove_all_iter(ListNodePtr *p_ls, int x){
    while(*p_ls){
        if((*p_ls)->data == x){
            ListNodePtr *temp = *p_ls;
            *p_ls = (*p_ls)->next;
            free(temp);
        }
        p_ls = &(*p_ls)->next;
    }
}

// Duplica tutti i nodi della lista @ls che contengono un numero pari (modifica @ls).
void duplicate_even_iter(ListNodePtr ls){
    while(ls){
        if(ls->data % 2 == 0){
            ListNodePtr temp = ls;
            
        }

        ls = ls->next;
    }
}