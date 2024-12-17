#include "convert_all.h"
#include "conversion.h"
#include <string.h>

char *convert_all_base(int bd, int ba, char *number)
{
    int decimal = convert_baseQ_to_decimal(bd, number);
    return convert_decimal_to_baseQ(ba, decimal, strlen(number));
}
