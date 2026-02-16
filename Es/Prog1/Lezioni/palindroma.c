#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 50

bool wrap_pal(const char st[]);
bool epal(size_t left, size_t right, const char st[]);

int main(void){
     
    char stringa[MAX_LEN];
    printf("Inserisci una stringa: \n");
    scanf("%50s", stringa);

    if(wrap_pal(stringa)){
        printf("la stringa '%s' e' palindroma.");
    }else{
        printf("La stringa '%s' non e' palindroma.");
    }

    return 0;
}

bool wrap_pal(const char st[]){
    return epal(0, strlen(st), st);
}

bool epal(size_t left, size_t right, const char st[]){
    if(left >= right){
        return true;
    }else{
        if(tolower(st[left]) != tolower(st[right - 1])){
            return false;
        }else{
            if(!isalpha(st[left])){
                return epal(left + 1, right, st);
            }else{
                if(!isalpha(st[right - 1])){
                    return epal(left, right - 1, st);
                }else{
                    return epal(left + 1, right - 1, st);
                }
            }
        }
    }
}