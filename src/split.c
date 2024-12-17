#include <string.h>
#include "split.h"
#include "allouage_dynamique_str.h"

void split(char *input, char sep, char **before, char **after)
{
    *before = NULL;
    *after = NULL;
    char *pos = strchr(input, sep);
    if (pos == NULL){
        int taille = strlen(input);
        alloue_str(before, taille + 1);
        strncpy(*before, input, taille);
        (*before)[taille] = '\0';

        *after = NULL;
    }
    else {
        int lenBefore = pos - input;
        alloue_str(before, lenBefore + 1);
        strncpy(*before, input, lenBefore);
        (*before)[lenBefore] = '\0';

        char *reste = pos+1;
        int lenAfter = strlen(reste);
        alloue_str(after, lenAfter + 1);
        strncpy(*after, reste, lenAfter + 1);
    }
}
