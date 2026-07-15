#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct contact ContactNode, *Contact;
typedef struct list ListNode, *List;

struct contact{
    char *nome;
    long int numero;
};

struct list{
    Contact contatto;
    List next;
};

typedef List Rubrica[10];

int sumValue(long int val){
    int sum = 0;
    int base = 10;
    int cifra = 0;
    while(val != 0){
        cifra = val % base;
        val -= cifra;
        val = val/base;
        sum += cifra;
    }

    return sum;
}

/**
 * @brief funzione che calcola l'hash a partire dal numero di telefono
 */
size_t hashNumber(long int cell){
    long int hash = cell;
    while(hash > 9)
        hash = sumValue(hash);

    return (size_t)hash;
}

List aggiungiElemento(List head, Contact cont){

    List curr = head;
    List prec = NULL;
    List newContact = (List)malloc(sizeof(List));
    newContact->contatto = cont;
    newContact->next = NULL;
    
    while(curr){
        if(curr->contatto->numero == cont->numero){
            curr->contatto->nome = cont->nome;
            free(newContact);
            return head;
        }
        prec = curr;
        curr = curr->next;
    }

    if(prec){
        prec->next = newContact;
        newContact->next = curr;
    }else{
        newContact->next = head;
        head = newContact;
    }

    return head;
}

List rimuoviElemento(List head, Contact cont){
    List prec = NULL;
    List curr = head;
    while(curr){
        if(curr->contatto->numero == cont->numero){
            if(prec)
                prec->next = curr->next;
            else
                head = curr->next;

            List temp = curr;
            curr = curr->next;
            free(temp);
        }else{
            prec = curr;
            curr = curr->next;
        }
    }

    return head;
}

void printRubrica(Rubrica r){
    for(size_t i = 0; i < 10; i++){
        printf("Hash %zu:\n", i);
        List curr = r[i];
        while(curr){
            printf("\t Nome: %s Telefono: %ld \n", curr->contatto->nome, curr->contatto->numero);
            curr = curr->next;
        }
    }
}

/**
 * @brief funzione che inserisce il contatto nella Rubrica
 */
void InserisciInRubrica(Rubrica r, Contact cont){
    size_t index = hashNumber(cont->numero);
    r[index] = aggiungiElemento(r[index], cont);
}

/**
 * @brief rimuove un contatto dalla lista
 */
void RimuoviDaRubrica(Rubrica r, Contact cont){
    size_t index = hashNumber(cont->numero);
    r[index] = rimuoviElemento(r[index], cont);
}

int main(void){
    Rubrica rubrica = {NULL};
    ContactNode contact[4] = {
        {.nome = "Pino", .numero = 3432},
        {.nome = "Mario", .numero = 3432},
        {.nome = "Gianni", .numero = 5430},
        {.nome = "Carla", .numero = 1256},
    };

    for(size_t i = 0; i < 4; i++)
        InserisciInRubrica(rubrica, &contact[i]);

    printRubrica(rubrica);
    
    RimuoviDaRubrica(rubrica, &contact[2]);
    printRubrica(rubrica);

    return 0;
}