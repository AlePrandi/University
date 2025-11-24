#include <stdio.h>
#include <stddef.h>
#define N 5


//  prototipi
int somma(const size_t aLen, const int a[]);
int sommaR(const size_t aLen,const int a[], size_t i);

int main(void){
    int arr[N] = {1,4,6,15,19};
    int som = 0;
    som = somma(N, arr);
    scanf("la somma degli el. dell'array e': %d \n", som);
    return 0;
}

// assicurasi che partiamo da zero
int somma(const size_t aLen, const int a[]){
    return sommaR(aLen, a, 0);
}

int sommaR(const size_t aLen,const int a[], size_t i){
    if(i == aLen){
        return 0;
    }else{
        return a[i] + sommaR(aLen, a, i + 1);
    }
}