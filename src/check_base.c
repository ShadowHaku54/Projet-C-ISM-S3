#include "check_base.h"
#include "conversion_utils.h"

int check_car_in_base(char c, int b)
{
    int decimal = convertir_car_en_decimal(c);
    if (decimal == -1 || decimal >= b){
        return 0;
    }
    return 1;
}

int check_number_in_base(char *number, int base)
{
    for (int i = 0; number[i] != '\0'; i++){
        if (!check_car_in_base(number[i], base)){
            return 0;
        }
    }
    return 1;
}

int check_base(int base)
{
    return (base>=2 && base <= 36);
}

