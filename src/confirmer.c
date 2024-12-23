#include <stdio.h>
#include "confirmer.h"
#include "input.h"
#include "allouage_dynamique_str.h"
#include "view_sms.h"

int confirmer(char *sms)
{
    char *rep = NULL;
    char c;
    int non_ok;
    do{
        rep = input_data_small(sms);

        if (view_char_isNull_after_input(rep)){
            non_ok = 1;

        } else {
            c = rep[0];
            non_ok = (c != 'n' && c !='o' && c != '\0' && c != 'O' && c != 'N');

            if(non_ok){
                puts("\tMauvaise saisie!\n");
            }
        }

    }while(non_ok);
    libere_alloue(&rep);
    return (c ==  'o' || c == 'O');
}
