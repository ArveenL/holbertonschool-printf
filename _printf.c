#include "main.h"

/**
*
*
*
*
*/
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0;
	char current;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			if (format[i] == 'c')
				count += print_char(args);
			else if (format[i] == 's')
				count += print_string(args);
			else if (format[i] == '%')
				count += _putchar('%');
			else
			{
				count += _putchar('%');
				count += _putchar(format[i]);
			}
		}
		else
		{
			current = format[i];
			count += _putchar(current);
		}
		i++;
	}

	va_end(args);
	return (count);
}

