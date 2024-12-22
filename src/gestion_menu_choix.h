#ifndef __GESTION_MENU_CHOIX__
#define __GESTION_MENU_CHOIX__
int gestion_menu_choix(const char *tabMenu[], int taille, const char *Title, int fontColor, int textColor, int borderColor);
void display_menu(const char *tabMenu[], int tailleMenu,
                  const char *titreMenu, int fontColor, int textColor,
                  int borderColor, int delayMs, int largeurMenu);
#endif // __GESTION_MENU_CHOIX__
