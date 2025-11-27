#include <stdio.h>
#include <limits.h>
#define N 5

//  prototipi
int somma(const size_t aLen, const int a[]);
int sommaR(const size_t aLen, const int a[], size_t i);

int main(void)
{
    int arr[N] = {1, 4, 6, 15, 19};
    int som = 0;
    som = somma(N, arr);
    scanf("la somma degli el. dell'array e': %d \n", som);
    stampaCre(N, arr, 0);
    puts("");
    stampaDec(N, arr, 0);
    char stringa[10] = "ciao";
    int lung = lung_stringa(stringa);
    printf("la stringa %s e' lunga %d char\n", stringa, lung);
    return 0;
}

// interfaccia con involucro
// wrapper -> oscura i dettagli al main
int somma(const size_t aLen, const int a[])
{
    return sommaR(aLen, a, 0);
}

int sommaR(const size_t aLen, const int a[], size_t i)
{
    if (i == aLen)
    {
        return 0;
    }
    else
    {
        return a[i] + sommaR(aLen, a, i + 1);
    }
}

/*
void stampaCre(const size_t aLen, const int a[], size_t i){
    if (i < aLen){
        printf("%d ", a[i]);
        stampaCre(aLen, a, i + 1);
    }
}
*/

void stampaCre(const size_t aLen, const int a[], size_t i){
    if (i == aLen){
        return;
    }else{
        printf("%d ", a[i]);
        stampaCre(aLen, a, i + 1);
    }
}

/*
void stampaDec(const size_t aLen, const int a[], size_t i){
    if(aLen - i -1 >= 0){
        printf("%d ", a[aLen - i - 1]);
        stampaDec(aLen, a, i + 1);
    }
}
*/

void stampaDec(const size_t aLen, const int a[], size_t i){
    if(i == aLen){
        return;
    }else{
        // inverto stampa e chiamata per stampare prima i successivi
        stampaDec(aLen, a, i + 1);
        printf("%d ", a[i]);
    }
}

int min(const size_t aLen, const size_t a[], size_t i){
    if(i == aLen){
        return INT_MAX;
    }else{
        int minCoda = min(aLen, a, i +1);
        return(a[i] < minCoda) ? a[i] : minCoda;
    }
}

int max(const size_t aLen, const size_t a[], size_t i){
    if(i == aLen){
        return INT_MIN;
    }else{
        int maxCoda = max(aLen, a, i +1);
        return(a[i] > maxCoda) ? a[i] : maxCoda;
    }
}

int lung_stringa(const char* s){
    if(*s == '\0'){
        return 0;
    }else{
        return 1 + lung_stringa(s + 1);
    }
}

