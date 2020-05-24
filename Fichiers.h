/**************************************************************/
/* Programme Pendu                                       */
/*============================================================*/
/* Auteur    : Espitia Yorley.                                */
/* Date      : 2020-05-05                                         */
/**************************************************************/

#ifndef DEF_FICHIERS
#define DEF_FICHIERS


typedef struct Joueur Joueur;
struct Joueur
{
    char nom [100];
    char prenom [100];
    // difficulty level between 1-5
    int difficulty;
    // invisible mode, 0: norma, 1: invisible
    int invisible;
};
int joueurIsReady(Joueur*);
void Info_jouer(Joueur*);
char execute_menu();
void Option_jeu(Joueur*);
char execute_menu_options(Joueur*,char*);
int Dif_dictionnaire();
int Mode();

#endif // DEF_FICHIERS
