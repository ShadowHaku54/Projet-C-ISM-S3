#include <stdio.h>
#include <stdlib.h>
#include "allouage_dynamique_str.h"

static size_t total_memory_allocated = 0;

void alloue_str(char **str, int taille)
{
    *str = NULL;
    *str = malloc(taille * sizeof(char));
    printf("%p\n", (void *)*str);
    if (*str == NULL)
    {
        puts("ERREUR SYSTEME! L'ALLOCATION C'EST MAL DEROULEE.\nVEUILLEZ VERIFIER VOTRE ESPACE MEMOIRE");
        printf("taille: %d\n", taille);
        printf("M�moire totale allou�e jusqu'ici : %zu octets\n", total_memory_allocated);
        exit(1);
    }
    else {
        puts("L'allocation r�ussi!");
        total_memory_allocated += 1;
    }
}

void libere_alloue(char **ptr)
{
    if(*ptr != NULL){
        free(*ptr);
        *ptr = NULL;
        total_memory_allocated -= 1;
    }
}

