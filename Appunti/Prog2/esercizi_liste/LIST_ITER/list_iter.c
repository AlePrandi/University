#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct listNode ListNode, *ListNodePtr;

struct listNode {
   int data;
   ListNodePtr next;
};

// Ritorna una lista contenente tutti i numeri interi 
// compresi tra @m ed @n, estremi inclusi. 
ListNodePtr fromTo_iter(int m, int n){
    ListNodePtr lista = NULL;
    for(int i = n; i >= m; i--){
        ListNodePtr node = (ListNodePtr)malloc(sizeof(ListNode));
        node->data = i;
        node->next = lista;
        lista = node;
    }

    return lista;
}

// Toglie tutte le occorrenze di @x dalla lista *@p_ls  (modifica *@p_ls).
void remove_all_iter(ListNodePtr *p_ls, int x){
    ListNodePtr curr, prev = NULL, temp;
    curr = *p_ls;
    while(curr){
        if(curr->data == x){

            if(prev) prev->next = curr->next;
            else *p_ls = curr->next;

            temp = curr;
            curr = curr->next;
            free(temp);
        }else{
            prev = curr;
            curr = curr->next;
        }
    }
}

void remove_all_rec(ListNodePtr *p_ls, int x){
    ListNodePtr l, temp;
    l = *p_ls;
    if(l){
        remove_all_rec(&(l->next), x);
        if(l->data == x){
            temp = l;
            *p_ls = l->next;
            free(temp);
        }
    }
}

// Ritorna una nuova lista con gli elementi di @ls 
// in ordine inverso (non modifica la lista @ls).
ListNodePtr reverse_iter(ListNodePtr ls){
    ListNodePtr lista = NULL;
    while(ls){
        ListNodePtr node = (ListNodePtr)malloc(sizeof(ListNode));
        node->data = ls->data;
        node->next = lista;
        lista = node;

        ls = ls->next;
    }

    return lista;
}

ListNodePtr reverse_rec(ListNodePtr ls){ //DIFFICILE
    if(ls){
        ListNodePtr temp, curr, node;
        node = (ListNodePtr) malloc(sizeof(ListNode));
        node->data = ls->data;
        node->next = NULL;

        if(ls->next){
            temp = reverse_rec(ls->next);
        }
    }
}

ListNodePtr crealista(int* arr, int len){
    ListNodePtr node;
    ListNodePtr lista = NULL;
    for(int i = len - 1;i >= 0;i--){
        node = (ListNodePtr)malloc(sizeof(ListNode));
        node->data = arr[i];
        node->next = lista;
        lista = node;
    }

    return lista;
}

// Ritorna la lista i cui elementi sono le somme a coppie degli elementi 
// corrispondenti di due liste @ls1 e @ls2 di uguale lunghezza 
// (non modifica la liste @ls1 e @ls2).
ListNodePtr zipSum_iter(ListNodePtr ls1, ListNodePtr ls2){
    ListNodePtr lista;
    while(ls1 && ls2){
        ListNodePtr node = (ListNodePtr)malloc(sizeof(ListNode));
        node->data = ls1->data + ls2->data;
        node->next = lista;
        lista = node;

        ls1 = ls1->next;
        ls2 = ls2->next;
    }

    return lista;
}

// Ritorna true se tutti gli elementi nella lista @ls1 compaiono
// nello stesso ordine anche nella lista @ls2.
_Bool included_iter(ListNodePtr ls1, ListNodePtr ls2){
    bool tro = true;
    while(ls1 && tro){
        tro = false;
        while(ls2 && !tro){
            if(ls1->data == ls2->data)
                tro = true;

            ls2 = ls2->next;
        }
        ls1 = ls1->next;
    }

    return tro;
}

// Conta il numero di occorrenze di @x nella lista @ls.
int occurrences_iter(ListNodePtr ls, int x){
    int cont = 0;
    while(ls){
        if(ls->data == x)
            cont++;

        ls = ls->next;
    }

    return cont;
}

// Duplica tutti i nodi della lista @ls 
//  che contengono un numero pari (modifica @ls).
void duplicate_even_iter(ListNodePtr *ls){
    ListNodePtr curr, prev = NULL;
    curr = *ls;
    while(curr){
        if(curr->data % 2 == 0){
            ListNodePtr node = (ListNodePtr)malloc(sizeof(ListNode));
            node->data = curr->data;
            node->next = curr;

            if(prev)prev->next = node;
            else *ls = node;

            prev = curr;
            curr = curr->next;
        }else{
            prev = curr;
            curr = curr->next;
        }
    }
}

void stampalista(ListNodePtr l){
    printf("Lista: \n");
    while(l){
        printf("%d ", l->data);
        l = l->next;
    }
    puts("");
}

void freelistaRec(ListNodePtr l){
    if(l){
        freelista(l->next);
        free(l);
    }
}

void freelistaIter(ListNodePtr l){
    ListNodePtr temp;
    while(l){
        temp = l;
        l = l->next;
        free(temp);
    }
}

int main(){

    int v[] = {1,2,3,4,5,6,7,8,9,0};
    ListNodePtr l1 = crealista(v, sizeof(v)/sizeof(int)), l2;
    stampalista(l1);
    l2 = reverse_iter(l1);
    stampalista(l2);

    remove_all_iter(&l1, 5);
    stampalista(l1);

    remove_all_rec(&l1, 6);
    stampalista(l1);

    freelistaRec(l1);
    freelistaIter(l2);
    return 0;
}