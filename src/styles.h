#ifndef __STYLES_H__
#define __STYLES_H__
void print_ligne(char starting[], char mid[], char ending[], int largeur);
void print_ligne_char(int largeur, char c[]);
void print_ligne_spaces(int largeur);
void affiche_lettre_par_lettre(const char *texte, int delai_ms);
void setConsoleColor(int textColor, int backgroundColor);
void fillConsoleBackground(int textColor, int backgroundColor);
void afficher_tables_bases(int base_depart, int base_arrive);
void afficher_resultat_apres_conversion(int base_depart, int base_arrive, char Sneg, const char *before, const char *after,
                                        const char *before_convertie, const char *after_convertie);
#endif // __STYLES_H__
