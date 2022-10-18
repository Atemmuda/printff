#include "main.h"

/**
 * select_flag - select flag for printf when a flag modifier 
 * is found in the format string
 * @s: character that holds the flag specifier
 * @f: pointer to the struct flags in which we turn the flags on
 *
 * Return: 1 if a flag has been turn on, else 0
 */

 int select_flag(char s, flags_tag *f)
 {
    int i = 0;

    switch (s)
    {
        case '+':
            f->plus = 1;
            i = 1;
            break;
        case ' ':
			f->space = 1;
			i = 1;
			break;
		case '#':
			f->hash = 1;
			i = 1;
			break;
    }

    return (i);
 }