#include <stdio.h>

int moltiplicazione(int num, int num2);

int main(void){
    int num1, num2;
    printf("Inserisci due numeri da moltiplicare: ");
    scanf("%d %d", &num1, &num2);
    int molt = moltiplicazione(num1, num2);
    printf("La moltiplicazione di %d e %d viene: %d \n", num1, num2, molt);
    return 0;
}

int moltiplicazione(int num, int num2){
    int ret = 0;
    if(num2 == 1){
        ret = num;
    }else{
        ret = num + moltiplicazione(num, num2 -1);
    }
    return ret;
}