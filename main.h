#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdarg.h>
#include <stdlib.h>

#ifndef MAIN_H
#define MAIN_H

int _putchar(char c);
void _puts(const char* str);
int _vprintf(const char* fmt, va_list args);
int _printf(const char* format, ...);


void unsigned_number_to_string(uint64_t number, int base, char *buffer);
void signed_number_to_string(int64_t number, int base, char *buffer);

char rev_string(char *s);




#endif
