#include <stdio.h>


int inputChoice(int max)
{
    int choix;
    puts("Faites votre choix :");
    printf(">\t");
    scanf("%d", &choix);

    while(choix<=0 || choix>max+1){
        printf("Erreur! Saisir un nombre entre [0;%d]\n", max);
        printf(">\t");
        scanf("%d", &choix);
    }

    return choix;
}
