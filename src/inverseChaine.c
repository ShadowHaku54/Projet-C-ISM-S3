#include <string.h>
#include "inverseChaine.h"

void inverseChaine(char *chaine)
{
    int N = strlen(chaine);

    int i=0, j=N-1;
    while(i<j){
        char tmp = chaine[i];
        chaine[i++] = chaine[j];
        chaine[j--] = tmp;
    }
}
