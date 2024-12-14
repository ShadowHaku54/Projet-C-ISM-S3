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
