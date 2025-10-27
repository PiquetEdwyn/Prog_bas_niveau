#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "moyennes.h"

int main(int argc, char *argv[]) 
{
    char *nomfic;
    moyPromo promo1;

    if (argc != 2) 
    {
        fprintf(stderr, "Utilisation : jury nom_fichier_moyennes\n");
        exit(EXIT_FAILURE);
    }

    nomfic = argv[1];
    fprintf(stdout, "Nom du fichier contenant les moyennes : %s\n", nomfic);

    lire_fichier_moyennes(nomfic, &promo1);
    decisionJury(&promo1);
    afficher_decisions_jury(&promo1);
    return 0;
}