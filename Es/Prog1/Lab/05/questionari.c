#include <stdio.h>

#define NUM_RISP 20 // numero risposte al questionario
#define VAL 5

int main()
{
	// valori delle risposte ai questionari
	const int risposte[NUM_RISP] = {
		1, 2, 5, 4, 3, 5, 2, 1, 3, 1,
		4, 3, 3, 3, 2, 3, 3, 2, 2, 5};

	// calcola le frequenze delle risposte
	int frequenze[VAL] = {};
	for (size_t i = 0; i < NUM_RISP; i++)
	{
		frequenze[risposte[i]]++;
	}


	printf("Stelle \t Frequenza\n");
	for(size_t i = 0; i < VAL; i++){
		printf("%zu \t %d     \t", i + 1, frequenze[i + 1]);
		for(size_t j = 0; j < frequenze[i + 1];j++){
			printf("#");
		}
		puts("");
	}
	return 0;
}
