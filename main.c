/**************************************************************/
/* Programme Pendu                                       */
/*============================================================*/
/* Auteur    : Espitia Yorley.                                */
/* Date      : 2020-05-05                                         */
/**************************************************************/

/*= Directives de précompilation =============================*/
#include <stdio.h>
#include <ctype.h>


#include "fichiers.h"
#include "dico.h"


/*= Prototypes ===============================================*/
char execute_menu();
void Jouer_partie();
void Quitter_jeu();


/*= Fonction principale ======================================*/
int main()
{
    /*- Déclarations -----------------------------------------*/
    Joueur J1;
    char choix;
    char errorMessage[100];

    J1.difficulty = 0;
    J1.invisible = 0;
    errorMessage[0] = '\0';


    /*- Traitements ------------------------------------------*/
    do
    {
        choix = execute_menu(&J1, &errorMessage);
        errorMessage[0] = '\0';

        switch(choix)
        {
            case '1' :  Info_jouer(&J1);
                        break;


            case '2' :
                        if (joueurIsReady(&J1) == 0)
                            strncpy(errorMessage, "Veuillez entrer votre Nom et une difficulte.", 100);
                        else
                            Jouer_partie(&J1);
                        break;


            case '3' :  Option_jeu(&J1);
                        break;

            default:
                strncpy(errorMessage, "Option not found.", 100);
        }

    }
    while (choix != '4');

    Quitter_jeu();
}

void Jouer_partie(Joueur* elJugador)
{
    clrscr();
    char choix;
    char motSecret[100] = {0}; // Ce sera le mot à trouver
    gotoxy(34,10); printf("Juste pour montrer le loading et choix dun mot");
    gotoxy(34,11); printf("Je te laisse comprendre et tenter de continuer ici?");

    piocherMot(motSecret, elJugador->difficulty);
    gotoxy(34,13); printf("&motPioche a ete donne en reference et a ete modifie dans la fonction");
    gotoxy(34,14); printf(" motPioche = %s ", motSecret);
    gotoxy(34,15); printf(" ------ ");


    gotoxy(34,20); printf("Pour faire une pause je demande un input ici pas utilise, ensuite on sera renvoye dans la main loop du menu");
    gotoxy(34,22); printf("Votre choix : ");
    gotoxy(49,22); scanf(" %c", &choix);

}

void Quitter_jeu()
{
    clrscr();
    printf("Merci d'avoir joue");
}
