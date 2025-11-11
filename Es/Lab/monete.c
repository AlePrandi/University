#include <stdio.h>

#define NUM_TAGLI 6

int cambio_taglio(int cifra, int moneta);

int main(void) {
	// Chiedi all'utente la somma da convertire
	int cent;
	printf("Scrivere l'ammontare da convertire in monete: ");
	scanf("%d", &cent);

	// Definiamo i tagli delle monete
	const int tagli_monete[NUM_TAGLI] = {1,2,5,10,20,50};

	// COMPLETARE
	printf("Cifra = %d \n", cent);
	for(int i = NUM_TAGLI-1; i >= 0; i--){
		int num_monete = cambio_taglio(cent, tagli_monete[i]);
		cent = cent - (tagli_monete[i] * num_monete);
		if(num_monete > 0){
			printf("%d monete da %dcent", num_monete, tagli_monete[i]);
			puts("");
		}
	}
	return 0;
}

int cambio_taglio(int cifra, int moneta){
	int conv = cifra;
	int num_monete = 0;
	while(conv >= moneta){
		num_monete++;
		conv -= moneta;
	}
	return num_monete;
}