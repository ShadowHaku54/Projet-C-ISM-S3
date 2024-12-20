#include "view_sms.h"
#include <stdio.h>
#include "checks.h"
#include "constantes_prog.h"


int view_char_isNull_after_input(char *value)
{
    if (value == NULL){
        puts("Erreur lors de la saisie. \nValeur trop grande ou comportement inantendue! \nRéessayer!\n");
        return 1;
    }
    return 0;
}

int view_char_is_number(char *value)
{
    if(!char_is_number(value)){
        puts("Erreur! Désolé veuillez saisir un entier!");
        return 0;
    }
    return 1;
}

int view_check_base(int base)
{
    if(base < MIN_BASE || base > MAX_BASE){
        printf("Erreur! Les bases valides sont entre %d et %d\n", MIN_BASE, MAX_BASE);
        return 0;
    }
    return 1;
}
