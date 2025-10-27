#include <stdio.h>
#include <stdlib.h>
#include "equipe.h" // bibliothèque de gestion d'une équipe
#include <string.h>

int main()
{
    /* ptrjoueur capitaineLOSC1;
    ptrjoueur capitaineLOSC2;
    joueur *capitaineLOSC3;
    joueur *capitaineLOSC4; */
    equipe eqFoot;
    equipe nouvEqFoot;
    /* capitaineLOSC1 = eqFoot.joueurs + 16;
    capitaineLOSC3 = eqFoot.joueurs + 16; */
    equipe testEqFoot;
    char nomFicEq[20];

    lire_equipe_fichier("LOSC.txt",&eqFoot);
    afficher_equipe(eqFoot);
    /* definir_capitaine2(&eqFoot, &capitaineLOSC2);
    definir_capitaine2(&eqFoot, &capitaineLOSC4);
    printf("Capitaine 1: %s %s \n" ,capitaineLOSC1->prenom, capitaineLOSC1->nom);
    printf("Capitaine 2: %s %s \n" ,capitaineLOSC2->prenom, capitaineLOSC2->nom);
    printf("Capitaine 3: %s %s \n" ,capitaineLOSC3->prenom, capitaineLOSC3->nom);
    printf("Capitaine 4: %s %s \n" ,capitaineLOSC4->prenom, capitaineLOSC4->nom); */
    lire_equipe_clavier(&nouvEqFoot);
    afficher_equipe(nouvEqFoot);
    /* ecrire_equipe_fichier("nouvelleEquipe.txt", nouvEqFoot);

    equipe testEqFoot;
    lire_equipe_fichier("nouvelleEquipe.txt", &testEqFoot);
    afficher_equipe(testEqFoot); */

    strcpy(nomFicEq, nouvEqFoot.nom);
    strcat(nomFicEq, ".txt");
    ecrire_equipe_fichier(nomFicEq, nouvEqFoot);
    lire_equipe_fichier(nomFicEq, &testEqFoot);
    afficher_equipe(testEqFoot);
    return 0;
}