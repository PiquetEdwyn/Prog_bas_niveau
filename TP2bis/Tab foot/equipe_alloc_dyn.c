#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "equipe_alloc_dyn.h"

/* Fonctions de manipulation d'une équipe */

void lire_equipe_fichier_alloc_dyn(char nomfic[],equipeAllocDyn* e)
{
    FILE *f;
    int i;
    char temp[101];

    if ((f=fopen(nomfic,"r"))!=NULL)
    {
        fscanf(f, "%100s", temp);
        e->nom = malloc((strlen(temp) + 1) * sizeof(char));

        strcpy(e->nom, temp);
        fscanf(f,"%d",&e->nbjoueurs);
        e->joueurs = malloc(e->nbjoueurs * sizeof(joueurAllocDyn));

        for (i = 0; i < e->nbjoueurs; i++) 
        {
            fscanf(f, "%100s", temp);
            e->joueurs[i].nom = malloc((strlen(temp) + 1) * sizeof(char));
            strcpy(e->joueurs[i].nom, temp);

            fscanf(f, "%100s", temp);
            e->joueurs[i].prenom = malloc((strlen(temp) + 1) * sizeof(char));
            strcpy(e->joueurs[i].prenom, temp);

            fscanf(f, "%d", &e->joueurs[i].numeromaillot);
        }
        fclose(f);
    }
    else
        printf("\nErreur de lecture du fichier %s\n\n",nomfic);
}

void afficher_joueurs_alloc_dyn(joueurAllocDyn *j,int nbj)
{
    for (int i = 0; i < nbj; i++)
    {
        printf("%d %s %s\n", j->numeromaillot, j->nom, j->prenom);
        j++;
    }
}

void afficher_equipe_alloc_dyn(equipeAllocDyn e)
{
    printf("%s : %d joueurs\n",e.nom,e.nbjoueurs);
    afficher_joueurs_alloc_dyn(e.joueurs,e.nbjoueurs);
}

void lire_equipe_clavier_alloc_dyn(equipeAllocDyn* e)
{
    char temp[101];
    printf("Lecture d'une nouvelle equipe : \n");
    printf("Nom de l'equipe (sans espace) ?");
    scanf("%100s", temp);
    e->nom = malloc(strlen(temp) + 1);
    strcpy(e->nom, temp);
    printf("Nombre de joueurs ?");
    scanf("%d", &e->nbjoueurs);
    e->joueurs = malloc(e->nbjoueurs * sizeof(joueurAllocDyn));

    for (int i = 0; i < e->nbjoueurs; i++)
    {
        printf("Saisir les nom prenom et numero de maillot du joueur %d ?", i + 1);
        scanf("%100s", temp);
        e->joueurs[i].nom = malloc(strlen(temp) + 1);
        strcpy(e->joueurs[i].nom, temp);
        scanf("%100s", temp);
        e->joueurs[i].prenom = malloc(strlen(temp) + 1);
        strcpy(e->joueurs[i].prenom, temp);

        scanf("%d", &e->joueurs[i].numeromaillot);
    }
    printf("Fin de lecture de l'equipe, merci \n");
}

void ecrire_equipe_fichier_alloc_dyn(char nomfic[], const equipeAllocDyn e)
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

long long unsigned int occupation_memoire_equipe_alloc_dyn(const equipeAllocDyn *e)
{
    long long unsigned int totalSize = 0;
        totalSize += strlen(e->nom) + 1;
    for (int i = 0; i < e->nbjoueurs; i++) 
    {
        totalSize += strlen(e->joueurs[i].nom) + 1;
        totalSize += strlen(e->joueurs[i].prenom) + 1;
        totalSize += sizeof(int);
    }
    totalSize += sizeof(joueurAllocDyn) * e->nbjoueurs;
    totalSize += sizeof(char*) + sizeof(int) + sizeof(joueurAllocDyn*);
    printf("%llu octets sont utilisés pour stocker la variable eqFootAllocDyn\n", (long long unsigned int)sizeof(totalSize));
    return totalSize;
}