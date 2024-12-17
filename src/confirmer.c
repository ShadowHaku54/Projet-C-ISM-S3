#include <stdio.h>
#include "confirmer.h"
#include "input.h"
#include "allouage_dynamique_str.h"

int confirmer(char *sms)
{
    char *rep = NULL;
    char c;
    do{
        rep = input(sms);
        if (rep == NULL){
            puts("Erreur lors de la saisie. \nValeur trop grande ou comportement inantendue! \nRéessayer!\n");
            libere_alloue(rep);
        }
        c = rep[0];
    }while(c != 'n' && c !='o' && c != '\0');
    libere_alloue(rep);
    return (c ==  'o');
}
