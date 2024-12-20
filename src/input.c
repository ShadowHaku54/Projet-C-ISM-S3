#include <stdio.h>
#include <string.h>

#include "input.h"
#include "allouage_dynamique_str.h"
#include "vider_tampon.h"
#include "supspace.h"
#include "constantes_prog.h"


char *input(char *sms, const int max_size)
{
    char TMP[max_size];
    puts(sms);
    printf(">%s", TAB);

    do{
        if (fgets(TMP, max_size, stdin) == NULL){
            return NULL;
        }
    } while(TMP[0] == '\n');

    char *pos = strchr(TMP, '\n');
    if (pos == NULL){
        vider_tampon();
        return NULL;
    }
    *pos = '\0';

    supspace(TMP);

    char *value = NULL;
    alloue_str(&value, strlen(TMP) + 1);
    strcpy(value, TMP);

    return value;
}


char *input_data_type_int(char *sms) {
    return input(sms, MAX_CHAR_INT);
}

char *input_data_small(char *sms) {
    return input(sms, MAX_SMALL_CHAR);
}

char *input_text(char *sms)
{
    return input(sms, MAX_CHAR);
}
