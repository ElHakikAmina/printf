#include "main.h"
/*  uppercase hexadecimal notation  */

/**
 * print_hexa_upper - uppercase hexadecimal notation
 * @types: this variable contains list of arguments
 * @b: Buffer - array to handle print
 * @f: flags - Calculates active flags
 * @w:  width
 * @p: Precision 
 * @s: size
 * Return: the number of characters that is  printed
 */
int print_uppercase_hexadecimal(va_list types, char b[],
	int f, int w, int p, int s)
{
	return (print_hexadecimal(types, "0123456789ABCDEF", b,
		f, 'X', w, p, s));
}
