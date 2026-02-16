#include <stdio.h>
#include <stdbool.h>
// usata nella ricerca di un valore solitamente
#define LEN 10 

size_t ricorsioneL2R(const size_t aLen, const int arr[]);
size_t ric_L2R(const size_t aLen, const int arr[], size_t i);

size_t ricorsioneR2L(const size_t aLen, const int arr[]);
size_t ric_R2L(const size_t aLen, const int arr[], size_t i);

size_t ricorsioneDico(const size_t aLen, const int arr[]);
size_t ric_dico(const size_t aLen, const int arr[], size_t left, size_t right);

bool allPari(const size_t aLen, const int arr[], size_t i);
bool maggioreDi(const size_t aLen, const int arr[], size_t i, int val);


int main(void){
    size_t aLen = LEN;
    int arr[10] = {1,2,3,4,5,6,7,8,9,11};
    printf("numeri pari L2R: %zu", ricorsioneL2R(aLen,arr));
    puts("");
    printf("numeri pari R2L: %zu", ricorsioneR2L(aLen,arr));
    puts("");
    printf("numeri pari DICO: %zu", ricorsioneDico(aLen,arr));
    puts("");

    int arrP[10] = {10, 12, 14, 16, 18, 20, 30, 32, 36, 46};

    if(allPari(aLen,arrP,0))
        printf("Tutti pari\n");

    int num = 25;
    if(maggioreDi(aLen, arrP,0, num))
        printf("Esiste un numero maggiore di %d \n", num);

   return 0;
}

size_t ricorsioneL2R(const size_t aLen, const int arr[]){
    return ric_L2R(aLen, arr, 0);
}

size_t ric_L2R(const size_t aLen, const int arr[], size_t i){
    if(i == aLen){
        return 0;
    }else{
        return(arr[i] % 2 == 0) ? 1 + ric_L2R(aLen, arr, i + 1) : 0 + ric_L2R(aLen, arr, i + 1);
    }
}

size_t ricorsioneR2L(const size_t aLen, const int arr[]){
    return ric_R2L(aLen, arr, aLen);
}

size_t ric_R2L(const size_t aLen, const int arr[], size_t i){
    if(i == 0){
        return 0;
    }else{
        return(arr[i-1] % 2 == 0) ? 1 + ric_R2L(aLen, arr, i - 1) : 0 + ric_R2L(aLen, arr, i - 1);
    }
}

size_t ricorsioneDico(const size_t aLen, const int arr[]){
    if(aLen == 0 || arr == NULL){ // casi particolari
        return 0;
    }else{
        return ric_dico(aLen, arr, 0, aLen);
    }
}

size_t ric_dico(const size_t aLen, const int arr[], size_t left, size_t right){
    if(left + 1 == right){
        if(arr[left] % 2 == 0){
            return 1;
        }else{
            return 0;
        }
    }else{
        size_t middle = (left + right) / 2;
        return ric_dico(aLen, arr, left, middle) + ric_dico(aLen, arr, middle, right);
    }
}

//condizione Universale
// Es tutti pari

bool allPari(const size_t aLen, const int arr[], size_t i){
    if(i == aLen)
        return true;

    return(arr[i] % 2 == 0) && allPari(aLen, arr, i+1);
}


//condizione Esistenziale
//Es almeno un numero maggiore di n

bool maggioreDi(const size_t aLen, const int arr[], size_t i, int val){
    if(i == aLen)
        return false;

    return(arr[i] > val) || maggioreDi(aLen, arr, i+1, val);
}