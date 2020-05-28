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

/*= Prototypes ===============================================*/

void Jouer_partie();
void Quitter_jeu();


/*= Fonction principale ======================================*/
int main()
{
    /*- Déclarations -----------------------------------------*/
    Joueur leJoueur;
    char choix;
    char errorMessage[100];

    leJoueur.difficulty = 2;
    leJoueur.invisible = 1;
    errorMessage[0] = '\0';


    /*- Traitements ------------------------------------------*/
    do
    {
        choix = execute_menu(&leJoueur, &errorMessage);
        errorMessage[0] = '\0';

        switch(choix)
        {
            case '1' :  Info_jouer(&leJoueur);
                        break;


            case '2' :
                printf(" case 2 ");
                        if (joueurEstPret(&leJoueur) == 0)
                            strncpy(errorMessage, "Veuillez entrer votre Nom.", 100);
                        else
                            {
                            printf(" 3 ");
                            Jouer_partie(&leJoueur);

                        }
                        break;


            case '3' :  Option_jeu(&leJoueur);
                        break;

            default:
                strncpy(errorMessage, "Option non trouvee.", 100);
        }

    }
    while (choix != '4');

    Quitter_jeu(leJoueur);
}

void Jouer_partie(Joueur* leJoueur)
{
    char choix;
    nouvelle_partie(leJoueur);

    gotoxy(34,22); printf("Votre choix : ");gotoxy(49,22); scanf(" %c", &choix);

}

void Quitter_jeu(Joueur* leJoueur)
{
    clrscr();
    gotoxy(37,12); printf("Merci d'avoir joue %s %s \n\n\n\n\n", leJoueur->nom, leJoueur->prenom);
}
