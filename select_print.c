#include "main.h"
int (*select_print(char s))(va_list, flags_tag *)
{
	spf func_arr[] = {
		{'i', print_int},
		{'s', print_string},
		{'c', print_char},
		{'d', print_int},
		/* 
        {'u', print_unsigned},
		{'x', print_hex},
		{'X', print_hex_big},
		{'b', print_binary},
		{'o', print_octal},
		{'R', print_rot13},
		{'r', print_rev},
		{'S', print_bigS},
		{'p', print_address},
		{'%', print_percent}
        */
		};
	int flags = 4;

	register int i;

	for (i = 0; i < flags; i++)
    {
		if (func_arr[i].c == s)
			return (func_arr[i].f);
    }
	return (NULL);
}
