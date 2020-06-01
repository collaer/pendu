/*dico.c
------
Ces fonctions piochent au hasard un mot dans un fichier dictionnaire
pour le jeu du pendu
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "dico.h"

/*= Fonctions ================================================*/

int piocherMot(char* motPioche, int difficulte)
{
    FILE* dico = NULL;
    int   nombreMots = 0, numMotChoisi = 0;
    int   caractereLu = 0;

    switch(difficulte)
    {
        case 1: dico = fopen("./dicos/Difficulte1.txt", "r");
                break;
        case 3: dico = fopen("./dicos/Difficulte3.txt", "r");
                break;
        case 4: dico = fopen("./dicos/Difficulte4.txt", "r");
                break;
        case 5: dico = fopen("./dicos/Difficulte5.txt", "r");
                break;
        default: dico = fopen("./dicos/Difficulte2.txt", "r");
    }


    if (dico == NULL)
    {
        printf("\nImpossible de charger le dictionnaire de mots");
        return 0;
    }

    do
    {
        caractereLu = fgetc(dico);
        if (caractereLu == '\n')
            nombreMots++;
    }
    while(caractereLu != EOF);

    numMotChoisi = nombreAleatoire(nombreMots);

    rewind(dico);

    while (numMotChoisi > 0)
    {
        caractereLu = fgetc(dico);
        if (caractereLu == '\n')
            numMotChoisi--;
    }

    fgets(motPioche, 100, dico);

    motPioche[strlen(motPioche) - 1] = '\0';
    fclose(dico);

    return 1;
}

int nombreAleatoire(int nombreMax)
{
    srand(time(NULL));
    return (rand() % nombreMax);
}
