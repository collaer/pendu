/**************************************************************/
/* Programme Pendu                                       */
/*============================================================*/
/* Auteur    : Espitia Yorley.                                */
/* Date      : 2020-05-05                                         */
/**************************************************************/

#ifndef DEF_FICHIERS
#define DEF_FICHIERS


typedef struct Jouer Jouer;
struct Jouer
{
    char nom [100];
    char prenom [100];
};
char Info_jouer(Jouer*);
char execute_menu();
void Option_jeu(char*);
char* Dif_dictionnaire();
int piocherMot(char* );
int nombreAleatoire(int);
void Mode();

#endif // DEF_FICHIERS
