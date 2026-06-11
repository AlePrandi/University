typedef struct listNode ListNode, *List;

struct listNode{
    int data;
    List next;
};

/**
 * @brief Funzione che dato un numero ne trova i divisori a partire dall'indice i
 * @param num il numero di cui bisogna trovare i divisori
 * @param i indice su cui scorrere 
 * @return Una lista con all'interno i divisori del numero
 */
List divisorList(int num, int i);