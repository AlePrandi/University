#include "./linkedListQueue.h"
#include "./charQueueADT.h"
#include <stdlib.h>
#include <math.h>

/* @brief Restituisce una coda vuota, se non trova memoria restituisce NULL */
CharQueueADT mkQueue(){
    CharQueueADT lista = malloc(sizeof(CharQueueADT));
    if(!lista) return NULL;

    lista->front = malloc(sizeof(ListNode));
    lista->rear = malloc(sizeof(ListNode));

    lista->front->data = 0;
    lista->rear->data = 0;

    lista->front->next = NULL;
    lista->rear->next = NULL;

    return lista;
}

/* @brief Distrugge la coda, recuperando la memoria */
void dsQueue(CharQueueADT *pq){
    if(!pq || !(*pq)) return;
    while((*pq)->front){
        ListNodePtr temp = (*pq)->front;
        (*pq)->front = (*pq)->front->next;
        free(temp);
        temp = NULL;
    }

    free((*pq));
    (*pq) = NULL;
}


/* @brief Aggiunge un elemento in fondo alla coda, restituisce esito 0/1 */
_Bool enqueue(CharQueueADT q, const char e){
    if(!q) return 0;
    ListNodePtr newNode = (ListNodePtr)malloc(sizeof(ListNode));
    if(!newNode) return 0;
    newNode->data = e;
    newNode->next = NULL;

    if(!q->front){
        q->front = newNode;
        q->rear = newNode;
    }else{
        q->rear->next = newNode;
        q->rear = newNode;
    }
    return 1;
}

/* @brief Toglie e restituisce l'elemento in testa alla coda, restituisce esito 0/1 */
_Bool dequeue(CharQueueADT q, char*res){
    if(!q || !q->front) return 0;
    *res = q->front->data;
    ListNodePtr temp = q->front;
    q->front = q->front->next;

    if(q->front == NULL) q->rear = NULL;

    free(temp);
    temp = NULL;

    return 1;
}

/* @brief Controlla se la coda è vuota */
_Bool isEmpty(CharQueueADT q){
    return q ? (q->front ? 0 : 1) : 1;
}

/* @brief Restituisce il numero degli elementi presenti nella coda */
int size(CharQueueADT q){
    if(!q || !q->front) return 0;
    int sz = 0;
    while(q->front){
        sz++;
        q->front = q->front->next;
    }
    return sz;
}
