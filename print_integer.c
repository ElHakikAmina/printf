#include "main.h"
/**
 * print_int - Prints an integer.
 * @args: List of arguments.
 * @b: Buffer array to handle printing.
 * @f: flags that Calculates active flags.
 * @w: Width specification.
 * @p: Precision specification.
 * @s: Size specifier.
 *
 * Return: Number of characters printed.
 */
int print_integer(va_list args, char b[], int f, int w, int p, int s)
{
    int i = BUFFER_SIZE - 2;
    int is_negative = 0;
    long int n = va_arg(args, long int);
    unsigned long int num;

    n =  convert_number_size(n, s);

    if (n == 0)
        b[i--] = '0';

    b[BUFFER_SIZE - 1] = '\0';
    num = (unsigned long int)n;

    if (n < 0)
    {
        num = (unsigned long int)((-1) * n);
        is_negative = 1;
    }

    while (num > 0)
    {
        b[i--] = (num % 10) + '0';
        num /= 10;
    }

    i++;

    return (write_number(is_negative, i, b, f, w, p, s));
}
