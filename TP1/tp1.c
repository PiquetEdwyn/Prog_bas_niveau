#include <stdio.h>
#include <stdlib.h>

void echange(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void trier(int *a, int *b, int *c) 
{
    if (*a > *b) 
    {
        echange(a, b);
    }
    if (*b > *c) 
    {
        echange(b, c);
    }
    if (*a > *b) 
    {
        echange(a, b);
    }
}

void fois2(int *a) 
{
    *a *= 2;
}

void puissance2_par_adresse(int *x, int n) 
{
    *x = 1;
    for (int i = 0; i < n; i++) 
    {
        fois2(x);
    }
}

int puissance2(int n) 
{
    int result = 1;
    for (int i = 0; i < n; i++) 
    {
        fois2(&result);
    }
    return result;
}

void pgcd_ppcm(int x, int y, int *pgcd, int *ppcm) 
{
    int a = x, b = y;
    while (b != 0) 
    {
        int t = b;
        b = a % b;
        a = t;
    }
    *pgcd = a;
    *ppcm = (x / *pgcd) * y;
    
}

int main() 
{
    int choice;
    int x, y, z, n, pgcd, ppcm;

    while (1) 
    {
        printf("\nMenu\n");
        printf("1. Echange\n");
        printf("2. Trier\n");
        printf("3. Puissance2\n");
        printf("4. Puissance2 par adresse\n");
        printf("5.  Pgcd et ppcm \n");
        printf("0. Quitter\n");
        printf("Choisissez une option (0, 1, 2, 3, 4, 5): ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                printf("Entrez la valeur de x : ");
                scanf("%d", &x);
                printf("Entrez la valeur de y : ");
                scanf("%d", &y);
                printf("Avant l'échange: x = %d, y = %d\n", x, y);
                echange(&x, &y);
                printf("Après l'échange: x = %d, y = %d\n", x, y);
                break;

            case 2:
                printf("Entrez la valeur de x : ");
                scanf("%d", &x);
                printf("Entrez la valeur de y : ");
                scanf("%d", &y);
                printf("Entrez la valeur de z : ");
                scanf("%d", &z);
                printf("Avant le tri: x = %d, y = %d, z = %d\n", x, y, z);
                trier(&x, &y, &z);
                printf("Après le tri: x = %d, y = %d, z = %d\n", x, y, z);
                break;

            case 3:
                printf("Entrez la valeur de l'exposant n pour calculer 2^n: ");
                scanf("%d", &n);
                printf("2^%d = %d\n", n, puissance2(n));
                break;

            case 4:
                printf("Entrez la valeur de l'exposant n pour calculer 2^n par adresse: ");
                scanf("%d", &n);
                x = 1;
                puissance2_par_adresse(&x, n);
                printf("2^%d = %d\n", n, x);
                break;

             case 5:
                do 
                {
                    printf("Entrez deux nombres entiers non nuls (x et y): ");
                    scanf("%d %d", &x, &y);
                } while (x == 0 || y == 0);

                pgcd_ppcm(x, y, &pgcd, &ppcm);
                printf("Pour les nombres %d et %d, le PGCD est %d et le PPCM est %d.\n", x, y, pgcd, ppcm);
                break;

            case 0:
                return 0;

            default:
                printf("Valeur non reconnue.\n");
                break;
        }
    }
    return 0;
}