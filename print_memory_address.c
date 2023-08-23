#include "main.h"

/****************** pointer ******************/
/**
 * print_memory_address - Prints the value stored in a pointer variable
 * @types: variable that contains arguments
 * @b: Buffer 
 * @f: flags
 * @w: width - variable when we put the width
 * @p: Precision - variable when we put the precision
 * @s: Size - variable when we put the size
 * Return: Number of characters that we  printed.
 */
int print_memory_address(va_list types, char b[],
	int f, int w, int p, int s)
{
	char extra_char = 0; 
    char padding_char = ' ';
	int index = BUFFER_SIZE - 2;
    unsigned long num_addresses;
    int length = 2;
    int padding_start = 1; 
	
	char map_to[] = "0123456789abcdef";
	void *address = va_arg(types, void *);

	UNUSED(w);
	UNUSED(s);

	if (address == NULL)
		return (write(1, "(nil)", 5));

	b[BUFFER_SIZE - 1] = '\0';
	UNUSED(p);

	num_addresses = (unsigned long)address;

	while (num_addresses > 0)
	{
		b[index--] = map_to[num_addresses % 16];
		num_addresses /= 16;
		length++;
	}

	if ((f & FLAG_ZERO) && !(f & FLAG_MINUS))
		padding_char = '0';
	if (f & FLAG_PLUS)
		extra_char = '+', length++;
	else if (f & FLAG_SPACE)
		extra_char = ' ', length++;

	index++;

	/*return (write(1, &buffer[i], BUFFER_SIZE - i - 1));*/
	return (write_memory_address(b, index, length,
		w, f, padding_char, extra_char, padding_start));
}
