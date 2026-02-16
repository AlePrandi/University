#include <stdio.h>

#define MAX 10

size_t ricerca(const int a[], int val);
size_t ricercaBin(size_t left, size_t right, const int a[], int val);

int main(void){
    
    int a[MAX] = {1,2,3,4,5,6,7,8,9,10};

    int val = 5;
    size_t ris = ricerca(a, val);
    if(ris != -1){
        printf("il valore %d e' presente in posizione a[%zu] \n", val, ris);
    }else{
        printf("Il valore %d non e' presente \n", val);
    }
    return 0;
}

size_t ricerca(const int a[], int val){
    if(val < a[0] || val > a[MAX - 1]){
        return -1;
    }else{
        return ricercaBin(0, MAX, a, val);
    }
}


size_t ricercaBin(size_t left, size_t right, const int a[], int val){
    if(left == right - 1){
        if(a[left] == val){
            return left;
        }else{
            return -1;
        }
    }else{
        // rischio overflow per indici grandi
        // size_t middle = (left + right) / 2;
        // Caso NO overflow
        size_t middle = left + ((right - left)/2);
        
        if(a[middle] == val){
            return middle;
        }else{
            if(val < a[middle]){
                return ricercaBin(left, middle, a, val);
            }else{
                return ricercaBin(middle, right, a, val);
            }
        }
    }
}