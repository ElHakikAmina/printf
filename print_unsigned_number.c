#include "main.h"
/************************* PRINT UNSIGNED NUMBER *************************/
/**
 * print_unsigned - Prints an unsigned number
 * @types: List a of arguments
 * @b: Buffer array to handle print
 * @f: flags Calculates active flags
 * @w: get width
 * @p: Precision specification
 * @s: Size specifier
 * Return: Number of chars printed.
 */


 /****** FUNCTION THAT PRINT UNSIGNED NUMBER ******/
/**
 * print_unsigned_number - Prints an unsigned number.
 * @types: contains list of arguments.
 * @b: b for Buffer - array for printing.
 * @f: f for flag - Flag options that determine formatting.
 * @w:  w for width - Width specification.
 * @p:  p for precision - Precision specification.
 * @s: s for size - Size specifier.
 *
 * Return: The number of characters printed.
 */

int print_unsigned_number(va_list types, char b[],
	int f, int w, int p, int s)
{
	int i = BUFFER_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
/*convert_unsigned_size*/
	num = convert_unsigned_size(num, s);

	if (num == 0)
		b[i--] = '0';

	b[BUFFER_SIZE - 1] = '\0';

	while (num > 0)
	{
		b[i--] = (num % 10) + '0';
		num /= 10;
	}
    i=i+1;
	

	return (write_unsigned(0, i, b, f, w, p, s));
}

