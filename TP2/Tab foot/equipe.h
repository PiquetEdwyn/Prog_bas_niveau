/* Module permettant de gérer une équipe de joueurs */

/* Un joueur est défini par son nom, prénom et numéro de maillot */
typedef struct
{
    char nom[30],prenom[50];
    int numeromaillot;
} joueur, *ptrjoueur; // le type ptrjoueur est un type pointeur vers un joueur

/* Une équipe est définie par son nom, nombre de joueurs et tableau de joueurs */
typedef struct
{
    char nom[50];
    int nbjoueurs;
    joueur joueurs[50];
} equipe, *ptrequipe; // le type ptrequipe est un type pointeur vers une equipe

/* Liste des fonctions de gestion d'une équipe */
/* Seuls les prototypes (en-têtes) des fonctions sont listés (suivis d'un ";") */
/* Leurs définitions sont dans le fichier equipe.c */
void lire_equipe_fichier(char nomfic[],equipe* e);
void afficher_equipe(equipe e);
void definir_capitaine2(equipe *e, ptrjoueur *capitaineLOSC2);
void definir_capitaine4(equipe *e, joueur **capitaineLOSC4);
void lire_equipe_clavier(equipe* e);
void ecrire_equipe_fichier(char nomfic[], equipe e);
int trouver_maillot_joueur(equipe e, char* nomJoueur, char* prenomJoueur);