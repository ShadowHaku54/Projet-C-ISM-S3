#include <stdio.h>
#include "vider_tampon.h"

void vider_tampon()
{
    int a;
    while((a = getchar()) != '\n' && a != EOF);
}
