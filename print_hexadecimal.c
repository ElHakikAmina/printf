#include "main.h"
/***** PRINT  IN LOWERCASE OR UPPERCASE *****/
/**
 * print_hexa - Prints a hexadecimal number in lowercase or uppercase
 * @types: variable contains a list of arguments
 * @map_to: Array of values to map the number to
 * @b: Buffer 
 * @f: flags
 * @flag_ch: Calculates active flags
 * @w: width
 * @p: Precision
 * @s: Size
 * @s: Size
 * Return: Number of chars printed
 */
int print_hexadecimal(va_list types, char map_to[], char b[],
	int f, char flag_ch, int w, int p, int s)
{
	int index = BUFFER_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(w);

	num = convert_unsigned_size(num, s);

	if (num == 0)
		b[index--] = '0';

	b[BUFFER_SIZE - 1] = '\0';

	while (num > 0)
	{
		b[index--] = map_to[num % 16];
		num /= 16;
	}

	if (f & FLAG_HASH && init_num != 0)
	{
		b[index--] = flag_ch;
		b[index--] = '0';
	}

	index++;

	return (write_unsigned(0, index, b, f, w, p, s));
}
