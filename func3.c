/*
 * THIS PROJECT IS CREATED BY EL HAKIK AMINA AND  ASMA AOUBRAIM
 * */
#include "main.h"
/**
 * THIS PROJECT IS CREATED BY EL HAKIK AMINA AND  ASMA AOUBRAIM
 * print_non_printable_characters - Prints the hexadecimal ASCII codes of non-printable characters
 * @types: all arguments
 * @b: Buffer
 * @f: flags
 * @w: width
 * @p: Precision
 * @s: Size
 * Return: Number of characters that are  printed
 */
int print_non_printable_characters(va_list types, char b[],
	int f, int w, int p, int s)
{
	int index = 0, offset = 0;
	char *str = va_arg(types, char *);

	UNUSED(f);

    UNUSED(p);

    UNUSED(s);
    
	UNUSED(w);
	
	

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[index] != '\0')
	{
		if (is_printable_character(str[index]))
			b[index + offset] = str[index];
		else
			offset += append_hexadecimal_code(str[index], b, index + offset);
            index=index+1;
	}

	b[index + offset] = '\0';

	return (write(1, b, index + offset));
}

/**
 * THIS PROJECT IS CREATED BY EL HAKIK AMINA AND  ASMA AOUBRAIM
 * print_reversed_string - Prints the reverse of a string.
 * @types: all the arguments
 * @b: Buffer
 * @f: flags
 * @w: width
 * @p: Precision
 * @s: Size
 * Return: Numbers of characters that are  printed
 */

int print_reversed_string(va_list types, char b[],
	int f, int w, int p, int s)
{
	char *str;
	int index, count = 0;

	UNUSED(b);
	UNUSED(f);
	UNUSED(w);
	UNUSED(s);

	str = va_arg(types, char *);

	if (str == NULL)
	{
		UNUSED(p);

		str = ")Null(";
	}
	for (index = 0; str[index]; index++)
		;

	for (index = index - 1; index >= 0; index--)
	{
		char zIndex = str[index];

		write(1, &zIndex, 1);
		count=count+1;
	}
	return (count);
}

/**
 * THIS PROJECT IS CREATED BY EL HAKIK AMINA AND  ASMA AOUBRAIM
 * print_rot13_encoded_string - Encode a string in ROT13 and print it..
 * @types: all arguments
 * @b: Buffer 
 * @f:  flags
 * @w:  width
 * @p: Precision
 * @s: Size 
 * Return: Numbers of characters that are  printed
 */
int print_rot13_encoded_string(va_list types, char b[],
	int f, int w, int p, int s)
{
	char v;
	char *str;
	unsigned int index, jIndex;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types, char *);
	UNUSED(b);
	UNUSED(f);
	UNUSED(w);
	UNUSED(p);
	UNUSED(s);

	if (str == NULL)
		str = "(AHYY)";
	for (index = 0; str[index]; index++)
	{
		for (jIndex = 0; in[jIndex]; jIndex++)
		{
			if (in[jIndex] == str[index])
			{
				v = out[jIndex];
				write(1, &v, 1);
				count++;
				break;
			}
		}
		if (!in[jIndex])
		{
			v = str[index];
			write(1, &v, 1);
            count=count+1;
		}
	}
	return (count);
}
