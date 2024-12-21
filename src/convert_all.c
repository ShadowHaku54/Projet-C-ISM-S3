#include <string.h>
#include "convert_all.h"
#include "conversion.h"
#include <stdio.h>
#include <math.h>

char *convert_all_base_partInt(int bd, int ba, char *number)
{
    Very_Long_int decimal = convert_baseQ_to_decimal(bd, number);

    if (decimal == -1){
        return NULL;
    }

    return convert_decimal_to_baseQ(ba, decimal, strlen(number));
}

char *convert_all_base_partFract(int bd, int ba, char *number_after, int precision)
{
    Very_Long_int decimal = convert_baseQ_to_decimal(bd, number_after);

    Very_Long_int deviseur = pow(10, strlen(number_after));
    double fraction = (double) decimal / deviseur;
    if (fraction == -1){
        return NULL;
    }

    return convert_float_to_baseQ(ba, fraction, precision);
}
