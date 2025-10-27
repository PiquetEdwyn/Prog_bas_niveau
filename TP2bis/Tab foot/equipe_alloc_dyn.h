/* Module permettant de gérer une équipe de joueurs */

/* Un joueur est défini par son nom, prénom et numéro de maillot */
typedef struct
{
    char *nom;
    char *prenom;
    int numeromaillot;
} joueurAllocDyn, *ptrjoueurAllocDyn; // le type ptrjoueur est un type pointeur vers un joueur

/* Une équipe est définie par son nom, nombre de joueurs et tableau de joueurs */
typedef struct
{
    char *nom;
    int nbjoueurs;
    joueurAllocDyn *joueurs;
} equipeAllocDyn, *ptrequipeAllocDyn; // le type ptrequipe est un type pointeur vers une equipe

/* Liste des fonctions de gestion d'une équipe */
/* Seuls les prototypes (en-têtes) des fonctions sont listés (suivis d'un ";") */
/* Leurs définitions sont dans le fichier equipe.c */
void lire_equipe_fichier_alloc_dyn(char nomfic[],equipeAllocDyn* e);
void afficher_equipe_alloc_dyn(equipeAllocDyn e);
void lire_equipe_clavier_alloc_dyn(equipeAllocDyn* e);
void ecrire_equipe_fichier_alloc_dyn(char nomfic[], equipeAllocDyn e);
long long unsigned int occupation_memoire_equipe_alloc_dyn(const equipeAllocDyn *e);