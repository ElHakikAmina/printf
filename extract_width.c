/*
 * THIS PROJECT IS CREATED BY EL HAKIK AMINA AND  ASMA AOUBRAIM
 * */

#include "main.h"

/**
 * extract_width - Calculate the width for printing.
 * @formatString: The format string to analyze.
 * @currentIndex: Pointer to the current index within the format string.
 * @argsList: List of arguments to be printed.
 *
 * Return: Calculated width.
 */
int extract_width(const char *formatString, int *currentIndex, va_list argsList)
{
    int index = *currentIndex + 1; /* Start checking after the '%' */
    int width = 0;

    /* Loop through the format string to find the width value */
    for (; formatString[index] != '\0'; index++)
    {
        /* Check if the character is a digit */
        if (is_digit_character(formatString[index]))
        {
            width *= 10;
            width += formatString[index] - '0';
        }
        /* Check if width is specified as an asterisk (*) */
        else if (formatString[index] == '*')
        {
            index++; /* Move past the asterisk */
            width = va_arg(argsList, int); /* Get width from arguments */
            break;
        }
        else
        {
            break; /* Stop if a non-digit, non-asterisk character is encountered */
        }
    }

    /* Update the current index to point to the last processed character */
    *currentIndex = index - 1;

    return width;
}
