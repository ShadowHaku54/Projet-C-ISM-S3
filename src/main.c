#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <locale.h> // affiche les cract�res spr�ciaux sur le terminal
// LES MENUS
#include "menu_main.h"
#include "menu_codage.h"
#include "menu_decodage.h"
#include "menu_transcodage.h"

#include "conversion.h"
#include "input.h"

// FONCTIONNALITES AFFICHAGE
#include "display_menu.h"

#include "inputChoice.h"


int main()
{
    setlocale(LC_ALL, ""); // permet d'afficher les caract�res sp�ciaux

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

//    char nbr[] = "A45B96";
//    char *decimal_car = "10771350";
//    int bq = 8;
//    int decimal = convert_baseQ_to_decimal(10, decimal_car);
//    char *octal = convert_decimal_to_baseQ(bq, decimal, strlen(decimal_car));
//    printf("%s en decimal vaut %d en base 10\n", decimal_car, decimal);
//    printf("%d en decimal vaut %s en base %d\n", decimal, octal, bq);
//    libere_alloue(octal);

    char *test = input("Entrer un nombre :");
    puts(test);


    return 0;
}


