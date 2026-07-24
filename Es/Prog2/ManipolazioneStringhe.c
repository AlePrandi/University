#include <stdio.h>
#include <stdlib.h>

/* INSERIRE QUI EVENTUALI FUNZIONI AUSILIARIE (CON UN COMMENTO SIGNIFICATIVO IN TESTA) */
typedef struct node CharNode, *CharList;

struct node
{
    char data;
    CharList next;
};

/**
 * Data una lista di caratteri *ptr e una stringa str, modifica *ptr inserendo
 * un nodo nuovo per ciascun carattere di str. I nodi nuovi vanno inseriti dopo
 * la prima occorrenza del carattere 'Z' nella lista. Se 'Z' non occorre vanno
 * inseriti in coda alla lista. I nuovi nodi vanno inseriti nello stesso ordine
 * con cui si susseguono nella stringa.
 *
 * Non considera l'eventualità che la malloc fallisca.
 * Se ptr == NULL restituisce 0, altrimenti restituisce 1.
 * Se s == NULL o ptr == NULL, non modifica ptr.
 *
 * ESEMPI:
 * (1) data *ptr == [A,x,8] ed s == "k$2e" restituisce 1 e causa *ptr == [A,x,8,k,$,2,e]
 * (2) data ptr == NULL ed s == "Pluto" restituisce 0 e non modifica ptr
 * (3) data *ptr == [] ed s == "Pluto" restituisce 1 e causa *ptr == [P,l,u,t,o]
 * (4) data *ptr == [P,A,Z,Z,O] ed s == "Pluto" restituisce 1 e causa *ptr == [P,A,Z,P,l,u,t,o,Z,O]
 * (5) data *ptr == [p,a,z,z,o] ed s == "Pluto" restituisce 1 e causa *ptr == [p,a,z,z,o,P,l,u,t,o]
 * (6) data *ptr == [p,a,z,z,o] ed s == NULL restituisce 1 e non modifica ptr
 */
int insert(CharList *ptr, const char *s){
    if (!ptr) return 0;
    if (!s || s[0] == '\0') return 1;
    CharList prec = NULL;
    CharList curr = *ptr;
    while(curr)
    {
        if (curr->data == 'Z')
        {
            for (int i = 0; s[i] != '\0'; i++)
            {
                CharList newNode = (CharList)malloc(sizeof(CharNode));
                newNode->data = s[i];
                newNode->next = curr->next;
                curr->next = newNode;
                curr = newNode;
            }
            return 1;
        }
        prec = curr;
        curr = curr->next;
    }

    if (prec)
    {
        for (int i = 0; s[i] != '\0'; i++)
        {
            CharList newNode = (CharList)malloc(sizeof(CharNode));
            newNode->data = s[i];
            prec->next = newNode;
            newNode->next = curr;
            prec = newNode;
        }
    }else{
        CharList tail = NULL;
        for(int i = 0; s[i] != '\0'; i++){
            CharList newNode = (CharList)malloc(sizeof(CharNode));
            newNode->data = s[i];
            newNode->next = NULL; 

            if(!(*ptr)){
                (*ptr) = newNode;
            }else{
                tail->next = newNode;
            }
            tail = newNode;
        }
    }

    return 1;
}