#include <stdio.h>
#include "ram.h"
/**
* @brief Crea una struttura RAM con una certa quantità di memoria  
* @param M la quantità di memoria voluta, espressa in KB (deve essere una potenza di 2, maggiore o uguale a 1)
* @return Il puntatore alla struttura creata, oppure NULL in caso di errore
*/
RAM initram(int M) {
    if(M <= 0 || (M & (M - 1)) != 0) return NULL;
    RAM newRam = (RAM)malloc(sizeof(struct nodo));
    if(!newRam) return NULL;
    newRam->KB = M;
    newRam->parent = NULL;
    newRam->lbuddy = NULL;
    newRam->rbuddy = NULL;
    newRam->s = LIBERO;

    return newRam;
}


/**
* @brief Tenta di allocare una data quantità di memoria entro una RAM
* @param K la quantità di memoria richiesta, in KB
* @param ram la RAM entro cui cercare la memoria richiesta
* @return Il puntatore al nodo che può ospitare la quantità richiesta, oppure NULL se non trovato
*/
RAM allocram(int K, RAM ram){
    if(!ram || K<= 0 || K > ram->KB || ram->s == OCCUPATO) return NULL;
    if(K == ram->KB || K > ram->KB/2){
        if(ram->s == LIBERO){
            ram->s = OCCUPATO;
            return ram;
        }
        return NULL;
    }
    
    if(ram->s == LIBERO){
        ram->lbuddy = initram(ram->KB/2);
        ram->rbuddy = initram(ram->KB/2);
        
        if(!ram->lbuddy || !ram->rbuddy){
            free(ram->lbuddy);
            free(ram->rbuddy);
            ram->lbuddy = ram->rbuddy = NULL;
            return NULL;
        }
        
        ram->s = INTERNO;
        ram->lbuddy->parent = ram->rbuddy->parent = ram;
    }
    
    RAM allocato = allocram(K, ram->lbuddy);
    if(!allocato) allocato = allocram(K, ram->rbuddy);
    return allocato;
}


/**
* @brief Libera un nodo RAM precedentemente ottenuto con allocram    
* @param ram il nodo RAM da liberare
* @return Il successo della operazione
*/
Risultato deallocram(RAM ram) {
    if(ram == NULL || ram->s != OCCUPATO) return NOK;
    ram->s = LIBERO;
    RAM parent = ram->parent;
    if(parent == NULL) return OK;
    if(parent->lbuddy->s == LIBERO && parent->rbuddy->s == LIBERO){
        parent->s = OCCUPATO;
        free(parent->lbuddy);
        free(parent->rbuddy);
        parent->lbuddy = parent->rbuddy = NULL;
        deallocram(parent);
    }
    return OK;
}


/**
* @brief calcola il numero di KB di memoria ancora liberi all'interno di una struttura RAM    
* @param ram la struttura RAM 
* @return La quantità di memoria libera, oppure -1 in caso di errore
*/
int numfree(RAM ram){
    if(!ram) return -1;
    if(ram->s == LIBERO) return ram->KB;
    if(ram->s == OCCUPATO) return 0;
    
    return numfree(ram->lbuddy) + numfree(ram->rbuddy);
}


int contaChar(int num){
    int count = 0; 
    while(num > 0){
        num = num/10;
        count++;
    }
    return count;
}

int lenTree(RAM ram){
    if(ram == NULL) return 0;
    if(ram->s != INTERNO) return 1;
    // 3 perchè '0' + ':' + ',' nel caso di nodo interno
    return 3 + lenTree(ram->lbuddy) + lenTree(ram->rbuddy);
}

int appendBuddies(char *s, RAM ram, int i){
    if(ram == NULL) return i;
    if(ram->s == INTERNO){
        s[i++] = '0';
        s[i++] = ':';
        i = appendBuddies(s, ram->lbuddy, i);
        s[i++] = ',';
        i = appendBuddies(s, ram->rbuddy, i);
    } else {
        s[i++] = (char)(ram->s + '0');
    }
    return i;
}

/**
* @brief crea una rappresentazione dello stato interno della RAM sotto forma di una stringa (in un formato a piacere, 
* purchè completo di tutte le informazioni, ovvero tale che si possa ricreare dalla stringa esattamente lo stesso stato)
* @param ram la struttura RAM di cui creare la stringa
* @return la stringa creata, vuota in caso di RAM nulla o errore
*/
char* ram2str(RAM ram) {
    if(ram == NULL) {
        char *empty = malloc(1);
        if(empty) empty[0] = '\0';
        return empty;
    }
    
    int firstChars = contaChar(ram->KB);
    int lenStr = firstChars + lenTree(ram) + 2; 
    char *stringa = malloc(lenStr); 
    if(!stringa) {
        char *empty = malloc(1);
        if(empty) empty[0] = '\0';
        return empty;
    }

    int temp = ram->KB;
    for(int j = firstChars - 1; j >= 0; j--){
        stringa[j] = (temp % 10) + '0';
        temp /= 10;
    }
    stringa[firstChars] = ';';
    
    int finalPos = appendBuddies(stringa, ram, firstChars + 1);
    stringa[finalPos] = '\0';
    
    return stringa;
}

char* appendChild(char *str, RAM ram){
    if(*str == '\0' || ram == NULL) return str;

    if(*str == '0'){
        ram->s = INTERNO;
        str++; // salta '0'
        if(*str == ':') str++; // salta ':'
        
        ram->lbuddy = initram(ram->KB / 2);
        ram->rbuddy = initram(ram->KB / 2);
        
        ram->lbuddy->parent = ram->rbuddy->parent = ram;
        
        str = appendChild(str, ram->lbuddy);
        
        if(*str == ',') str++; // salta la virgola tra i figli
        
        str = appendChild(str, ram->rbuddy);
    } 
    else if(*str == '1'){
        ram->s = LIBERO;
        str++;
    } 
    else if(*str == '2'){
        ram->s = OCCUPATO;
        str++;
    }
    return str;
}


/**
* @brief ricostruisce una struttura RAM a partire dalla sua rappresentazione sotto forma di stringa creata da ram2str 
* @param s  la stringa che contiene la rappresentazione della RAM, eventualmente vuota
* @return la RAM creata, oppure NULL in caso di errore o stringa vuota
*/
RAM str2ram(char *str){
    if(str == NULL || *str == '\0') return NULL;
    
    int ramCap = 0;
    char *p = str;
    while(*p != ';' && *p != '\0'){
        ramCap = (ramCap * 10) + (*p - '0');
        p++;
    }
    
    if(*p == ';') p++; 

    RAM ram = initram(ramCap);
    if(!ram) return NULL;
    
    appendChild(p, ram);
    return ram;
}

/**
* @brief cancella dallo heap la struttura dati di un nodo RAM e di tutti i suoi figli  
* @param ram il nodo RAM da cancellare
* @return Restituisce OK se la funzione ha effettivamente liberato della memoria, NOK altrimenti
*/
Risultato freeram(RAM* ramptr){
    if(!ramptr || !*ramptr) return NOK;
    freeram(&(*ramptr)->lbuddy);
    freeram(&(*ramptr)->rbuddy);
    free(*ramptr);
    *ramptr = NULL;
    return OK;
}