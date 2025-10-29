#include <stdio.h>

int main(){
    int n = 5;
    int numero = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            printf("%d ", numero);
            numero++;
        }
        printf("\n");
    }
    return 0;
}