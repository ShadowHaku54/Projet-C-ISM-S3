#include "checks.h"

int isNumber(char var)
{
    return (var>='0' && var<='9');
}

int isAlphabetMaj(char var)
{
    return (var>='A' && var<='Z');
}

int isAlphabetMins(char var)
{
    return (var>='a' && var<='z');
}

int char_is_number(char *var)
{
    int i = 0;
    while (var[i] != '\0'){
        if(!isNumber(var[i])){
            return 0;
        }
        i++;
    }
    return 1;
}
