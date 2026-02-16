#include <stdio.h>

int fact(int num);

int main(void)
{
    int n, val;

    printf("inserisci un numero: ");
    scanf("%d", &n);
    val = fact(n);
    printf("il fattoriale di %d e': %d \n", n, val);
    return 0;
}

int fact(int num)
{
    int ret = 0;
    if (num >= 0)
    {
        if (num == 0)
        {
            ret = 1;
        }
        else
        {
            ret = num * fact(num - 1);
        }
    }else{
        printf("numero non valido");
        ret = 0;
    }
    return ret;
}