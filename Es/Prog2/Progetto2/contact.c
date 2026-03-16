#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "contact.h"


/* INSERIRE QUI EVENTUALI ALTRI #include <...> */

/* INSERIRE QUI EVENTUALI FUNZIONI AUSILIARIE */

/**

 * @brief Controlla se due contatti hanno lo stesso nome e cognome.
 * Restituisce:
 * - 1 se i due contatti sono uguali, 0 se sono diversi, -99 se qualche name o surname è NULL
 *
 * @param c1 primo contatto.
 * @param c2 secondo contatto.
 * @return  1, 0, o -99.
 */
int contactEq(Contact c1, Contact c2) {
    return contactEqEff(&c1, &c2);
}


/**
 * Invoca la funzione contactEq su uno o più casi a scelta, controllando che
 * il suo effetto come risultato e argomenti rispetti la specifica corretta.
 * Può essere sufficiente anche un unico caso, se sufficientemente generale per
 * individuare quali programmi sono corretti e quali no.
 * Se la funzione è corretta, come ultima cosa deve stampare "TEST PASSED\n".
 * Se invece la funzione non risulta corretta, deve stampare "TEST FAILED\n".
 *
 * NOTA: questa funzione compare negli errori di compilazione come "student_main"
 */
int test_contactEq() {
    int ok = 1;
    Contact c1, c2;

    // TEST diversi
    c1.name = "Pippo";
    c1.surname = "Pluto";

    c2.name = "Paperino";
    c2.surname = "Pluto";

    if(contactEq(c1, c2) != 0)
        ok = 0;

    //TEST uguali
    c2.name = "Pippo";
    c2.surname = "Pluto";
    if(contactEq(c1, c2) != 1)
        ok = 0;

    //TEST null
    c2.name = NULL;
    c2.surname = "Pluto";
    if(contactEq(c1, c2) != -99)
        ok = 0;

    if(ok)
        printf("TEST PASSED\n");
    else
        printf("TEST FAILED \n");
    
    return 0; 
}


// come per contactEq

int contactEqEff(const Contact *pc1, const Contact *pc2) {
    if(!pc1->name || !pc1->surname || !pc2->name || !pc2->surname)
        return -99;
    
    size_t i = 0;
    while(pc1->surname[i] != '\0' || pc2->surname[i] != '\0'){
        if(tolower(pc1->surname[i]) != tolower(pc2->surname[i]))
            return 0;
        i++;
    }

    // controllo se uno è terminatore e l'altro no
    if(tolower(pc1->surname[i]) != tolower(pc2->surname[i]))
        return 0;

    i = 0;
    while(pc1->name[i] != '\0' || pc2->name[i] != '\0'){
        if(tolower(pc1->name[i]) != tolower(pc2->name[i]))
            return 0;
        i++;
    }

    // controllo se uno è terminatore e l'altro no
    if(tolower(pc1->name[i]) != tolower(pc2->name[i]))
        return 0;

    return 1;
}


// come per test_contactEq

int test_contactEqEff() {
    int ok = 1;
    Contact *c1, *c2;

    // TEST diversi
    c1->name = "Pippo";
    c1->surname = "Pluto";

    c2->name = "Paperino";
    c2->surname = "Pluto";

    if(contactEqEff(c1, c2) != 0)
        ok = 0;

    //TEST uguali
    c2->name = "Pippo";
    c2->surname = "Pluto";
    if(contactEqEff(c1, c2) != 1)
        ok = 0;

    //TEST null
    c2->name = NULL;
    c2->surname = "Pluto";
    if(contactEqEff(c1, c2) != -99)
        ok = 0;

    if(ok)
        printf("TEST PASSED\n");
    else
        printf("TEST FAILED \n");

    return 0;
}


// come per contactEq

int contactCmp(Contact c1, Contact c2) {
    return contactCmpEff(&c1, &c2);
}


// come per test_contactEq

int test_contactCmp() {
    int ok = 1;
    Contact c1, c2;

    // TEST diversi
    c1.name = "Paperino";
    c1.surname = "Pluto";
    c2.name = "Pluto";
    c2.surname = "Pluto";
    if(contactCmp(c1, c2) != -1)
        ok = 0;


    c1.name = "Pippo";
    c1.surname = "Pluto";
    c2.name = "Carlo";
    c2.surname = "bruto";
    if(contactCmp(c1, c2) != 1)
        ok = 0;

    //TEST uguali
    c2.name = "Pippo";
    c2.surname = "Pluto";
    if(contactCmp(c1, c2) != 0)
        ok = 0;

    //TEST null
    c2.name = NULL;
    c2.surname = "Pluto";
    if(contactCmp(c1, c2) != -99)
        ok = 0;

    if(ok)
        printf("TEST PASSED\n");
    else
        printf("TEST FAILED \n");

    return 0;
}


// come per test_contactEq

int contactCmpEff(const Contact *pc1, const Contact *pc2) {
    if(!pc1->name || !pc1->surname || !pc2->name || !pc2->surname)
        return -99;

    size_t j = 0;
    while(pc1->surname[j] != '\0' || pc2->surname[j] != '\0'){
        if(tolower(pc1->surname[j]) == tolower(pc2->surname[j]))
            j++;
        else if(tolower(pc1->surname[j]) > tolower(pc2->surname[j])){
            return 1;
        }else{
            return -1;
        }
    }

    j = 0;
    while(pc1->name[j] != '\0' || pc2->name[j] != '\0'){
        if(tolower(pc1->name[j]) == tolower(pc2->name[j]))
            j++;
        else if(tolower(pc1->name[j]) > tolower(pc2->name[j])){
            return 1;
        }else{
            return -1;
        }
    }

    return 0;

}


// come per test_contactEq

int test_contactCmpEff() {

    int ok = 1;
    Contact *c1, *c2;

    // TEST diversi
    c1->name = "Pippo";
    c1->surname = "Pluto";

    c2->name = "Paperino";
    c2->surname = "Pluto";

    if(contactEqEff(c1, c2) != 0)
        ok = 0;

    //TEST uguali
    c2->name = "Pippo";
    c2->surname = "Pluto";
    if(contactEqEff(c1, c2) != 1)
        ok = 0;

    //TEST null
    c2->name = NULL;
    c2->surname = "Pluto";
    if(contactEqEff(c1, c2) != -99)
        ok = 0;

    if(ok)
        printf("TEST PASSED\n");
    else
        printf("TEST FAILED \n");

    return 0;
}

int main(void){
    int Eq = test_contactEq();
    int EqEff = test_contactEqEff();
    int Cmp = test_contactCmp();
    int CmpEff = test_contactCmpEff();

}