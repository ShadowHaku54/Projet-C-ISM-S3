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

void set_console_color(int textColor)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    // Obtenir les informations actuelles de la console
    if (GetConsoleScreenBufferInfo(hConsole, &csbi)) {
        // Extraire la couleur de fond actuelle (4 bits de poids forts)
        int backgroundColor = csbi.wAttributes & 0xF0;

        // Combiner la couleur de fond existante avec la nouvelle couleur de texte
        SetConsoleTextAttribute(hConsole, backgroundColor | (textColor & 0x0F));
    }
}
void set_background_color(int color)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD cellsWritten;
    COORD topLeft = {0, 0};

    // Obtenir les dimensions actuelles de la console
    if (!GetConsoleScreenBufferInfo(hConsole, &csbi)) {
        return; // Si la fonction échoue, on quitte
    }

    DWORD consoleSize = csbi.dwSize.X * csbi.dwSize.Y;

    // Remplir l'écran avec la couleur spécifiée
    FillConsoleOutputAttribute(hConsole, color, consoleSize, topLeft, &cellsWritten);

    // Effacer tout texte existant
    FillConsoleOutputCharacter(hConsole, ' ', consoleSize, topLeft, &cellsWritten);

    // Positionner le curseur en haut à gauche
    SetConsoleCursorPosition(hConsole, topLeft);
}

void set_text_color_ansi(int colorCode)
{
    printf("\033[%dm", colorCode);
}
