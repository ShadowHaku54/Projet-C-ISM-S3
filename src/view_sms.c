#include "view_sms.h"
#include <stdio.h>
#include "checks.h"
#include "constantes_prog.h"


int view_char_isNull_after_input(char *value)
{
    if (value == NULL){
        puts("ERREUR LORS DE LA SAISIE. \nVALEUR TROP GRANDE OU COMPORTEMENT INANTENDUE! \nREESSAYER!\n");
        return 1;
    }
    return 0;
}

int view_char_is_number(char *value)
{
    if(!char_is_number(value)){
        puts("ERREUR! DESOLE VEUILLEZ SAISIR UN ENTIER!");
        return 0;
    }
    return 1;
}

int view_check_base(int base)
{
    if(base < MIN_BASE || base > MAX_BASE){
        printf("ERREUR! LES BASES VALIDES SONT ENTRE %d ET %d\n", MIN_BASE, MAX_BASE);
        return 0;
    }
    return 1;
}
