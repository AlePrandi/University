#include <stdio.h>
#include <stdlib.h>

typedef struct listNode ListNode, *List;
struct listNode {
    int data;
    List next;
};

void freeList(List l){
    if(!l) return;
    freeList(l->next);
    free(l);
    printf("free\n");
}

List creaNodo(int val){
    List newNode = (List)malloc(sizeof(ListNode));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

int checklist(List ret, int n, int exp[]){
    for(int i = 0;i < n; i++){
        if(!ret || ret->data != exp[i]) return 0;
        ret = ret->next;
    }
    return 1;
}

/**
 * @brief date due liste *lsPtr1 e *lsPtr2 le unisce in modo ordinato
 * es. date [1,5,9] e [0,2,4,6,8] ret = [0,1,2,4,5,6,8,9]
 * implementazione ITERATIVA
 */
List merge(List *lsPtr1, List *lsPtr2){
    List head = NULL;
    List tail = NULL;
    List curr1 = *lsPtr1;
    List curr2 = *lsPtr2;

    while(curr1 && curr2){
        List next1 = curr1->next;
        List next2 = curr2->next;
        if(curr1->data <= curr2->data){
            if(!head){
                head = curr1;
            }else{
                tail->next = curr1;
            }
            tail = curr1;
            curr1 = next1;
        }else{
            if(!head){
                head = curr2;
            }else{
                tail->next = curr2;
            }
            tail = curr2;
            curr2 = next2;
        }
    }

    while(curr1){
        if(!head){
            head = curr1;
        }else{
            tail->next = curr1;
        }
        tail = curr1;
        curr1 = curr1->next;
    }

    while(curr2){
        if(!head){
            head = curr2;
        }else{
            tail->next = curr2;
        }
        tail = curr2;
        curr2 = curr2->next;
    }

    return head;
}

int main(void){

    List l1 = creaNodo(1);
    l1->next = creaNodo(5);
    l1->next->next = creaNodo(9);

    List l2 = creaNodo(0);
    l2->next = creaNodo(2);
    l2->next->next = creaNodo(6);

    printf("%d\n", l1->next->next->data);

    #define N 6
    int exp[N] = {0,1,2,5,6,9};

    List ret = merge(&l1, &l2);

    if(checklist(ret, N, exp)){
        printf("TEST PASSED\n");
    }else{
        printf("TEST FAILED\n");
    }

    freeList(ret);

    ret=l1=l2=NULL;
    
    return 0;
}