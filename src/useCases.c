#include <stdio.h>
#include "useCases.h"
#include "display_menu.h"
#include "inputChoice.h"
#include "menu_codage.h"
#include "menu_decodage.h"
#include "menu_transcodage.h"


int useCaseCodage()
{
    int choix;
    int quit; // bool : pour quiter ou non
    do{

        display_menu(Menu_Codage, TailleMenuCodage);
        choix = inputChoice(TailleMenuCodage);
        switch(choix)
        {
        case 1:

            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            quit = 0;
            break;
        case 5:
            quit = 1;
            break;
        default:
            break;
        }

    } while(choix != TailleMenuCodage+1 && choix != TailleMenuCodage);

    return quit;
}
