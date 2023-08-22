#include "main.h"
 /* THIS FUNCTION PRINT PERCENT SIGN : print_percentage*/
/**
 * print_percent - Handles printing of a percent sign.
 * @args: List of arguments (not used in this function).
 * @b: Buffer to handle printing (not used in this function).
 * @f: Flags to calculate active flags (not used in this function).
 * @w: Width specification (not used in this function).
 * @p: Precision specification (not used in this function).
 * @s: Size specifier (not used in this function).
 *
 * Return: The number of characters printed (always 1 for the percent sign).
 */

int print_percentage(va_list args, char b[], int f, int w, int p, int s)
{
    UNUSED(args);
    UNUSED(b);
    UNUSED(f);
    UNUSED(w);
    UNUSED(p);
    UNUSED(s);
    
    return (write(1, "%%", 1));
}

