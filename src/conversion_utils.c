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

int check_num_int_in_base(int n, int b)
{
    return (n >= 0 && n < b);
}

int check_number_in_base(char *number, int base)
{
    for (int i = 0; number[i] != '\0'; i++){
        int decimal = convertir_car_en_decimal(number[i]);
        if (!check_num_int_in_base(decimal, base)){
            return 0;
        }
    }
    return 1;
}



