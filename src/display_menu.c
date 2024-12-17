#include <stdio.h>
#include "display_menu.h"

void display_menu(const char *tabMenu[], int tailleMenu)
{
    int i;
    for (i = 0; i < tailleMenu; i++){
        printf("%d. %s\n", i+1, tabMenu[i]);
    }
}
