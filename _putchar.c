#include "main.h"

/**
 * _putchar - writes ONE character to stdout/screen
 * @c: The character to print
 *
 * Return: On success 1
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
