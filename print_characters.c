#include "main.h"
int print_string(va_list l, flags_tag *f)
{
	char *s = va_arg(l, char *);

	(void)f;

	if (!s)
		s = "(null)";
	return (_puts(s));
}

int print_char(va_list l, flags_tag *f)
{
	(void)f;
	_putchar(va_arg(l, int));
	return (1);
}
