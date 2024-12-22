#include <string.h>
#include "convert_all.h"
#include "conversion.h"
#include <math.h>

char *convert_all_base_partInt(int bd, int ba, char *number)
{
    Very_Long_int decimal = convert_baseQ_to_decimal(bd, number);

    if (decimal == -1){
        return NULL;
    }

    return convert_decimal_to_baseQ(ba, decimal);
}

char *convert_all_base_partFract(int bd, int ba, char *number_after, int precision)
{
    Very_Long_int decimal = convert_baseQ_to_decimal(bd, number_after);

    if (decimal == -1){
        return NULL;
    }

    double deviseur = pow(bd, strlen(number_after));
    double fraction = decimal / deviseur;
    return convert_float_to_baseQ(ba, fraction, precision);
}
