#include <stdio.h>
#include "confirmer.h"
#include "input.h"
#include "allouage_dynamique_str.h"

int confirmer(char *sms)
{
    char *rep = NULL;
    char c;
    int non_ok;
    do{
        rep = input_data_small(sms);
        if (rep == NULL){
            puts("Erreur lors de la saisie. \nValeur trop grande ou comportement inantendue! \nRéessayer!\n");
            continue;
        }
        c = rep[0];
        non_ok = (c != 'n' && c !='o' && c != '\0' && c != 'O' && c != 'N');

        if(non_ok){
            puts("Mauvaise saisie!\n");
        }
    }while(non_ok);
    libere_alloue(rep);
    return (c ==  'o' || c == 'O');
}
