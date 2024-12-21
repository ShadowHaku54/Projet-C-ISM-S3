#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "gestion_menu_choix.h"
#include "input.h"
#include "allouage_dynamique_str.h"
#include "view_sms.h"
#include "saisie_small_number.h"
#include "styles.h"
#include "constantes_prog.h"


int gestion_menu_choix(const char *tabMenu[], int taille, const char *Title)
{

    display_menu(tabMenu, taille, Title, COLOR_BORDER_HIGHLIGHT, COLOR_TEXT_DEFAULT, DELAIS_MS, LARGEUR);
    int choix = saisie_small_number("FAITES VOTRE CHOIX :");

    if (choix == -1){
        return -1;
    }

    if (choix <= 0 || choix > taille){
        printf("DÉSOLÉ! VEUILLER SAISIR UN NUMÉRO ENTRE 1 ET %d\n", taille);
        return -1;
    }

    return choix;
}

void display_menu(const char *tabMenu[], int tailleMenu, const char *titreMenu, int borderColor, int textColor, int delayMs, int largeurMenu)
{
    set_console_color(borderColor);
    print_ligne("╔", "═", "╗", largeurMenu);
    print_ligne("║", " ", "║", largeurMenu);

    int titreLen = strlen(titreMenu);
    int padding = (largeurMenu - titreLen) / 2;

    print_ligne_spaces(SCREEM);
    printf("║");

    set_console_color(textColor);
    for (int i = 0; i < padding; i++) printf(" ");
    affiche_lettre_par_lettre(titreMenu, delayMs);

    set_console_color(borderColor);
    print_ligne_spaces(largeurMenu - titreLen - padding);
    printf("║\n");

    print_ligne("║", " ", "║", largeurMenu);
    print_ligne("╠", "═", "╣", largeurMenu);

    for (int i = 0; i < tailleMenu ; i++) {
        set_console_color(borderColor);
        int optionLen = snprintf(NULL, 0, " %d ⮞ %s", i + 1, tabMenu[i]);

        print_ligne("║", " ", "║", largeurMenu);
        print_ligne_spaces(SCREEM);
        printf("║");
        set_console_color(textColor);
        printf(" %d ⮞%s", i + 1, TAB);
        affiche_lettre_par_lettre(tabMenu[i], delayMs);

        set_console_color(borderColor);
        print_ligne_spaces(largeurMenu - optionLen);
        puts("║");

        if (i < tailleMenu - 1){
            print_ligne("║", ".", "║", largeurMenu);
        }
    }

    print_ligne("╚", "═", "╝", largeurMenu);
    set_console_color(textColor);
}


