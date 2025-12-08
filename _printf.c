#include "main.h"
#include <stdarg.h>

/**
 * _printf - cust.printf that looks for either a normal string
 *           or a %c or a %s or a %%, all within first argument
 * @format: the first argument in question, just a normal string,
 *          and may contain above identifiers
 * ...: takes more arguments to fill in any specifiers that may
 *      appear in first argument
 *
 * Return: count of length of first argument excluding '\0'
 */

int _printf(const char *format, ...)
{
	va_list args;
	int i = 0;
	int len = 0;
	char c;
	char *str;
	int j;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
			{
				c = va_arg(args, int);
				_putchar(c);
				len++;
			}
			else if (format[i] == 's')
			{
				str = va_arg(args, char *);
				if (str == NULL)
					str = "(null)";
				for (j = 0; str[j] != '\0'; j++)
				{
					_putchar(str[j]);
					len++;
				}
			}
			else if (format[i] == '%')
			{
				_putchar('%');
				len++;
			}
		}
		else
		{
			_putchar(format[i]);
			len++;
		}
		i++;
	}

	va_end(args);
	return (len);
}
