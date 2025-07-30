#include "main.h"
#include <stdio.h>

int main(void)
{
    int len1, len2;

    len1 = _printf("Custom: Hello %c, %s%%!\n", 'X', "world");
    len2 = printf("Native: Hello %c, %s%%!\n", 'X', "world");

    _printf("Custom return: %d\n", len1);
    printf("Native return: %d\n", len2);

    return (0);
}

