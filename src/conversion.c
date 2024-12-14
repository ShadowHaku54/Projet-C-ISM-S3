#include <string.h>
#include <stdio.h>
#include "conversion.h"
#include "checks.h"
#include "inverseChaine.h"

#define MAX_CHAR 70

int checkBase(char *number, int base)
{
    int decimal;
    for (int i = 0; number[i] != '\0'; i++){
        decimal = convertir_car_en_decimal(number[i]);
        if(decimal== -1 || decimal>=base){
            return 0;
        }
    }
    return 1;
}

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

int convertBaseQtoDecimal(int bq, char *number)
{
    int decimal = 0;
    int N = strlen(number);
    int puissbq = 1;
    for(int i=N-1; i>=0; i--){
        int dec_equiv = convertir_car_en_decimal(number[i]);
        printf("%c %d %d\n", number[i], i, dec_equiv);
        decimal += dec_equiv * puissbq;
        puissbq *= bq;
    }

    return decimal;
}

char* convertDecimaltoBaseQ(int bq, int decimal)
{
    static char number[MAX_CHAR];

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
