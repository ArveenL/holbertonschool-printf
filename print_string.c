#include "main.h"

/**
* - Handles %s arguments
*
*/
int print_string(va_list args)
{
	char *str = va_arg(args, char *);
	int i = 0, count = 0;

	if (str == NULL)
		str = "(null)";

	while (str[i])
	{
		count += _putchar(str[i]);
		i++;
	}

	return (count);
}

