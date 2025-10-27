typedef struct
{
    char nom[50];
    char prenom[50];
    double *moyennes;
    int nbUEvalide;
    char decision;
} moyEtu;


typedef struct
{
    int nb_etu;
    int nb_UE;
    moyEtu *etudiants;
} moyPromo;

void lire_fichier_moyennes(char nomfic[], moyPromo* e);
void decisionJury(moyPromo* promo);
void afficher_decisions_jury(moyPromo* promo);