#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

typedef struct flags
{
    int  plus;
    int space;
    int hash;
} flags_tag;

typedef struct selectPrintFn
{
    char c;
    int (*f)(va_list ap, flags_tag *f);
} spf;

int select_flag(char s, flags_tag *f);

int _printf(const char *format, ...);

int print_string(va_list list, flags_tag *f);
int print_char(va_list list, flags_tag *f);

int print_percent(va_list list, flags_tag *f);

int _putchar(char c);
int _puts(char *str);




#endif