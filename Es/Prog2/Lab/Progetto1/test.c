/* INSERIRE QUI EVENTUALI ALTRI #include <...> */
/* INSERT HERE MORE #include <...> IF NEEDED */
#include <stdio.h>
#include "stoib.h"


/**
 * Invoca la funzione stoib su uno o più casi a scelta, controllando che
 * il suo effetto come risultato e argomenti rispetti la specifica corretta.
 * Può essere sufficiente anche un unico caso, se sufficientemente generale per
 * individuare quali programmi sono corretti e quali no.
 * Se la funzione è corretta, come ultima cosa deve stampare "TEST PASSED\n".
 * Se invece la funzione non risulta corretta, deve stampare "TEST FAILED\n".
 * NON STAMPARE ALTRO SU STANDARD OUTPUT.
 * Se avete necessità di fare stampe di debug, potete farle su standard error.
 *
 * NOTA: questa funzione compare negli errori di compilazione come "student_main"
 * NOTA: il main viene testato indipendentemente dalla vostra funzione stoib
 * IMPORTANTE: cercate sempre di far compilare il vostro codice per poter vedere il
 * risultato dei test, anche a costo di commentare parte del codice di questa funzione
 *
 * <ENGLISH VERSION>
 *
 * Invokes the stoib function on one or more selected test cases, checking
 * that its effect as result and arguments respects the correct specification.
 * A single test case may be enough, if it sufficiently general to single out
 * which programs are correct and which are not.
 * If the function is correct, as the final step it must print "TEST PASSED\n".
 * If instead the function is not correct, it must print "TEST FAILED\n".
 * DO NOT PRINT ANYTHING ELSE ON STANDARD OUTPUT.
 * If you need to print debug information, use standard error.
 *
 * NOTE: this function appears in compilation errors as "student_main"
 * NOTE: the main is tested independently of your stoib function
 * IMPORTANT: always try to make your code compile so that you can see the test
 * results, even if that means commenting out part of the code of this function
 */
int main() {
    
    int ok = 1;
    int res = 0;
    
    //stringa vuota
    int n = stoib("", 10, &res);
    if (n != 0) ok = 0;
    
    //res NULL
    res = 0;
    n = stoib("+4", 10, NULL);
    if(n != 0) ok = 0;
    
    //stringa NULL
    res = 0;
    n = stoib(NULL, 10, &res);
    if(n != 0) ok = 0;
    
    //base non valida
    res = 0;
    n = stoib("-19", 1, &res);
    if(n != 0) ok = 0;
    
    res = 0;
    n = stoib("5", 37, &res);
    if(n != 0) ok = 0;
    
    //spazi bianchi
    res = 0;
    n = stoib("\t-35", 10, &res);
    if(n != 4 || res != -35) ok = 0;
    res = 0;
    n = stoib("   +14", 10, &res);
    if(n != 6 || res != 14) ok = 0;
    res = 0;
    n = stoib("\n-2", 10, &res);
    if(n != 3 || res != -2) ok = 0;
    
    //caratteri non validi
    res = 0;
    n = stoib("-9A13", 10, &res);
    if(n != 2 || res != -9) ok = 0;
    res = 0;
    n = stoib("a", 10, &res);
    if(n != 0) ok = 0;
    
    //nessun carattere valido
    res = 0;
    n = stoib("ABC", 8, &res);
    if(n != 0) ok = 0;
    
    //conta caratteri se inclusi nella base
    res = 0;
    n = stoib("1C", 16, &res);
    if(n != 2 && res != 28) ok = 0;

    
    if(ok){
        printf("TEST PASSED\n");
    }else{
        printf("TEST FAILED\n");
    }
    
    return 0;
}
