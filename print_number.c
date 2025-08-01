#include "main.h"
#include <unistd.h>

/**
 *
 *
 *
 */

int print_number_helper(unsigned int n)
{
    int count = 0;
    char digit;

    if (n / 10)
        count += print_number_helper(n / 10);

    digit = '0' + (n % 10);
    count += write(1, &digit, 1);

    return count;
}

int print_number(va_list args)
{
    int num = va_arg(args, int);
    int count = 0;
    char neg = '-';
    unsigned int n;

    if (num < 0)
    {
        write(1, &neg, 1);
        n = (unsigned int)(-1 * (num + 1)) + 1;
        count++;
    }
    else
    {
        n = num;
    }

    count += print_number_helper(n);
    return count;
}

