#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, char *argv[]) 
{
    char *endptr;
    
    if (argc != 4) 
    {
        fprintf(stderr, "Utilisation : 3 arguments attendus, une chaine, un entier et un nombre reel.\n");
        exit(EXIT_FAILURE);
    }

    char paramcc[50];
    strcpy(paramcc, argv[1]);

    errno = 0;
    long paramentier = strtol(argv[2], &endptr, 10);
    if (errno == ERANGE) 
    {
        perror("strtol");
        exit(EXIT_FAILURE);
    }

    double paramreel = strtod(argv[3], &endptr);
    if (paramreel == HUGE_VAL) 
    {
        fprintf(stderr, "Erreur : Le nombre réel contient trop de décimales ou n'est pas valide.\n");
        exit(EXIT_FAILURE);
    }

    printf("Chaine : %s\n", paramcc);
    printf("Paramentier : %ld\n", paramentier);
    printf("Paramreel : %f\n", paramreel);

    exit(EXIT_SUCCESS);
}