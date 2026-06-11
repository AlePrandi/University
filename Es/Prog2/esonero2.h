#include <stdio.h>
#include <stdlib.h>

typedef struct listNode ListNode, *List;

struct listNode{
    int data;
    List next;
};

/**
 * @brief Funzione che date due liste l1 e l2 ritorna una lista contenente i char di l1 
 * che non sono presenti in l2
 * @param l1 lista 1 su cui va fatto il controllo dell'univocità
 * @param l2 lista 2 i cui caratteri non devono essere presenti  
 * @return lista contenente i caratteri univoci di l1
 */
List prefix(List l1, List l2);