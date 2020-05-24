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
char execute_menu();
void Jouer_partie();
void Quitter_jeu();


/*= Fonction principale ======================================*/
int main()
{
    /*- Déclarations -----------------------------------------*/
    Jouer J1;
    char choix;
    char *option;


    /*- Traitements ------------------------------------------*/
    do
    {
        choix = execute_menu();

        switch(choix)
        {
            case '1' :  Info_jouer(&J1);
                        break;
            case '2' :  Jouer_partie();
                        break;
            case '3' :  Option_jeu(&option);
                        break;
            case '4' :  Quitter_jeu();
                        break;
        }
    }
    while (choix != '4');
}

void Jouer_partie()
{
    clrscr();
    printf("On commence");




}
void Quitter_jeu()
{
    clrscr();
    printf("Merci d'avoir joue");
}
