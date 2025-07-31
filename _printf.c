#include "main.h"

/**
 * _printf - Custom implementation of printf function
 * @format: Format string containing text and format specifiers
 *
 * Return: Number of characters printed (excluding null terminator),
 *         or -1 if format is NULL
 */
int _printf(const char *format, ...)
{
	va_list args; /* Variable to hold the list of arguments */
	int count = 0; /* Counter for characters printed */
	int i = 0; /* Index to traverse the format string */
	char c; /* Temporary variable to hold a single character */
	char *str; /* Pointer to hold string arguments */
	int j; /* Index counter for string traversal */

	/* Check if format string is NULL to prevent segmentation fault */
	if (format == NULL)
		return (-1);

	/* Initialize the variable argument list starting after format */
	va_start(args, format);

	/* Loop through each character in the format string */
	while (format[i])
	{
		/* Check if current character is a format specifier indicator */
		if (format[i] == '%')
		{
			/* Move to the next character to see the specifier type */
			i++;
			
			/* Safety check: if string ends after %, break the loop */
			if (format[i] == '\0')
				break;

			/* Handle different format specifiers */
			switch (format[i])
			{
			case 'c': /* Handle character format specifier */
				/* Get the next argument as int (chars promoted to int) */
				c = va_arg(args, int);
				/* Write the character to standard output */
				write(1, &c, 1);
				/* Increment the character count */
				count++;
				/* Exit this case */
				break;

			case 's': /* Handle string format specifier */
				/* Get the next argument as char pointer (string) */
				str = va_arg(args, char *);
				
				/* Handle NULL string by replacing with "(null)" */
				if (str == NULL)
					str = "(null)";
				
				/* Initialize string index counter */
				j = 0;
				
				/* Print each character of the string until null terminator */
				while (str[j])
				{
					/* Write current character to standard output */
					write(1, &str[j], 1);
					/* Increment character count */
					count++;
					/* Move to next character in string */
					j++;
				}
				/* Exit this case */
				break;

			case '%': /* Handle literal percent sign */
				/* Write a single percent character to output */
				write(1, "%", 1);
				/* Increment character count */
				count++;
				/* Exit this case */
				break;

			default: /* Handle unknown format specifiers */
				/* Print the % character as-is */
				write(1, "%", 1);
				/* Print the unknown specifier character */
				write(1, &format[i], 1);
				/* Add 2 to count (% + unknown char) */
				count += 2;
				/* Exit this case */
				break;
			}
		}
		else /* Current character is not a format specifier */
		{
			/* Write regular character directly to output */
			write(1, &format[i], 1);
			/* Increment character count */
			count++;
		}
		
		/* Move to the next character in format string */
		i++;
	}

	/* Clean up the variable argument list */
	va_end(args);
	
	/* Return total number of characters printed */
	return (count);
}
