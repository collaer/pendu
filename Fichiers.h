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
    int difficulty;
    int invisible;
};
int joueurIsReady(Joueur*);
void Info_jouer(Joueur*);
char execute_menu();
void Option_jeu(Joueur*);
char execute_menu_options(Joueur*,char*);
int Dif_dictionnaire();
int Mode();


typedef struct Partie Partie;
struct Partie
{
    char motSecret [100];
    long tailleMot;
    char mask [100];
    int *lettreTrouvee;
    long coupsRestants;
};
char lireCaractere();
int rechercheLettre(char , char[] , int[] );
int gagne(int[], long );

#endif // DEF_FICHIERS
