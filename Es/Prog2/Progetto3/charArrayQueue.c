#include "./charArrayQueue.h"
#include <stdlib.h>
#include <math.h>

/* @brief Restituisce una coda vuota, se non trova memoria restituisce NULL */
CharQueueADT mkQueue(){
    CharQueueADT coda = (CharQueueADT)malloc(sizeof(struct charQueue));
    if (!coda) return NULL;
    coda->capacity = INITIAL_CAPACITY * pow(2, 0);
    coda->a = malloc(sizeof(char) * coda->capacity);
    coda->size = 0;
    coda->front = 0;
    coda->rear = 0;

    return coda;
}

/* @brief Distrugge la coda, recuperando la memoria */
void dsQueue(CharQueueADT *pq){
    free((*pq)->a);
    (*pq)->a = NULL;
    free(*pq);
    *pq = NULL;
}

/* @brief Aggiunge un elemento in fondo alla coda, restituisce esito 0/1 */
_Bool enqueue(CharQueueADT q, const char e){
    if (!q) return 0;

    if (q->rear < q->capacity){   
        int coda = q->rear % q->capacity;
        q->a[coda] = e;
        q->size++;
        q->rear = (q->rear + 1) % q->capacity;

        if (q->size == q->capacity - 1){
            int newCap = q->capacity * 2;
            char* temp = malloc(sizeof(char) * newCap);
            for (size_t i = 0; i < q->size; i++){
                temp[i] = q->a[(q->front + i) % q->capacity];
            }
            free(q->a);
            q->a = temp;
            q->front = 0;
            q->capacity *= 2;
            q->rear = q->size;
        }
        return 1;
    }
    return 0;
}

/* @brief Toglie e restituisce l'elemento in testa alla coda, restituisce esito 0/1 */
_Bool dequeue(CharQueueADT q, char *res){
    if (!q || q->size == 0) return 0;

    int testa = q->front % q->capacity;
    *res = q->a[testa];
    q->a[testa] = '\0';
    q->front = (q->front + 1) % q->capacity;
    q->size--;

    if (q->capacity > INITIAL_CAPACITY && q->size == q->capacity / 4){
        int newCap = q->capacity / 2;
        char *temp = malloc(sizeof(char) * newCap);
        for (size_t i = 0; i < q->size; i++){
            temp[i] = q->a[(q->front + i) % q->capacity];
        }
        free(q->a);
        q->a = temp;
        q->capacity /= 2;
        q->front = 0;
        q->rear = q->size;
    }

    return 1;
}

/* @brief Controlla se la coda è vuota */
_Bool isEmpty(CharQueueADT q){
    if (!q) return 0;
    return (q->size == 0) ? 1 : 0;
    // return(q) ? ((q->size == 0) ? 1 : 0) : 0;
}

/* @brief Restituisce il numero degli elementi presenti nella coda */
int size(CharQueueADT q){
    return (q) ? q->size : 0;
}

/* @brief Restituisce l'elemento nella posizione data (a partire dalla testa con indice zero) (senza toglierlo), restituisce esito 0/1 */
_Bool peek(CharQueueADT q, int position, char *res){
    if (!q || q->size <= 0) return 0;
    if (position < q->size){
        *res = q->a[(q->front + position) % q->capacity];
        return 1;
    }
    return 0;
}