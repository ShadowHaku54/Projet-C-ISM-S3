#include <stdio.h>
#include <string.h>

#include "input.h"
#include "allouage_dynamique_str.h"
#include "vider_tampon.h"

#define MAX_CHAR 10
#define TAB "   "

char *input(char *sms)
{
    char TMP[MAX_CHAR];
    puts(sms);
    printf(">%s", TAB);
    if (fgets(TMP, MAX_CHAR, stdin) == NULL){
        return NULL;
    }

    char *pos = strchr(TMP, '\n');
    if (pos == NULL){
        vider_tampon();
        return NULL;
    }
    else{
        *pos = '\0';
    }

    char *value = NULL;
    alloue_str(&value, strlen(TMP) + 1);
    strcpy(value, TMP);

    return value;
}
