#include "main.h"

/**
 * _printf - prints output specified by a format
 * @fmt: format string containing the characters and the specifiers
 * Description: this function will call the select_print() function that will
 * determine which printing function to call depending on the conversion
 * specifiers contained into fmt
 * Return: length of the formatted output string
 */

int _printf(const char *fmt, ...)
{
	int (*pfunc)(va_list, flags_tag *);
	const char *p;
	va_list args;
	flags_tag flags = {0, 0, 0};

	register int count = 0;

	va_start(args, fmt);
	if (!fmt || (fmt[0] == '%' && !fmt[1]))
		return (-1);
	if (fmt[0] == '%' && fmt[1] == ' ' && !fmt[2])
		return (-1);
	for (p = fmt; *p; p++)
	{
		if (*p == '%')
		{
			p++;
			if (*p == '%')
			{
				count += _putchar('%');
				continue;
			}
			while (select_flag(*p, &flags))
				p++;
			pfunc = select_print(*p);
			count += (pfunc)
				? pfunc(args, &flags)
				: _printf("%%%c", *p);
		} else
			count += _putchar(*p);
	}
	_putchar(-1);
	va_end(args);
	return (count);
}
