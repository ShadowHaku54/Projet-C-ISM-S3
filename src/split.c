#include "split.h"
#include "string.h"
#include "allouage_dynamique_str.h"

void split(char *input, char sep, char **before, char **after)
{
    char *pos = strchr(input, sep);

    if (pos == NULL){
        int taille = strlen(input);
        alloue_str(before, taille);
        strncpy(*before, input, taille);

        *after = NULL;
    }
    else {
        int lenBefore = pos - input;

        alloue_str(before, lenBefore + 1);
        strncpy(*before, input, lenBefore);
        before[lenBefore] = '\0';

        int lenAfter = strlen(pos + 1);
        alloue_str(after, lenAfter + 1);
        strncpy(*after, pos+1, lenAfter + 1);

    }
}
