#ifndef __CONVERSION_H__
#define __CONVERSION_H__
typedef unsigned long long int Very_Long_int;
char *convert_decimal_to_baseQ(int bq, Very_Long_int decimal, int max_size);
Very_Long_int convert_baseQ_to_decimal(int bq, char *number);
#endif // CONVERSION_H
