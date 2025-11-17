#include <stdio.h>

int potenza(int num, int num2);

int main(void){
    int num1, num2;
    printf("Inserisci un numero e l'esponente: ");
    scanf("%d %d", &num1, &num2);
    int pot = potenza(num1, num2);
    printf("La potenza %d^%d e': %d \n", num1, num2, pot);
    return 0;
}

int potenza(int num, int num2){
    int ret = 0;
    if(num2 == 0){
        ret = 1;
    }else{
        ret = num * potenza(num, num2 -1);
    }
    return ret;
}