#include "view_sms.h"
#include <stdio.h>
#include "checks.h"
#include "constantes_prog.h"
#include "page_error.h"



int view_char_isNull_after_input(char *value)
{
    if (value == NULL){
        page_error("ERREUR LORS DE LA SAISIE. \n\tVALEUR TROP GRANDE OU COMPORTEMENT INANTENDUE!");
        return 1;
    }
    return 0;
}

int view_char_is_number(char *value)
{
    if(!char_is_number(value)){
        page_error("ERREUR! DESOLE VEUILLEZ SAISIR UN ENTIER!");
        return 0;
    }
    return 1;
}

static char message[50];

int view_check_base(int base)
{
    if(base < MIN_BASE || base > MAX_BASE){
        snprintf(message, sizeof(message), "ERREUR! LES BASES VALIDES SONT ENTRE %d ET %d\n", MIN_BASE, MAX_BASE);
        page_error(message);
        return 0;
    }
    return 1;
}
