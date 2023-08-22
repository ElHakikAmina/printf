#include "main.h"

/**
 * extract_size - Determines the size of the argument data type.
 * @formatSpecifier: Format specifier string.
 * @currentIndex: Current index within the formatSpecifier string.
 *
 * Return: Size of the argument (e.g., S_LONG for 'l', S_SHORT for 'h', or 0 if no size modifier).
 */
int extract_size(const char *formatSpecifier, int *currentIndex)
{
    int nextIndex = *currentIndex + 1;  /* Move to the next character in the formatSpecifier string. */
    int argumentSize = 0;  /* Initialize the argument size to zero. */

    /* Check if the next character in the formatSpecifier is 'l' (long). */
    if (formatSpecifier[nextIndex] == 'l') {
        argumentSize = SIZE_LONG;  /* Set the argument size to SIZE_LONG. */
    }
    /* Check if the next character in the formatSpecifier is 'h' (short). */
    else if (formatSpecifier[nextIndex] == 'h') {
        argumentSize = SIZE_SHORT;  /* Set the argument size to SIZE_SHORT. */
    }

    /* Update the currentIndex to the next index. */
    if (argumentSize == 0) {
        *currentIndex = nextIndex - 1;  /* No size modifier found, so revert the currentIndex. */
    } else {
        *currentIndex = nextIndex;  /* Update currentIndex to the next index. */
    }

    return argumentSize;  /* Return the determined argument size. */
}
