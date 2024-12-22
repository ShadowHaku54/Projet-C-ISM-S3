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

