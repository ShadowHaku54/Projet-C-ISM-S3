#include "allouage_dynamique_str.h"
#include <stdlib.h>

void alloue_str(char **str, int taille)
{
    *str = malloc(taille * sizeof(char));

    if (*str == NULL)
    {
        libere_alloue(str);
        exit(1);
    }
}

void libere_alloue(void *alloue)
{
    free(alloue);
}

