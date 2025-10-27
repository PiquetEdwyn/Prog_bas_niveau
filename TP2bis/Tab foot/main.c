#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "equipe_alloc_dyn.h"
#include "equipe.h"

int main()
{
    equipe eqFoot;
    equipe nouvEqFoot;
    equipe eqFootAllocDyn;
    equipeAllocDyn testEqFoot;
    char nomFicEq[20];

    lire_equipe_fichier("LOSC.txt",&eqFoot);
    afficher_equipe(eqFoot);
    lire_equipe_clavier(&nouvEqFoot);
    afficher_equipe(nouvEqFoot);
    strcpy(nomFicEq, nouvEqFoot.nom);
    strcat(nomFicEq, ".txt");
    ecrire_equipe_fichier(nomFicEq, nouvEqFoot);
    lire_equipe_fichier_alloc_dyn(nomFicEq, &testEqFoot);
    afficher_equipe_alloc_dyn(testEqFoot);
    long long unsigned int mémoire_occupée = occupation_memoire_equipe_alloc_dyn(&testEqFoot);
    printf("%llu octets sont utilisés pour stocker la variable eqFoot\n", (long long unsigned int)sizeof(eqFoot));
    return 0;
}