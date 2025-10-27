#include <stdio.h>
#include <stdlib.h>
#include "equipe.h"

/* Fonctions de manipulation d'une équipe */

void lire_equipe_fichier(char nomfic[],equipe* e)
{
    FILE *f;
    int i;

    if ((f=fopen(nomfic,"r"))!=NULL)
    {
        fscanf(f,"%s",e->nom);
        fscanf(f,"%d",&e->nbjoueurs);
        for (i=0;i<e->nbjoueurs;i++)
            fscanf(f,"%s%s%d",e->joueurs[i].nom,e->joueurs[i].prenom,&e->joueurs[i].numeromaillot);
        fclose(f);
    }
    else
        printf("\nErreur de lecture du fichier %s\n\n",nomfic);
}

void afficher_joueurs(joueur *j,int nbj)
{
    for (int i = 0; i < nbj; i++)
    {
        printf("%d %s %s\n", j->numeromaillot, j->nom, j->prenom);
        j++;
    }
}

void afficher_equipe(equipe e)
{
    printf("%s : %d joueurs\n",e.nom,e.nbjoueurs);
    afficher_joueurs(e.joueurs,e.nbjoueurs);
}

void definir_capitaine2(equipe *e, ptrjoueur *capitaineLOSC2)
{
    *capitaineLOSC2 = e->joueurs + 16;
}

void definir_capitaine4(equipe *e, joueur **capitaineLOSC4)
{
    *capitaineLOSC4 = e->joueurs + 16;
}

void lire_equipe_clavier(equipe* e)
{
    printf("Lecture d'une nouvelle equipe : \n");
    printf("Nom de l'equipe (sans espace) ?");
    scanf("%s", e->nom);
    printf("Nombre de joueurs ?");
    scanf("%d", &e->nbjoueurs);

    for (int i = 0; i < e->nbjoueurs; i++)
    {
        printf("Saisir les nom prenom et numero de maillot du joueur %d ?", i + 1);
        scanf("%s %s %d", e->joueurs[i].nom, e->joueurs[i].prenom, &e->joueurs[i].numeromaillot);
    }
    printf("Fin de lecture de l'equipe, merci \n");
}

void ecrire_equipe_fichier(char nomfic[], const equipe e)
{
    FILE *f;

    f = fopen(nomfic, "w");
    if (f == NULL)
    {
        printf("\nErreur lors de l'ouverture du fichier %s en écriture\n\n", nomfic);
        return;
    }

    fprintf(f, "%s\n", e.nom);
    fprintf(f, "%d\n", e.nbjoueurs);

    for (int i = 0; i < e.nbjoueurs; i++)
    {
        fprintf(f, "%s %s %d\n", e.joueurs[i].nom, e.joueurs[i].prenom, e.joueurs[i].numeromaillot);
    }
    fclose(f);
}