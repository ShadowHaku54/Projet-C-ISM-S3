#include <stdio.h>
#include <windows.h>
#include "styles.h"
#include "constantes_prog.h"

void print_ligne(char starting[], char mid[], char ending[], int largeur)
{
    print_ligne_spaces(SCREEM);
    printf("%s", starting);
    print_ligne_char(largeur, mid);
    printf("%s\n", ending);
}

void print_ligne_spaces(int largeur)
{
    print_ligne_char(largeur, " ");
}

void print_ligne_char(int largeur, char c[])
{
    for(int i = 0; i < largeur; i++) printf("%s", c);
}

void affiche_lettre_par_lettre(const char *texte, int delai_ms)
{
    for (const char *ptr = texte; *ptr != '\0'; ptr++) {
        putchar(*ptr);
        fflush(stdout);
        Sleep(delai_ms);
    }
}

void setConsoleColor(int textColor, int backgroundColor)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (backgroundColor << BG_COLOR_SHIFT) | textColor);
}


void fillConsoleBackground(int textColor, int backgroundColor)
{
    system("cls");
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    DWORD cellsWritten;
    DWORD consoleSize;

    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);

    consoleSize = consoleInfo.dwSize.X * consoleInfo.dwSize.Y;
    int attribute = (backgroundColor << BG_COLOR_SHIFT) | textColor;

    FillConsoleOutputAttribute(hConsole, attribute, consoleSize, (COORD){0, 0}, &cellsWritten);

    FillConsoleOutputCharacter(hConsole, ' ', consoleSize, (COORD){0, 0}, &cellsWritten);

    SetConsoleCursorPosition(hConsole, (COORD){0, 0});
}

void afficher_tables_bases(int base_depart, int base_arrive)
{
    system("cls");
    printf("\n");

    setConsoleColor(BORDER_COLOR_DEFAULT, BG_COLOR_DEFAULT);
    print_ligne_spaces(MARGE_1);
    printf("╔════════════════╗                  ╔════════════════╗\n");
    print_ligne_spaces(MARGE_1);
    printf("║ ");

    setConsoleColor(COLOR_TEXT_DEFAULT, BG_COLOR_DEFAULT);
    printf("Base de départ");

    setConsoleColor(BORDER_COLOR_DEFAULT, BG_COLOR_DEFAULT);
    printf(" ║        TO        ║ ");

    setConsoleColor(COLOR_TEXT_DEFAULT, BG_COLOR_DEFAULT);
    printf("Base d'arrivée");

    setConsoleColor(BORDER_COLOR_DEFAULT, BG_COLOR_DEFAULT);
    printf(" ║\n");
    print_ligne_spaces(MARGE_1);
    printf("╠════════════════╣                  ╠════════════════╣\n");
    print_ligne_spaces(MARGE_1);
    printf("║");

    setConsoleColor(COLOR_TEXT_DEFAULT, BG_COLOR_DEFAULT);
    if (base_depart != -1) {
        int cc = ((base_depart/10) == 0) ? 1 : 0;
        printf("%*s%d%*s", 7, "", base_depart, 7+cc, "");
    } else {
        printf("%*s", 16, " ");
    }
    setConsoleColor(BORDER_COLOR_DEFAULT, BG_COLOR_DEFAULT);
    printf("║                  ");

    printf("║");
    setConsoleColor(COLOR_TEXT_DEFAULT, BG_COLOR_DEFAULT);
    if (base_arrive != -1) {
        int cc = (base_arrive / 10) == 0 ? 1 : 0;
        printf("%*s%d%*s", 7, "", base_arrive, 7+cc, "");
    } else {
        printf("%*s", 16, " ");
    }

    setConsoleColor(BORDER_COLOR_DEFAULT, BG_COLOR_DEFAULT);
    printf("║\n");
    print_ligne_spaces(MARGE_1);
    printf("╚════════════════╝                  ╚════════════════╝\n\n\n");

    setConsoleColor(COLOR_TEXT_DEFAULT, BG_COLOR_DEFAULT);
}


void afficher_resultat_apres_conversion(int base_depart, int base_arrive, char Sneg, const char *before, const char *after,
                                        const char *before_convertie, const char *after_convertie)
{
    system("cls");
    const int local_color_text = COLOR_TEXT_DEFAULT;
    const int local_color_border = BORDER_COLOR_DEFAULT;
    const int background = BG_COLOR_DEFAULT;

    int point;

    int signe_neg = (Sneg == '-')? 1:0;

    int len_depart = strlen(before) + signe_neg;
    if (after != NULL){
        len_depart += strlen(after);
    }

    int len_arrive = strlen(before_convertie) + signe_neg;
    if (after_convertie != NULL){
        len_arrive += strlen(after_convertie);
    }

    int taille_col_3 = len_depart > len_arrive ? len_depart : len_arrive;
    taille_col_3 += 4;

    printf("\n\n\n\n\n");
    print_ligne_spaces(SCREEM + MARGE_1/2 - 7);
    setConsoleColor(GREEN, background);
    printf("RESULTAT");
    setConsoleColor(local_color_border, background);
    printf("\n");
    print_ligne_spaces(MARGE_1);
    printf("╔════════════╦════════════════╦");
    for (int i = 0; i < taille_col_3; i++) printf("═");
    printf("╗\n");

    print_ligne_spaces(MARGE_1);
    printf("║   ");

    setConsoleColor(local_color_text, background);
    printf("DEPART");

    setConsoleColor(local_color_border, background);
    printf("   ║    ");

    setConsoleColor(local_color_text, background);
    printf("Base %-2d", base_depart);

    setConsoleColor(local_color_border, background);
    printf("     ║ ");

    setConsoleColor(local_color_text, background);
    if (signe_neg) printf("-");
    affiche_lettre_par_lettre(before, DELAIS_MS);

    point = 0;
    if (after != NULL){
        printf(".");
        point= 1;
        affiche_lettre_par_lettre(after, DELAIS_MS);
    }

    setConsoleColor(local_color_border, background);
    printf("%*s║\n", (taille_col_3 - len_depart -point -1), "");

    print_ligne_spaces(MARGE_1);
    printf("╠════════════╬════════════════╬");
    print_ligne_char(taille_col_3, "═");
    printf("╣\n");

    print_ligne_spaces(MARGE_1);
    printf("║   ");

    setConsoleColor(local_color_text, background);
    printf("ARRIVE");

    setConsoleColor(local_color_border, background);
    printf("   ║    ");

    setConsoleColor(local_color_text, background);
    printf("Base %-2d", base_arrive);

    setConsoleColor(local_color_border, background);
    printf("     ║ ");

    setConsoleColor(local_color_text, background);
    if (signe_neg) printf("-");
    affiche_lettre_par_lettre(before_convertie, DELAIS_MS);

    point = 0;
    if (after_convertie != NULL){
        point = 1;
        printf(".");
        affiche_lettre_par_lettre(after_convertie, DELAIS_MS);
    }

    setConsoleColor(local_color_border, background);
    printf("%*s║\n", (taille_col_3 - len_arrive - point -1), "");

    print_ligne_spaces(MARGE_1);
    printf("╚════════════╩════════════════╩");
    print_ligne_char(taille_col_3, "═");
    printf("╝\n");

    setConsoleColor(local_color_text, background);
}
