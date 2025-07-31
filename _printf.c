#include <stdio.h> /* for putchar */
#include <stdarg.h> /* for variadic functions */
int _printf(const char *format, ...)
{
va_list args; /* tool to handle mystery variables (...) */
int count = 0; /* start counter for characters being printed */
int i = 0; /* index to walk through format string */
char c; /* storage for single characters from %c */
char *str; /* pointer for strings from %s */
int j; /* counter for looping through strings */
if (format == NULL) return (-1); /* null checker - see if there are format strings or not */
va_start(args, format); /* va_start - using known variable first then check for mystery variables */
while (format[i]) /* while loop through 'format string' to check each char one by one */
{
if (format[i] == '%') /* check if current character is % (format specifier) */
{
i++; /* move past the % to see what comes next */
if (format[i] == '\0') break; /* safety check - make sure string doesn't end right after % */
switch (format[i]) /* handle different format specifiers */
{
case 'c': /* c is simple - handle single character */
c = va_arg(args, int); /* grab character from mystery variables */
putchar(c); /* print it directly */
count++; /* count it (just 1) */
break; /* exit */
case 's': /* %s requires a loop - handle string */
str = va_arg(args, char *); /* grab string pointer from mystery variables */
if (str == NULL) str = "(null)"; /* safety check for null strings */
j = 0; /* start at beginning of string */
while (str[j]) /* while not at end of string */
{
putchar(str[j]); /* print this character */
count++; /* count this character */
j++; /* move to next character */
}
break; /* exit */
case '%': /* prints literal % symbol */
putchar('%'); /* prints literal %, no mystery variables needed */
count++; /* count it(just 1) */
break; /* exit */
default: /* handles unknown specifiers - print % and the character */
putchar('%'); /* prints the % */
putchar(format[i]); /* prints the unknown character */
count += 2; /* counts both characters */
break;
}
}
else /* regular character handling - if not %, just print it */
{
putchar(format[i]); /* print the normal character */
count++; /* count it */
}
i++; /* move to next character in format string */
}
va_end(args); /* clean up variable argument list */
return (count); /* return count i.e total number of characters printed */
}
