#include "stoib.h"

int stoib(char *s, unsigned short b, int *r) {

    if(!s || !r) return 0;
    
    int conta_c = 0;
    int segno = 1;
    int c_val = 0;
    int c = 0;
    *r = 0;
    
    if(b < 2 || b > 36) return 0;
    while(*s == ' ' || *s == '\t' || *s == '\n'){
        conta_c++;
        (s)++;
    }

    if(*s == '-' || *s == '+'){
        if(*s == '-')
            segno = -1;
        conta_c++;
        (s)++;
    }
    
    //fprintf(stderr, "");
    while(*s != '\0'){
        if(*s >= '0' && *s <= '9') 
            c = *s - '0';
        else if(*s >= 'A' && *s <= 'Z') 
            c = 10 + (*s - 'A');
        else
            break;

        if(c < b){
            *r = ((*r) * b) + c;
            c_val++;
        }else{
            break;
        }
         
        (s)++;
    }
    if(c_val < 1)
        conta_c = 0;
    else
        conta_c += c_val;
    *r *= segno;
    fprintf(stderr, "%s , %d , %d, %d", s, b, *r, conta_c);
    return conta_c;
}