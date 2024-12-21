#include <stdlib.h>
#include "use_case_conversion.h"
#include "menus_useCase_conversion.h"
#include "gestion_menu_choix.h"
#include "use_case_conversion_utils.h"


int use_case_conversion()
{
    while (1) {
        int n = gestion_menu_choix(Menu_Conversion, TailleMenuConversion, NameMenuConversion);

        if(n != -1){

            if (n == TailleMenuConversion){
                return 0;
            }
            else if (n == TailleMenuConversion-1){
                return 1;
            }

            else if (n == 1){
                if (!useCase_codage_or_transcodage(Menu_Codage, TailleMenuCodage, 1, NameMenuCodage)){
                    return 0;
                }
            }
            else if (n == 2){
                if (!useCase_codage_or_transcodage(Menu_Decodage, TailleMenuDecodage, 0, NameMenuDecodage)){
                    return 0;
                }
            }
            else if (n == 3){
                UseCase_personalise();
            }
            else if (n == 4){
                // complémnt à deux
            }
            else if (n == 5){
                // historique
            }
        }
    };
}



