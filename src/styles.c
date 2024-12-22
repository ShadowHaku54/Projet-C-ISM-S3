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

void afficher_tables(int base_depart, int base_arrive, int fontColor, int textColor, int borderColor, int marge)
{
    system("cls");
    printf("\n");

    setConsoleColor(borderColor, fontColor);
    print_ligne_spaces(marge);
    printf("╔════════════════╗                  ╔════════════════╗\n");
    print_ligne_spaces(marge);
    printf("║ ");

    setConsoleColor(textColor, fontColor);
    printf("Base de départ");

    setConsoleColor(borderColor, fontColor);
    printf(" ║        TO        ║ ");

    setConsoleColor(textColor, fontColor);
    printf("Base d'arrivée");

    setConsoleColor(borderColor, fontColor);
    printf(" ║\n");
    print_ligne_spaces(marge);
    printf("╠════════════════╣                  ╠════════════════╣\n");
    print_ligne_spaces(marge);
    printf("║");

    setConsoleColor(textColor, fontColor);
    if (base_depart != -1) {
        int cc = ((base_depart/10) == 0) ? 1 : 0;
        printf("%*s%d%*s", 7, "", base_depart, 7+cc, "");
    } else {
        printf("%*s", 16, " ");
    }
    setConsoleColor(borderColor, fontColor);
    printf("║                  ");

    printf("║");
    setConsoleColor(textColor, fontColor);
    if (base_arrive != -1) {
        int cc = (base_arrive / 10) == 0 ? 1 : 0;
        printf("%*s%d%*s", 7, "", base_arrive, 7+cc, "");
    } else {
        printf("%*s", 16, " ");
    }

    setConsoleColor(borderColor, fontColor);
    printf("║\n");
    print_ligne_spaces(marge);
    printf("╚════════════════╝                  ╚════════════════╝\n\n\n");

    setConsoleColor(textColor, fontColor);
}
