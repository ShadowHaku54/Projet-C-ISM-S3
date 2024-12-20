#ifndef __STYLES_H__
#define __STYLES_H__
void print_ligne(char starting[], char mid[], char ending[], int largeur);
void print_ligne_char(int largeur, char c[]);
void print_ligne_spaces(int largeur);
void affiche_lettre_par_lettre(const char *texte, int delai_ms);
void set_console_color(int textColor);
void set_background_color(int color);
void set_text_color_ansi(int colorCode);
#endif // __STYLES_H__
