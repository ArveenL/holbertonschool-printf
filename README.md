Custom printf(_printf)
Arveen / Alexandre


Task 0
******

THE TASK:  
1.Build _printf.c using the prototype int _printf(const char *format, ...) 
2.The _printf.c must return number of characters printed 
3.Must use the following identifiers(%): %c(char) / %s(string) / %%(percentage)
4.Handle variadic function(...) accordingly to the identifiers

STRUCTURE OVERVIEW:
 1. Include 2 libraries (stdio.h for putchar, stdarg.h for variadic functions)
 2. Prototype
 3. Ingredients (declare variables)
 4. NULL checker
 5. va_start (using known variable first then check for mystery variables)
 6. WHILE LOOP through format string:
 *    - Regular character handling
 *    - %c (simple)
 *    - %s (loop)
 *    - %% (simplest)
 7. va_end
 8. Return count
                                          

Task 1
**********

THE TASK:  
1. Extend _printf.c to handle integer conversion specifiers
2. Must handle %d (decimal integer) and %i (integer - same as %d)
3. Must handle negative numbers correctly
4. Must convert integers to printable digit characters
5. Don't need to handle flag characters, field width, precision, or length modifiers

STRUCTURE OVERVIEW:
 1. Add new cases to existing switch statement:
    - case 'd': (decimal integer)
    - case 'i': (integer - same as %d)
 2. Integer extraction from mystery variables using va_arg(args, int)
 3. Handle negative numbers:
    - Print '-' sign
    - Work with positive value
 4. Integer to string conversion:
    - Extract individual digits
    - Convert digits to printable characters
    - Handle special case of zero
 5. Print each digit character using putchar()
 6. Count all printed characters (including minus sign)
 7. Return updated count



^G Help       ^O Write Out  ^F Where Is   ^K Cut        ^T Execute    ^C Location   M-U Undo
^X Exit       ^R Read File  ^\ Replace    ^U Paste      ^J Justify    ^/ Go To Line M-E Redo
