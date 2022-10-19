#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

/**
 * struct flags - struct containing flags to "turn on"
 * when a flag specifier is passed to _printf()
 * @plus: flag for the '+' character
 * @space: flag for the ' ' character
 * @hash: flag for the '#' character
 */
typedef struct flags
{
	int  plus;
	int space;
	int hash;
} flags_tag;

/**
 * struct selectPrintFn - struct to choose the right function depending
 * on the format specifier passed to _printf()
 * @c: format specifier
 * @f: pointer to the correct printing function
 */
typedef struct selectPrintFn
{
	char c;
	int (*f)(va_list ap, flags_tag *f);
} spf;

/* select_flag.c */
int select_flag(char s, flags_tag *f);

/* select_print.c*/
int (*select_print(char s))(va_list, flags_tag *);

int print_string(va_list list, flags_tag *f);
int print_char(va_list list, flags_tag *f);

int print_percent(va_list list, flags_tag *f);

/*print_numbers.c*/
int print_int(va_list list, flags_tag *f);
int count_digit(int i);
void print_number(int n);

/*write_functions.c*/
int _putchar(char c);
int _puts(char *str);

/* The target function */
int _printf(const char *format, ...);

#endif
