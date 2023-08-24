/*
 * THIS PROJECT IS CREATED BY EL HAKIK AMINA AND  ASMA AOUBRAIM
 * */
#include "main.h"

/**
 * extract_precision - Calculates the precision for formatting and printing.
 *
 * This function analyzes a format string to determine the precision for formatting
 * purposes. It starts the analysis from the specified index within the format string.
 *
 * @formatString: The format string to examine.
 * @currentIndex: Pointer to the current index within the format string.
 * @argsList: List of arguments to be printed.
 *
 * Return: The calculated precision value.
 */

int extract_precision(const char *formatString, int *currentIndex, va_list argsList)
{
    int index = *currentIndex + 1; /* Start checking after the '%' */
    /* p=precision */
    int p = -1;

    /* Check if precision is specified by a '.' */
    if (formatString[index] != '.')
        return p; /* Precision not specified, return -1 */

    p = 0;

    /* Loop through the format string to find the precision value */
    for (index += 1; formatString[index] != '\0'; index++)
    {
        /* Check if the character is a digit */
        if (is_digit_character(formatString[index]))
        {
            p *= 10; /* Multiply the existing precision by 10 */
            p += formatString[index] - '0'; /* Add the digit to the precision */
        }
        /* Check if precision is specified as an asterisk (*) */
        else if (formatString[index] == '*')
        {
            index++; /* Move past the asterisk */
            p = va_arg(argsList, int); /* Get precision from arguments */
            break; /* Exit the loop when precision is found */
        }
        else
        {
            break; /* Stop if a non-digit, non-asterisk character is encountered */
        }
    }

    /* Update the current index to point to the last processed character */
    *currentIndex = index - 1;

    return p; /* Return the calculated precision */
}
