#include<stdio.h>
#include<stdlib.h>

#define TAILLE 10

//Liste Simplement chainée

typedef struct Element_entier {

	int n_entier;
	Element_entier* p_suivant;
}Element_entier;


typedef struct Liste_entiers {

	Element_entier* element_debut;
	Element_entier* element_fin;

	int n_taille;

}Liste_entiers;


void initialisation(Liste_entiers* Liste);
int insertListeVide(Liste_entiers* Liste, int n_val);
int insertDebutListe(Liste_entiers* Liste, int n_val);
int insertFinListe(Liste_entiers* Liste, Element_entier* courant, int n_val);
int insertPosListe(Liste_entiers* Liste, int n_pos, int n_val);
int suppDebut(Liste_entiers* Liste);
int suppPosListe(Liste_entiers* Liste, int n_pos);
int destructListe(Liste_entiers* liste);
void afficheListe(Liste_entiers* Liste);



int main() {

	Liste_entiers* Liste = NULL;
	Liste = (Liste_entiers*)malloc(sizeof(Liste_entiers));

	initialisation(Liste);

	if (insertListeVide(Liste, 1)) {

		printf("Insert dans liste vide ok\n");
	}

	if (insertDebutListe(Liste, 2)) {

		printf("Insert en debut de liste ok\n");
	}

	if (Liste && insertFinListe(Liste, Liste->element_fin, 3)) {

		printf("Insert en fin de liste ok\n");
	}

	if (insertPosListe(Liste, 3, 4)) {
		printf("insert à la position ok\n");
	}

	afficheListe(Liste);

	//suppDebut(Liste);

	if (suppPosListe(Liste, 3)) {

		printf("Supp pos ok\n");
	}

	afficheListe(Liste);

	if (destructListe(Liste)) {

		printf("Destruction liste\n");
	}


	free(Liste);


	
	return 0;
}


void initialisation(Liste_entiers* Liste) {

	Liste->element_debut = NULL;
	Liste->element_fin = NULL;
	Liste->n_taille = 0;


}

int insertListeVide(Liste_entiers* Liste, int n_val) {

	Element_entier* element = NULL;
	element = (Element_entier*)malloc(sizeof(Element_entier));

	if (element == NULL) {

		return 0;
	}
	else {

		element->n_entier = n_val;
		element->p_suivant = NULL;
		Liste->element_debut = element;
		Liste->element_fin = element;
		Liste->n_taille++;

		return 1;

	}



}


int insertDebutListe(Liste_entiers* Liste, int n_val) {

	Element_entier* element = NULL;
	element = (Element_entier*)malloc(sizeof(Element_entier));

	if (element == NULL) {

		return 0;
	}
	else {

		element->n_entier = n_val;
		element->p_suivant = Liste->element_debut;
		Liste->element_debut = element;
		Liste->n_taille++;

		return 1;

	}


}

int insertFinListe(Liste_entiers* Liste, Element_entier* courant, int n_val) {

	Element_entier* element = NULL;
	element = (Element_entier*)malloc(sizeof(Element_entier));

	if (element == NULL) {

		return 0;
	}
	else {

		element->n_entier = n_val;
		courant->p_suivant = element;
		element->p_suivant = NULL;
		Liste->element_fin = element;
		Liste->n_taille++;

		return 1;

	}

}


int insertPosListe(Liste_entiers* Liste, int n_pos, int n_val) {


	if (Liste->n_taille < 2) {
		return 0;
	}

	if (n_pos<1 || n_pos>Liste->n_taille) {
		return 0;
	}

	Element_entier *element = NULL;
	Element_entier* courant = NULL;
	element = (Element_entier*)malloc(sizeof(Element_entier));

	courant = Liste->element_debut;

	if (element == NULL) {

		return 0;

	}
	else {

		for (int n_i = 1; n_i < n_pos - 1; n_i++) {
			
			courant = courant->p_suivant;
		}

		if (courant->p_suivant == NULL) {
			return 0;
		}

		element->n_entier = n_val;
		element->p_suivant = courant->p_suivant;
		courant->p_suivant = element;
		Liste->n_taille++;

		return 1;
	}

}


int suppDebut(Liste_entiers* Liste) {

	if (Liste->n_taille == 0)
		return 0;

	Element_entier* supp = NULL;
	supp = Liste->element_debut;
	Liste->element_debut = Liste->element_debut->p_suivant;

	if (Liste->n_taille == 1){
		Liste->element_fin = NULL;
	}

	free(supp);
	Liste->n_taille--;

	return 1;

}

int suppPosListe(Liste_entiers* Liste, int n_pos) {

	if (Liste->n_taille <= 1 || n_pos < 1 || n_pos >= Liste->n_taille)
		return 0;

	Element_entier* supp = NULL;
	Element_entier* courant = NULL;

	courant = Liste->element_debut;

	for (int n_i = 1; n_i < n_pos - 1; n_i++) {

		courant = courant->p_suivant;
	}

	supp = courant->p_suivant;
	courant->p_suivant = courant->p_suivant->p_suivant;
	if (courant->p_suivant == NULL)
		Liste->element_fin = courant;

	free(supp);
	Liste->n_taille--;
	
	return 1;

}

int destructListe(Liste_entiers* liste) {

	if (liste->n_taille == 0)
		return 0;

	while (liste->n_taille > 0)
		suppDebut(liste);

	return 1;
}

void afficheListe(Liste_entiers* Liste) {

	Element_entier* courant = NULL;
	courant = Liste->element_debut;

	while (courant != NULL)
	{
		printf("%d\n", courant->n_entier);
		courant = courant->p_suivant;
	}
}
