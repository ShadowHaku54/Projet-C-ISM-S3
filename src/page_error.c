#include "page_error.h"
#include "constantes_prog.h"
#include "styles.h"
#include <stdio.h>
#include <windows.h>

void page_error(char *message)
{
    system("cls");
    fillConsoleBackground(RED, LIGHT_RED);
    setConsoleColor(RED, LIGHT_RED);

    printf("\n\n");
    print_ligne_spaces(SCREEM / 2 - 6);
    printf("%s████████ ERROR ████████%s\n\n\n", ANSI_BLINK, ANSI_RESET);
    Sleep(500);

    setConsoleColor(BLUE, LIGHT_RED);
    print_ligne_spaces(MARGE_2);
    printf("⛔ Message d'erreur : %s ⛔\n\n\n", message);

    Sleep(500);
    setConsoleColor(GRAY, WHITE);
    print_ligne_spaces(MARGE_2);

    affiche_lettre_par_lettre("Appuyer pour continuer", DELAIS_MS);
    affiche_lettre_par_lettre("...", DELAIS_MS+1000);

    getchar();

    // Rétablir les paramètres par défaut
    fillConsoleBackground(BRIGHT_WHITE, BLACK);
    setConsoleColor(COLOR_TEXT_DEFAULT, BG_COLOR_DEFAULT);
}
