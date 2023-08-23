#include "main.h"
/*  print_octal_number :  FUNCTION THAT PRINT UNSIGNED NUMBER IN OCTAL  */
/**
 * print_octal_number - Prints an unsigned number in octal notation
 * @types: Lista of arguments
 * @b: Buffer array to handle print
 * @f: flags that  Calculates active flags
 * @w: w for width - get width
 * @p: p for Precision specification
 * @s: s for Size specifier
 * Return: Number of chars printed
 */
int print_octal_number(va_list types, char b[],
	int f, int w, int p, int s)
{

	int i = BUFFER_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(w);

	num = convert_unsigned_size(num, s);

	if (num == 0)
		b[i--] = '0';

	b[BUFFER_SIZE - 1] = '\0';

	while (num > 0)
	{
		b[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (f & FLAG_HASH && init_num != 0)
		b[i--] = '0';

	i++;

	return (write_unsigned(0, i, b, f, w, p, s));
}
