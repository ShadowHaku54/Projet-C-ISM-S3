#include <string.h>
#include "split.h"
#include "allouage_dynamique_str.h"
#include <stdio.h>

#include <string.h>

void split(char *input, char sep, char **before, char **after)
{
    *before = NULL;
    *after = NULL;
    char *pos = strchr(input, sep);
    if (pos == NULL){
        int taille = strlen(input);
        puts("Allocation de before");
        alloue_str(before, taille + 1);
        printf("Allocation de before taille de sortie %d | adresse : %p\n", strlen(*before), (void *)*before);
        strncpy(*before, input, taille);
        (*before)[taille] = '\0';
    }
    else {
        int lenBefore = pos - input;
        puts("Allocation de before");
        alloue_str(before, lenBefore + 1);
        strncpy(*before, input, lenBefore);
        (*before)[lenBefore] = '\0';
        printf("Allocation de before taille de sortie %d | adresse : %p\n", strlen(*before), (void *)*before);

        char *reste = pos+1;
        int lenAfter = strlen(reste);
        puts("Allocation de after");
        alloue_str(after, lenAfter + 1);
        strncpy(*after, reste, lenAfter);
        (*after)[lenAfter] = '\0';
        printf("Allocation de after taille de sortie %d  | adresse : %p\n", strlen(*after), (void *)*after);

    }
}
