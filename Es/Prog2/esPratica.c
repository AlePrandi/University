#include <stdio.h>
#include <stdlib.h>

typedef struct list List, *ListPtr;

struct list{
    int data;
    ListPtr next;
};

void reverse (ListPtr *plst) {
    if(!plst || !(*plst)) return;
    ListPtr curr = *plst, inv = NULL;
    while(curr){
        ListPtr temp = curr;
        curr = curr->next;
        
        temp->next = inv;
        inv = temp;
    }
    *plst = inv;
    return;
}


ListPtr reverse_rec(ListPtr head){
    if(!head || !head->next) return head;
    
    ListPtr newHead = reverse_rec(head->next);
    
    head->next->next = head;
    head->next = NULL;
    
    return newHead;
}

void reverse (ListPtr *plst) {
    *plst = reverse_rec(*plst);
}


ListPtr divisorList(int num, int i){
    if(i > num) return NULL;
    if(num % i == 0){
        ListPtr node = malloc(sizeof(List));
        if(!node) return NULL;
        node->data = i;
        node->next = divisorList(num, i+1);
        return node;
    }
    return divisorList(num, i+1);
}

ListPtr *invertiLista(ListPtr *lPtr){
    if(!lPtr || !(*lPtr)) return NULL;
    if(!(*lPtr)->next) return lPtr;
    
}

int main(void){

    return 0;
}