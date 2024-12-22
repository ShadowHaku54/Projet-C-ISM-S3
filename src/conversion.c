#include <string.h>
#include "conversion.h"
#include "conversion_utils.h"
#include "inverseChaine.h"
#include "allouage_dynamique_str.h"
#include <stdio.h>
#include "constantes_prog.h"
#include "copy_str_dyn.h"
#include <math.h>


Very_Long_int convert_baseQ_to_decimal(int bq, char *number)
{
    if (*number == '\0'){
        return -1;
    }

    Very_Long_int decimal = 0;
    int N = strlen(number);
    Very_Long_int puissbq = 1;

    for(int i=N-1; i>=0; i--){
        int dec_equiv = convertir_car_en_decimal(number[i]);

        if (!check_num_int_in_base(dec_equiv, bq)){
            return -1;
        }

        decimal += dec_equiv * puissbq;
        puissbq *= bq;
    }

    return decimal;
}

char *convert_decimal_to_baseQ(int bq, Very_Long_int decimal)
{
    if (decimal == 0) return "0";

    int max_size = calculate_int_digits(decimal, bq);
    printf("nombre de chiffre maximal pour l'entier : %d\n", max_size);
    puts("Allocation de la partie entière");
    char *number = NULL;
    alloue_str(&number, max_size + 1);

    int i = 0;
    while(decimal != 0){
        int reste = decimal % bq;
        number[i] = convertir_decimal_en_car(reste);
        decimal /= bq;
        i++;
    }

    number[i] = '\0';
    printf("Allocation de la partie entière taille de sortie %d  %s | adresse : %p\n", strlen(number), number, (void *)number);
    inverseChaine(number);
    return number;
}

char *convert_float_to_baseQ(int bq, double fraction_decimal, int precision)
{
    if (fraction_decimal == 0) return "0";


    char *resultat = NULL;
    puts("Allocation de partie flottante");
    alloue_str(&resultat, precision + 1);

    int i = 0;
    while(fraction_decimal > 0.0 && i < precision){
        fraction_decimal *= bq;
        int newVal = (int) fraction_decimal;
        resultat[i] = convertir_decimal_en_car(newVal);
        fraction_decimal -= newVal;
        i++;
    }
    resultat[i] = '\0';
    printf("Allocation de partie flottante taille de sortie %d | adresse : %p\n", strlen(resultat), (void *)resultat);

    return resultat;
}

int calculate_int_digits(Very_Long_int decimal, int ba)
{
    if (decimal == 0) return 1;
    return (int)(log(decimal) / log(ba)) + 1;
}

int calculate_fraction_digits(double fraction, int ba)
{
    return (int)(-log(fraction) / log(ba)) + 1;
}
