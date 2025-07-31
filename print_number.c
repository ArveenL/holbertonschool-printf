#include "main.h"
#include <unistd.h>

/**
 *
 *
 *
 */

int print_number_helper(int num)
{
	int count = 0;
	char digit;

	if (num / 10)
		count += print_number_helper(num / 10);

	digit = '0' + (num % 10);
	count += write(1, &digit, 1);

	return (count);
}

int print_number(va_list args)
{
	int num = va_arg(args, int);
	int count = 0;
	char neg = '-';

	if (num < 0)
	{
		write(1, &neg, 1);
		num = -num;
		count++;
	}

	count += print_number_helper(num);

	return (count);
}

