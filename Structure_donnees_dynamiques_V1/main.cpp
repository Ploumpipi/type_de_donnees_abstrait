#include <stdio.h>
#include <stdlib.h>

/*
BUT : Creer un carre magique de 5 ou 7 de cote
ENTREE : -
SORTIE : Affichage du carre magique
*/

#define TAILLE 7

typedef struct jeton {
    int n_posX;
    int n_posY;
}jeton;

int** allocppCarre(int** pp_ncarre);
void init(int** pp_ncarre, jeton* ppos, int* p_ncompteur);
void nordEst(jeton* ppos);
void nordOuest(jeton* ppos);
void corriger(jeton* ppos);
void estVide(int** pp_ncarre, jeton* ppos);
void placer(int** pp_ncarre, jeton* ppos, int n_val);
void affiche(int** pp_ncarre);
int freeppCarre(int** pp_ncarre);

int main()
{
    
    int** pp_ncarre=NULL;
    int n_compteur = 0;
    jeton pos;
   

    if (pp_ncarre = allocppCarre(pp_ncarre)) {

        puts("Allocation memoire ok\n");
    }
       
    init(pp_ncarre, &pos,&n_compteur);

  
    for (int n_i = n_compteur; n_i <= TAILLE * TAILLE; n_i++) {

        nordEst(&pos);
        estVide(pp_ncarre, &pos);
        placer(pp_ncarre, &pos, n_i);

    }
    affiche(pp_ncarre);

    if (freeppCarre(pp_ncarre)) {

        puts("Vidage memoire ok\n");
    }

   

   
    return 0;
}


void init(int** pp_ncarre, jeton* ppos,int *p_ncompteur) {
   
    int n_i, n_j;

    for (n_i = 0; n_i < TAILLE; n_i++) {
        for (n_j = 0; n_j < TAILLE; n_j++) {
            if (pp_ncarre[n_i])
                pp_ncarre[n_i][n_j] = 0;
        }
    }

    ppos->n_posX = (TAILLE - 1) / 2 - 1;
    ppos->n_posY = (TAILLE - 1) / 2;
    if (pp_ncarre[ppos->n_posX]) {
        pp_ncarre[ppos->n_posX][ppos->n_posY] = 1;
    }
       
    *p_ncompteur = 2;

    
}

int** allocppCarre(int** pp_ncarre)
{
    int n_i, n_j;

    pp_ncarre = (int**)malloc(TAILLE * sizeof(int*));
    for (n_i = 0; n_i < TAILLE; n_i++) {
        if (!pp_ncarre) {
            return NULL;
        }
        pp_ncarre[n_i] = (int*)malloc(TAILLE * sizeof(int));
    }

    

    return pp_ncarre;
}



void nordEst(jeton* ppos) {

    ppos->n_posX = ppos->n_posX - 1;
    ppos->n_posY = ppos->n_posY + 1;
    corriger(ppos);


}

void  nordOuest(jeton* ppos) {


    ppos->n_posX = ppos->n_posX - 1;
    ppos->n_posY = ppos->n_posY - 1;
    corriger(ppos);



}


void corriger(jeton* ppos)
{


    if (ppos->n_posX < 0) {

        ppos->n_posX = TAILLE - 1;
    }
    if (ppos->n_posY == TAILLE) {

        ppos->n_posY = 0;
    }
    if (ppos->n_posY < 0) {

        ppos->n_posY = TAILLE - 1;
    }


}

void estVide(int** pp_ncarre, jeton* ppos) {



    while (pp_ncarre[ppos->n_posX][ppos->n_posY] != 0) {

        nordOuest(ppos);

    }

}

void placer(int** pp_carre, jeton* ppos, int n_val) {

    pp_carre[ppos->n_posX][ppos->n_posY] = n_val;
}


void affiche(int** pp_ncarre) {
   
    int n_i;
    int n_j;

    for (n_i = 0; n_i < TAILLE; n_i++)
    {

        for (n_j = 0; n_j < TAILLE; n_j++) {

            printf("%d ", pp_ncarre[n_i][n_j]);
        }
        printf("\n");
    }
}

int freeppCarre(int** pp_ncarre) {
    for (int n_i = 0; n_i < TAILLE; n_i++) {
        if (!pp_ncarre) {
            return 0;
        }
        free(pp_ncarre[n_i]);
    }

    free(pp_ncarre);

    return 1;
}
