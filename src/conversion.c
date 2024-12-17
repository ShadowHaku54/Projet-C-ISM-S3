#include <string.h>
#include "conversion.h"
#include "conversion_utils.h"
#include "inverseChaine.h"
#include "allouage_dynamique_str.h"


int convert_baseQ_to_decimal(int bq, char *number)
{
    int decimal = 0;
    int N = strlen(number);
    int puissbq = 1;
    for(int i=N-1; i>=0; i--){
        int dec_equiv = convertir_car_en_decimal(number[i]);
        decimal += dec_equiv * puissbq;
        puissbq *= bq;
    }

    return decimal;
}


char *convert_decimal_to_baseQ(int bq, int decimal, int max_size)
{
    char *number = NULL;
    alloue_str(&number, max_size);

    int i = 0;
    while(decimal != 0){
        int reste = decimal % bq;
        number[i++] = convertir_decimal_en_car(reste);
        decimal /= bq;
    }
    number[i] = '\0';

    inverseChaine(number);
    return number;
}
