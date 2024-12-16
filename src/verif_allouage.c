#include "verif_allouage.h"

void libere_alloue(void *alloue)
{
    if (alloue == NULL){
        exit(1);
    }
}

void alloue_str(char **str, size_t taille)
{
    *str = malloc(taille * sizeof(char));

    if (*str == NULL) exit(1);
}
