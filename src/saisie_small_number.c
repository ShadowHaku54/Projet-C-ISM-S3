#include "saisie_small_number.h"
#include "input.h"
#include "view_sms.h"
#include "allouage_dynamique_str.h"
#include <stdlib.h>

int saisie_small_number(char *sms)
{
    char *base = input_data_small(sms);

    if(view_char_isNull_after_input(base)){
        return -1;
    }

    if(!view_char_is_number(base)){
        libere_alloue(&base);
        return -1;
    }

    int b = atoi(base);
    libere_alloue(&base);
    return b;
}
