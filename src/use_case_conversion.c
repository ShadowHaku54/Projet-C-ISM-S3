#include "use_case_conversion.h"
#include "menus_useCase_conversion.h"
#include "gestion_menu_choix.h"
#include "use_case_conversion_utils.h"



int use_case_conversion()
{
    while (1) {
        int n = gestion_menu_choix(Menu_Conversion, TailleMenuConversion);

        if(n != -1){

            if (n == TailleMenuConversion){
                return 0;
            }
            else if (n == TailleMenuConversion-1){
                return 1;
            }

            else if (n == 1){
                if (!useCase_codage_or_transcodage(Menu_Codage, TailleMenuCodage, 1)){
                    return 0;
                }
            }
            else if (n == 2){
                if (!useCase_codage_or_transcodage(Menu_Decodage, TailleMenuDecodage, 0)){
                    return 0;
                }
            }
            else if (n == 3){
                UseCase_personalise();
            }

        }
    };
}

int useCase_codage_or_transcodage(const char *tabMenu[], int N, int statut)
{
    while (1){
        int n = gestion_menu_choix(tabMenu, N);

        if(n != -1){

            if (n == N){
                return 0;
            }
            else if (n == N-1){
                return 1;
            }

            underUseCase_saisieEtconversion(statut, n);
        }
    };
}


