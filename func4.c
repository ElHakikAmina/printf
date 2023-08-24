/*
 * THIS PROJECT IS CREATED BY EL HAKIK AMINA AND  ASMA AOUBRAIM
 * */
#include "main.h"

/**
 * THIS PROJECT IS CREATED BY EL HAKIK AMINA AND  ASMA AOUBRAIM
 * write_char - function that Prints a string
 * @c: characters.
 * @b: Buffer 
 * @f:  flags.
 * @w:  width.
 * @p: precision 
 * @s: size 
 *
 * Return: Number of characters that are  printed.
 */
int write_char(char c, char b[],
	int f, int w, int p, int s)
{ /* char is stored at left and paddind at buffer's right */
	int index = 0;
	char padd = ' ';

UNUSED(s);
	UNUSED(p);
	

	if (f & FLAG_ZERO)
		padd = '0';

	b[index++] = c;
	b[index] = '\0';

	if (w > 1)
	{
		b[BUFFER_SIZE - 1] = '\0';
		for (index = 0; index < w - 1; index++)
			b[BUFFER_SIZE - index - 2] = padd;

		if (f & FLAG_MINUS)
			return (write(1, &b[0], 1) +
					write(1, &b[BUFFER_SIZE - index - 1], w - 1));
		else
			return (write(1, &b[BUFFER_SIZE - index - 1], w - 1) +
					write(1, &b[0], 1));
	}

	return (write(1, &b[0], 1));
}






/**
 * THIS PROJECT IS CREATED BY EL HAKIK AMINA AND  ASMA AOUBRAIM
 * write_number - Prints a string
 * @is_negative: all arguments
 * @ind: char types.
 * @b: Buffer 
 * @f:  flags
 * @w:  width.
 * @p: precision 
 * @s: Size 
 *
 * Return: Number of characters that are printed.
 */
int write_number(int is_negative, int ind, char b[],
	int f, int w, int p, int s)
{
	int length = BUFFER_SIZE - ind - 1;
	char padd = ' ', extra_ch = 0;

	UNUSED(s);

	if ((f & FLAG_ZERO) && !(f & FLAG_MINUS))
		padd = '0';
	if (is_negative)
		extra_ch = '-';
	else if (f & FLAG_PLUS)
		extra_ch = '+';
	else if (f & FLAG_SPACE)
		extra_ch = ' ';

	return (write_integer(ind, b, f, w, p,
		length, padd, extra_ch));
}

/**
 * THIS PROJECT IS CREATED BY EL HAKIK AMINA AND  ASMA AOUBRAIM
 * @ind: Index at which the number starts on the buffer
 * @b: Buffer
 * @f: Flags
 * @w: width
 * @prec: Precision specifier
 * @length: Number length
 * @padd: Pading char
 * @extra_c: Extra char
 *
 * Return: Number of printed characters.
 */
int write_integer(int ind, char b[],
	int f, int w, int prec,
	int length, char padd, char extra_c)
{
	int i, padd_start = 1;

	if (prec == 0 && ind == BUFFER_SIZE  - 2 && b[ind] == '0' && w == 0)
		return (0); /* printf(".0d", 0)  no char is printed */
	if (prec == 0 && ind == BUFFER_SIZE  - 2 && b[ind] == '0')
		b[ind] = padd = ' '; /* width is displayed with padding ' ' */
	if (prec > 0 && prec < length)
		padd = ' ';
	while (prec > length)
		b[--ind] = '0', length++;
	if (extra_c != 0)
		length++;
	if (w > length)
	{
		for (i = 1; i < w - length + 1; i++)
			b[i] = padd;
		b[i] = '\0';
		if (f & FLAG_MINUS && padd == ' ')
		{
			if (extra_c)
				b[--ind] = extra_c;
			return (write(1, &b[ind], length) + write(1, &b[1], i - 1));
		}
		else if (!(f & FLAG_MINUS) && padd == ' ')
		{
			if (extra_c)
				b[--ind] = extra_c;
			return (write(1, &b[1], i - 1) + write(1, &b[ind], length));
		}
		else if (!(f & FLAG_MINUS) && padd == '0')
		{
			if (extra_c)
				b[--padd_start] = extra_c;
			return (write(1, &b[padd_start], i - padd_start) +
				write(1, &b[ind], length - (1 - padd_start)));
		}
	}
	if (extra_c)
		b[--ind] = extra_c;
	return (write(1, &b[ind], length));
}

/**
 * THIS PROJECT IS CREATED BY EL HAKIK AMINA AND  ASMA AOUBRAIM
 * @is_negative: Number that indicate if the number  is neg or pos
 * @ind: index of the start of the buff
 * @b: buffer
 * @f: Flags 
 * @w: Width 
 * @p: Precision 
 * @s: Size 
 *
 * Return: Number of written chars.
 */
int write_unsigned(int is_negative, int ind,
	char b[],
	int f, int w, int p, int s)
{
	
	int length = BUFFER_SIZE  - ind - 1, i = 0;
	char padd = ' ';

	UNUSED(is_negative);
	UNUSED(s);

	if (p == 0 && ind == BUFFER_SIZE  - 2 && b[ind] == '0')
		return (0); 

	if (p > 0 && p < length)
		padd = ' ';

	while (p > length)
	{
		b[--ind] = '0';
		length++;
	}

	if ((f & FLAG_ZERO) && !(f & FLAG_MINUS))
		padd = '0';

	if (w > length)
	{
		for (i = 0; i < w - length; i++)
			b[i] = padd;

		b[i] = '\0';

		if (f & FLAG_MINUS) 
		{
			return (write(1, &b[ind], length) + write(1, &b[0], i));
		}
		else 
		{
			return (write(1, &b[0], i) + write(1, &b[ind], length));
		}
	}

	return (write(1, &b[ind], length));
}

/**
 * THIS PROJECT IS CREATED BY EL HAKIK AMINA AND  ASMA AOUBRAIM
 * @b: buffer
 * @ind: Index - the start of buff
 * @length: Length_of_number
 * @w: the width 
 * @f: Flags 
 * @padd:padding
 * @extra_c:  extracharacter
 * @padd_start:  padding should start -index
 *
 * Return: Number of  characters that are writted.
 */
int write_memory_address(char b[], int ind, int length,
	int w, int f, char padd, char extra_c, int padd_start)
{
	int i;

	if (w > length)
	{
		for (i = 3; i < w - length + 3; i++)
			b[i] = padd;
		b[i] = '\0';
		if (f & FLAG_MINUS && padd == ' ')
		{
			b[--ind] = 'x';
			b[--ind] = '0';
			if (extra_c)
				b[--ind] = extra_c;
			return (write(1, &b[ind], length) + write(1, &b[3], i - 3));
		}
		else if (!(f & FLAG_MINUS) && padd == ' ')
		{
			b[--ind] = 'x';
			b[--ind] = '0';
			if (extra_c)
				b[--ind] = extra_c;
			return (write(1, &b[3], i - 3) + write(1, &b[ind], length));
		}
		else if (!(f & FLAG_MINUS) && padd == '0')
		{
			if (extra_c)
				b[--padd_start] = extra_c;
			b[1] = '0';
			b[2] = 'x';
			return (write(1, &b[padd_start], i - padd_start) +
				write(1, &b[ind], length - (1 - padd_start) - 2));
		}
	}
	b[--ind] = 'x';
	b[--ind] = '0';
	if (extra_c)
		b[--ind] = extra_c;
	return (write(1, &b[ind], BUFFER_SIZE  - ind - 1));
}
