#include <stdio.h>
#include <stdlib.h>

typedef struct listNode ListNode, *List;

struct listNode
{
    int data;
    List next;
};

List makeNode(char data)
{
    List node = malloc(sizeof(ListNode));
    node->data = data;
    node->next = NULL;
    return node;
}

void printList(List head)
{
    if (head == NULL)
    {
        puts("X");
        return;
    };

    printf("%c -> ", head->data);
    printList(head->next);
}

/**
 * Data una lista di caratteri *ptr e una stringa str, modificare *ptr nel
 * seguente modo. Per ogni carattere c in str, per ogni occorrenza di una
 * sequenza di almeno n > 1 nodi consecutivi contenenti il carattere c,
 * rimuovere da *ptr (e deallocare) tutti i nodi della sequenza tranne il primo.
 *
 * La funzione restituisce 0 se non ha modificato *ptr, 1 se lo ha modificato.
 * Non considera l'eventualità che la free fallisca.
 *
 * ESEMPI:
 * (1) data *prt == [A,B,B,A] ed s == "AB" restituisce 1 e causa *ptr = [A,B,A]
 * (2) data *ptr == NULL ed s == "AB" restituisce 0 e non modifica *ptr
 * (3) data *ptr == [A,B,B,A] ed s == "CD" restituisce 0 e non modifica *ptr
 * (4) data *ptr == [A,A,B,A] ed s == "AB" restituisce 1 e causa *ptr = [A,B,A]
 * (5) data *ptr == [A,A,A,B,B,A,A] ed s == "AB" restituisce 1 e causa *ptr =
 * [A,B,A]
 *
 * NOTA: questa funzione compare negli errori di compilazione come
 * "student_removeCharSeq" NOTA: viene controllato che questa funzione gestisca
 * correttamente la memoria NOTA: la funzione deve avere complessità
 * computazionale lineare in tempo e costante in spazio, rispetto alla lunghezza
 * della lista (considerando la stringa di lunghezza costante)
 */
int removeCharSeq(List *ptr, const char *str)
{
    int modified = 0;
    while (*str != '\0')
    {
        List curr = *ptr;
        List prec = NULL;
        int occ = 0;
        while (curr)
        {
            if (curr->data == *str)
            {
                occ++;
                if (occ > 1)
                {
                    modified = 1;
                    prec->next = curr->next;
                    List temp = curr;
                    curr = curr->next;
                    free(temp);
                }
            }
            else
            {
                occ = 0;
            }
            if (!(occ > 1 && modified))
            {
                prec = curr;
                curr = curr->next;
            }
        }
        str++;
    }
    return modified;
}

int main(void)
{
    List head = makeNode('A');
    head->next = makeNode('A');
    head->next->next = makeNode('A');
    head->next->next->next = makeNode('B');
    head->next->next->next->next = makeNode('B');
    head->next->next->next->next->next = makeNode('A');
    head->next->next->next->next->next->next = makeNode('A');

    char *str = "AB";

    int res = removeCharSeq(&head, str);

    printf("res: %d\nexpected: ABA\n", res);
    printList(head);
    return 0;
}