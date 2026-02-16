#include <stdio.h>

#define SIZE 10

int ricercaBinaria(int arr[], int dim, int target,int* pos);

int main(void){
    int arr[SIZE] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int tar;
    int pos = 0; 
    printf("Inserisci un numero da cercare: ");
    scanf("%d", &tar);

    int result = ricercaBinaria(arr, SIZE, tar, &pos);
    if(result){
        printf("Numero %d trovato nell'array in pos arr[%d].\n", tar, pos);
    }else{
        printf("Numero non trovato\n");
    }

    return 0;
}


int ricercaBinaria(int arr[], int dim, int target, int* pos){
    int ret = 0;
    int left = 0;
    int right = dim - 1;
    while(right - left > 0 && ret == 0){
        int mid = (left + right) / 2;
        if(target == arr[mid]){
            ret = target;
            *pos = mid;
        }else{
            if(target > arr[mid]){
                left = mid + 1;
            }else{
                right = mid;
            }
        }
    }

    return ret;
}