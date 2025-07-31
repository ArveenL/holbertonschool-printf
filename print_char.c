#include "main.h"

/**
* - Handles hte %c argument 
* 
*/
int print_char(va_list args)
{
	char c = va_arg(args, int);

	return (_putchar(c));
}

