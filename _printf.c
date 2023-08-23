/*
 * THIS PROJECT IS CREATED BY EL HAKIK AMINA AND  ASMA AOUBRAIM 
 * */
#include "main.h"

void print_buffer(char b[], int *buffer_index);

/**
 * _printf - Custom implementation of the printf function.
 *
 * @format: A format string containing format specifiers.
 *
 * Return: The total number of characters printed.
 */

int _printf(const char *format, ...)
{
    /* Initialize variables.*/
	int i;
    int printed = 0;
    int printed_chars = 0;
	int f; /* flags */
    int w; /* width */
    int p; /* precision */
    int s; /*size */
    int buffer_index = 0; 
	va_list list;
	char b[BUFFER_SIZE ]; /* Initialize a character buffer to store output.*/

	if (format == NULL)
		return (-1); /* Check if the format string is NULL.*/

	va_start(list, format); /* Start the variable argument list. */

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%') /* If the current character is not '%': */
		{
			b[buffer_index++] = format[i]; /* Store the character in the buffer.*/
			if (buffer_index == BUFFER_SIZE) /* If the buffer is full:*/
				print_buffer(b, &buffer_index); /* Print the buffer contents.*/
			printed_chars++; /* Increment the count of printed characters.*/
		}
		else /* If the current character is '%':*/
		{
			print_buffer(b, &buffer_index); /* Print the buffer contents.*/
			f = extract_flags(format, &i); /* Extract flags.*/
			w = extract_width(format, &i, list); /* Extract width.*/
			p = extract_precision(format, &i, list); /* Extract precision.*/
			s = extract_size(format, &i); /* Extract size specifier.*/
			++i; /* Move to the next character after '%'.*/
			printed = handle_print(format, &i, list, b,
				f, w, p, s); /* Handle printing based on format specifier.*/
			if (printed == -1) /* Check for errors.*/
				return (-1);
			printed_chars += printed; /* Increment the count of printed characters.*/
		}
	}

	print_buffer(b, &buffer_index); /* Print any remaining characters in the buffer.*/

	va_end(list); /* End the variable argument list.*/

	return (printed_chars); /* Return the total count of printed characters.*/
}

/**
 * print_buffer - Outputs the buffered characters if any exist.
 *
 * @b: Buffer containing an array of characters.
 * @buffer_index: Index at which to add the next character, indicating the buffer length.
 */

void print_buffer(char b[], int *buffer_index)
{
	if (*buffer_index > 0)
		write(1, &b[0], *buffer_index); /* Write the buffer contents to standard output.*/

	*buffer_index = 0; /* Reset the buffer index to 0.*/
}
