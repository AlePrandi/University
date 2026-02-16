#include <stdio.h>

int sommatoria(int num);

int main(void){

    int n;
    printf("Inserire un numero per la sommatoria da 1 a N: ");
    scanf("%d", &n);
    int somma = sommatoria(n);
    printf("La sommatoria di %d e': %d ", n, somma);
    return 0;
}

int sommatoria(int num){
    int ret = 0;
    if(num == 0){
        ret = num;
    }else{
        ret = num + sommatoria(num - 1);
    }
    return ret;
}