/*
 * THIS PROJECT IS CREATED BY EL HAKIK AMINA AND  ASMA AOUBRAIM
 * */
#include "main.h"
/**** Function THAT PRINT A STRING *****/
/**
 * THIS PROJECT IS CREATED BY EL HAKIK AMINA AND  ASMA AOUBRAIM
 * print_custom_string - Prints a string.
 * @args: List of arguments.
 * @b: Buffer array to handle printing.
 * @f: flags that Calculates active flags.
 * @w: Width specification.
 * @p: Precision specification.
 * @s: Size specifier.
 *
 * Return: Number of characters printed.
 */
int print_custom_string(va_list args, char b[], int f, int w, int p, int s)
{
    int length = 0; int i;
    char *str = va_arg(args, char *);

    UNUSED(b);
    UNUSED(f);
    UNUSED(w);
    UNUSED(p);
    UNUSED(s);

    if (str == NULL)
    {
        str = "(null)";
        if (p >= 6)
            str = "      ";
    }

    while (str[length] != '\0')
        length++;

    if (p >= 0 && p < length)
        length = p;

    if (w > length)
    {
        if (f & FLAG_MINUS)
        {
            write(1, &str[0], length);
            for (i = w - length; i > 0; i--)
                write(1, " ", 1);
            return (w);
        }
        else
        {
            for (i = w - length; i > 0; i--)
                write(1, " ", 1);
            write(1, &str[0], length);
            return (w);
        }
    }

    return (write(1, str, length));
}
