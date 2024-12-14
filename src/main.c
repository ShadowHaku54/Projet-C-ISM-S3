#include <stdio.h>
#include <stdlib.h>
#include<locale.h> // affiche les cractères spréciaux sur le terminal
// LES MENUS
#include "menu_main.h"
#include "menu_codage.h"
#include "menu_decodage.h"
#include "menu_transcodage.h"

#include "conversion.h"

// FONCTIONNALITES AFFICHAGE
#include "display_menu.h"

#include "inputChoice.h"


int main()
{
    setlocale(LC_ALL, ""); // permet d'afficher les caractères spéciaux

//    int choixP;
//
//    do{
//
//        display_menu(Menu_Main, TailleMenuMain);
//        choixP = inputChoice(TailleMenuMain);
//
//        switch(choixP)
//        {
//        case 1 :
//            display_menu(Menu_Codage, TailleMenuCodage);
//            break;
//        case 2 :
//            display_menu(Menu_Decodage, TailleMenuDecodage);
//            break;
//        case 3 :
//            display_menu(Menu_Transcodage, TailleMenuTranscodage);
//            break;
//        default:
//            break;
//        }
//
//    } while (choixP != TailleMenuMain+1);

    char nbr[] = "A45B96";
    int decimal = 10771350;
    int bq = 8;
    printf("%d en decimal vaut %s en base %d\n", decimal, convertDecimaltoBaseQ(bq, decimal), bq);

    return 0;
}


