#include "supspace.h"
#include <string.h>

void supspace(char *str)
{
    if (str == NULL || *str == '\0'){
        return;
    }

    char *start = str;
    while(*start == ' '){
        start++;
    }

    char *end = str + strlen(str) - 1;
    while(end > start && *end  == ' '){
        end--;
    }
    *(end + 1) = '\0';

    memmove(str, start, strlen(start) + 1);
}
