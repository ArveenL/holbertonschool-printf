#include <stdarg.h>
#include "main.h"

/**
 * print_number - prints an integer
 * @n: the integer to print
 *
 * Return: number of digits printed
 */
int print_number(int n)
{
	int count = 0;

	if (n / 10)
		count += print_number(n / 10);
	_putchar((n % 10) + '0');
	count++;
	return (count);
}

/**
 * _printf - cust.printf that looks for either a normal string
 *           or a %c or a %s or a %% or %d or %i, all within first argument
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
	int index = 0, len = 0, j, num;
	char c, *str;

	va_start(args, format);
	while (format[index] != '\0')
	{
		if (format[index] == '%' && format[index + 1] != '\0')
		{
			index++;
			if (format[index] == 'c')
			{
				c = va_arg(args, int);
				_putchar(c);
				len++;
			}
			else if (format[index] == 's')
			{
				str = va_arg(args, char *);
				for (j = 0; str[j] != '\0'; j++)
				{
					_putchar(str[j]);
					len++;
				}
			}
			else if (format[index] == '%')
			{
				_putchar('%');
				len++;
			}
			else if (format[index] == 'd' || format[index] == 'i')
			{
				num = va_arg(args, int);
				len += print_number(num);
			}
		}
		else
		{
			_putchar(format[index]);
			len++;
		}
		index++;
	}
	va_end(args);
	return (len);
}
