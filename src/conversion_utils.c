#include "conversion_utils.h"
#include "checks.h"

int convertir_car_en_decimal(char num)
{
    if (isNumber(num)){
        return num - 48;
    }
    else if (isAlphabetMaj(num)){
        return num - 65 + 10;
    }
    else if (isAlphabetMins(num)){
        return num - 97 + 10;
    }
    return -1;
}

char convertir_decimal_en_car(int decimal)
{
    if(decimal>=0 && decimal<=9){
        return decimal + 48;
    }
    return decimal - 10 + 65;
}

