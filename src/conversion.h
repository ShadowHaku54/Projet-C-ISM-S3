#ifndef __CONVERSION_H__
#define __CONVERSION_H__
typedef unsigned long long int Very_Long_int;
char *convert_decimal_to_baseQ(int bq, Very_Long_int decimal);
Very_Long_int convert_baseQ_to_decimal(int bq, char *number);
char *convert_float_to_baseQ(int bq, double fraction_decimal, int precision);
int calculate_int_digits(Very_Long_int decimal, int ba);
int calculate_fraction_digits(double fraction, int ba);

#endif // CONVERSION_H
