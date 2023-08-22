#include "main.h"
/**
 * print_hexadecimal - Prints an unsigned number in hexadecimal notation
 * @types: Lista of arguments
 * @b: Buffer array to handle print
 * @f:  Calculates active flags
 * @w: get width
 * @p: Precision specification
 * @s: Size specifier
 * Return: Number of chars printed
 */
int print_hexadecimal_number(va_list types, char b[],
	int f, int w, int p, int s)
{
	return (print_hexadecimal(types, "0123456789abcdef", b,
		f, 'x', w, p, s));
}
