#include<stdio.h>
#include<stdlib.h>


#define TAILLE 10

int main() {
	//Les tableaux (statiques) 
	//adressage dans la pile
	int n_tab[TAILLE] = { 0 };

	//affichage des @ du tableau
	printf("adr du tableau n_tab : %x\n",(unsigned int)&n_tab);
	printf("adr du tableau n_tab : %x\n",(unsigned int)&n_tab[0]);
	printf("adr du tableau n_tab : %x\n",(unsigned int)&n_tab[1]);

	//Les tableaux (dynamiques)
	int* pn_tab = NULL;

	pn_tab = (int*)calloc(1, sizeof(int));
	if (pn_tab != NULL) {
		printf("adr du tableau pn_tab : %x\n", (unsigned int)&pn_tab);
		printf("adr du tableau pn_tab : %x\n", (unsigned int)&pn_tab[0]);
		printf("adr du tableau pn_tab : %x\n", (unsigned int)&pn_tab[1]);
	}

	int** ppn_tab = NULL;
	ppn_tab = (int**)calloc(TAILLE, sizeof(int*));

	if (ppn_tab != NULL) {
		for (int n_i = 0; n_i < TAILLE; n_i++) {
			ppn_tab[n_i] = (int*)calloc(TAILLE, sizeof(int));
		}
	}


	if (ppn_tab != NULL) {
		for (int n_i = 0; n_i < TAILLE; n_i++) {
			for (int n_j = 0; n_j < TAILLE; n_j++) {
				if (ppn_tab[n_i]) {
					printf("%d", ppn_tab[n_i][n_j]);
				}
			}
			puts("\n");
		}
	}

	if (ppn_tab != NULL) {
		for (int n_i = 0; n_i < TAILLE; n_i++) {
			free(ppn_tab[n_i]);
		}
	}


	free(pn_tab);

	return 0;
}