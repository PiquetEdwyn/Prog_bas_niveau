#include "moyennes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void lire_fichier_moyennes(char nomfic[], moyPromo* e)
{
    FILE *f;
    int i, j;

    f = fopen(nomfic, "r");
    e->etudiants = (moyEtu*)malloc(e->nb_etu * sizeof(moyEtu));
    for (i = 0; i < e->nb_etu; i++)
    {
        fscanf(f, "%s %s", e->etudiants[i].prenom, e->etudiants[i].nom);
        e->etudiants[i].moyennes = (double*)malloc(e->nb_UE * sizeof(double));
        for (j = 0; j < e->nb_UE; j++)
        {
            fscanf(f, "%lf", &(e->etudiants[i].moyennes[j]));
        }
    }

    fclose(f);
}

void decisionJury(moyPromo* promo) 
{
    for (int i = 0; i < promo->nb_etu; i++) 
    {
        int nbUEvalide = 0;
        for (int j = 0; j < promo->nb_UE; j++) 
        {
            if (promo->etudiants[i].moyennes[j] >= 10.0) 
            {
                nbUEvalide++;
            }
        }
        if (nbUEvalide >= 4) 
        {
            promo->etudiants[i].decision = 'V';
            promo->etudiants[i].nbUEvalide = nbUEvalide;
        }
        else 
        {
            promo->etudiants[i].decision = 'E';
            promo->etudiants[i].nbUEvalide = nbUEvalide;
        }
    }
}

void afficher_decisions_jury(moyPromo* promo) 
{
    for (int i = 0; i < promo->nb_etu; i++) 
    {
        printf("%s %s ", promo->etudiants[i].prenom, promo->etudiants[i].nom);
        if (promo->etudiants[i].decision == 'V') 
        {
            printf("V");
            if (promo->etudiants[i].nbUEvalide == promo->nb_UE) 
            {
                printf("*\n");
            } else 
            {
                printf("%d\n", promo->etudiants[i].nbUEvalide);
            }
        }
        else 
        {
            printf("E\n");
        }
    }
}