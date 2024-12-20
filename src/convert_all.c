#include <string.h>
#include "convert_all.h"
#include "conversion.h"

char *convert_all_base(int bd, int ba, char *number)
{
    Very_Long_int decimal = convert_baseQ_to_decimal(bd, number);

    if (decimal == -1){
        return NULL;
    }

    return convert_decimal_to_baseQ(ba, decimal, strlen(number));
}
