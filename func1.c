#include "main.h"

/************************* PRINT CHARARCTER
 * THIS PROJECT IS CREATED BY EL HAKIK AMINA AND  ASMA AOUBRAIM
 * *************************/

/**
 * THIS PROJECT IS CREATED BY EL HAKIK AMINA AND  ASMA AOUBRAIM
 * print_character - Prints a single character.
 * @args: List of arguments.
 * @b: Buffer array to handle printing.
 * @f:  flags that Calculates active flags.
 * @w: Width specification.
 * @p: Precision specification.
 * @s: Size specifier.
 *
 * Return: Number of characters printed.
 */
int print_character(va_list args, char b[], int f, int w, int p, int s)
{
    char character = va_arg(args, int);

    return (write_char(character, b, f, w, p, s));
}
