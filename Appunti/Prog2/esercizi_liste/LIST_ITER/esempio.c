#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct listNode ListNode, *ListNodePtr;

struct listNode {
   int data;
   ListNodePtr next;
};

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

void remove_all_iter_rec(ListNodePtr *p_ls, int x){
    ListNodePtr l, temp;
    l = *p_ls;
    if(l){
        remove_all_iter_rec(&(l->next), x);
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

void stampalista(ListNodePtr l){
    printf("Lista: \n");
    while(l){
        printf("%d ", l->data);
        l = l->next;
    }
    puts("");
}

void freelista(ListNodePtr l){
    if(l){
        freelista(l->next);
        free(l);
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

    remove_all_iter_rec(&l1, 6);
    stampalista(l1);

    freelista(l1);
    freelista(l2);
    return 0;
}