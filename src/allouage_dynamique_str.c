#include <stdio.h>
#include <stdlib.h>
#include "allouage_dynamique_str.h"

void alloue_str(char **str, int taille)
{
    *str = malloc(taille * sizeof(char));

    if (*str == NULL)
    {
        puts("Erreur système! L'allocation c'est mal déroulée.\nVEUILLEZ VERIFIER VOTRE ESPACE MEMOIRE");
        libere_alloue(str);
        exit(1);
    }
}

void libere_alloue(void *alloue)
{
    free(alloue);
}

