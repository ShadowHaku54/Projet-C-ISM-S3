#include <stdio.h>
#include "gestion_menu_choix.h"
#include "input.h"
#include "allouage_dynamique_str.h"
#include "view_sms.h"
#include "saisie_small_number.h"



int gestion_menu_choix(const char *tabMenu[], int taille)
{
    display_menu(tabMenu, taille);
    int choix = saisie_small_number("Faites votre choix :");

    if (choix == -1){
        return -1;
    }

    if (choix <= 0 || choix > taille){
        printf("Désolé! veuiller saisir un numéro entre 1 et %d\n", taille);
        return -1;
    }

    return choix;
}

void display_menu(const char *tabMenu[], int tailleMenu)
{
    int i;
    for (i = 0; i < tailleMenu; i++){
        printf("%d. %s\n", i+1, tabMenu[i]);
    }
}

