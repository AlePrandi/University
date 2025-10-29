#include <stdio.h>

int main(){

    int n = 5;
    int numero = 1;

    //int cont = 1;
    //int max = n*(n/2 + 1);
    // for(int i = 0; i < max; i++){
    //     printf("%d ", numero);
    //     if(numero == cont*(cont + 1)/2){
    //         printf("\n");
    //         cont++;
    //     }
    //     numero++;
    // }


    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++){
            printf("%d ", numero);
            numero++;
        }
        printf("\n");
    }
    return 0;
}