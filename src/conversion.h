#ifndef CONVERSION_H
#define CONVERSION_H
int checkBase(char *number, int base);
int check_car_in_base(char c, int b);
int convertir_car_en_decimal(char);
char convertir_decimal_en_car(int);
char* convert_decimal_to_baseQ(int bq, int decimal, size_t max_size);
int convert_baseQ_to_decimal(int bq, char *number);
#endif // CONVERSION_H
