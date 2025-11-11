#include <stdio.h>
#include <stdbool.h>

// Prototipo della funzione:
bool verifica_primalita(int num);

int main(void)
{
	// stampa i numeri primi minori di 100
	for (int n = 2; n <= 100; n++)
	{
		if (verifica_primalita(n))
		{
			printf("Il numero %d e' primo!", n);
			puts("");
		}
	}
}

// Implementazione della funzione verifica_primalita()
// restituisce true se n è primo, false altrimenti
// restituisce sempre false per qualsiasi n < 2
bool verifica_primalita(int num)
{
	// COMPLETARE
	bool ret = true;
	for (int i = 2; i < num/2+1; i++)
	{
		if (num % i == 0)
		{
			ret = false;
		}
	}
	return ret;
}
