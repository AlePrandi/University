#include <stdio.h>

int fact(int num)
{
    if (num > 0)
    {
        if (num == 2 || num < 2)
        {
            return num;
        }
        else
        {
            return num * fact(num - 1);
        }
    }else{
        printf("numero non valido");
        return 0;
    }
}

int main(void)
{
    int n, val;

    printf("inserisci un numero: ");
    scanf("%d", &n);
    val = fact(n);
    printf("il fattoriale di %d e': %d \n", n, val);
    return 0;
}