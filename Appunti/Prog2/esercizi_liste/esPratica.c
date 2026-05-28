#include <stdio.h>
#include <stdlib.h>
#include "esPratica.h"

void reverse (IntList *plst) {
    if(!plst || !(*plst)) return;
    IntList curr = *plst, inv = NULL;
    while(curr){
        IntList temp = curr;
        curr = curr->next;
        
        temp->next = inv;
        inv = temp;
    }
    *plst = inv;
    return;
}


IntList reverse_rec(IntList head){
    if(!head || !head->next) return head;
    
    IntList newHead = reverse_rec(head->next);
    
    head->next->next = head;
    head->next = NULL;
    
    return newHead;
}

void reverse (IntList *plst) {
    *plst = reverse_rec(*plst);
}


List divisorList(int num, int i){
    if(i > num) return NULL;
    if(num % i == 0){
        List node = malloc(sizeof(ListNode));
        if(!node) return NULL;
        node->data = i;
        node->next = divisorList(num, i+1);
        return node;
    }
    return divisorList(num, i+1);
}

int main(void){

    return 0;
}