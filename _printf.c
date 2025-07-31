#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * _printf - Custom implementation of printf function
 * @format: Format string containing text and format specifiers
 *
 * Description: This function mimics the behavior of the standard printf
 * function. It processes a format string and outputs formatted text to
 * stdout. Supports conversion specifiers: %c, %s, and %%.
 *
 * Return: Number of characters printed (excluding null terminator),
 *         or -1 if format is NULL
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	int i = 0;
	char c;
	char *str;
	int j;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				break;

			switch (format[i])
			{
			case 'c':
				c = va_arg(args, int);
				write(1, &c, 1);
				count++;
				break;

			case 's':
				str = va_arg(args, char *);
				if (str == NULL)
					str = "(null)";
				j = 0;
				while (str[j])
				{
					write(1, &str[j], 1);
					count++;
					j++;
				}
				break;

			case '%':
				write(1, "%", 1);
				count++;
				break;

			default:
				write(1, "%", 1);
				write(1, &format[i], 1);
				count += 2;
				break;
			}
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
		i++;
	}

	va_end(args);
	return (count);
}
