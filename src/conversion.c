#include <string.h>
#include <stdio.h>
#include "conversion.h"
#include "checks.h"
#include "inverseChaine.h"
#include "allouage_dynamique_str.h"


int check_car_in_base(char c, int b)
{
    int decimal = convertir_car_en_decimal(c);
    if (decimal == -1 || decimal >= b){
        return 0;
    }
    return 1;
}

int checkBase(char *number, int base)
{
    for (int i = 0; number[i] != '\0'; i++){
        if (!check_car_in_base(number[i], base)){
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

int convert_baseQ_to_decimal(int bq, char *number)
{
    int decimal = 0;
    int N = strlen(number);
    int puissbq = 1;
    for(int i=N-1; i>=0; i--){
        int dec_equiv = convertir_car_en_decimal(number[i]);
        decimal += dec_equiv * puissbq;
        puissbq *= bq;
        printf("%c %d %d %d\n", number[i], dec_equiv, decimal, puissbq);
    }

    return decimal;
}

char* convert_decimal_to_baseQ(int bq, int decimal, size_t max_size)
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
