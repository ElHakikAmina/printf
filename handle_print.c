#include "main_of_printf.h"

/**
 * handle_print - Handles printing of an argument based on its type.
 * @formatSpecifier: Formatted string containing the argument.
 * @currentIndex: Current index within the formatSpecifier string.
 * @argumentList: List of arguments to be printed.
 * @outputBuffer: Buffer to store the printed result.
 * @activeFlags: Flags indicating special printing behavior.
 * @fieldWidth: Width specification for formatting.
 * @precision: Precision specification for formatting.
 * @argumentSize: Size specifier for the argument.
 *
 * Return: 1 if successful, 2 if unrecognized format.
 */
int handle_print(const char *formatSpecifier, int *currentIndex, va_list argumentList,
                  char outputBuffer[], int activeFlags, int fieldWidth, int precision, int argumentSize)
{
    int unknownLength = 0;
    int printedCharacters = -1;

    FormatType formatTypes[] = {
        {'c', print_character}, {'s', print_custom_string}, {'%', print_percentage},
        {'i', print_integer}, {'d', print_integer}, {'b', print_binary_number},
        {'u', print_unsigned_number}, {'o', print_octal_number}, {'x', print_hexadecimal},
        {'X', print_uppercase_hexadecimal}, {'p', print_memory_address}, {'S', print_non_printable_characters},
        {'r', print_reversed_string}, {'R',  print_rot13_encoded_string}, {'\0', NULL}
    };

    for (int i = 0; formatTypes[i].formatSpecifier != '\0'; i++) {
        if (formatSpecifier[*currentIndex] == formatTypes[i].formatSpecifier) {
            return formatTypes[i].function(argumentList, outputBuffer, activeFlags, fieldWidth, precision, argumentSize);
        }
    }

    if (formatTypes[i].formatSpecifier == '\0') {
        if (formatSpecifier[*currentIndex] == '\0') {
            return -1; // End of formatSpecifier string, return -1.
        }
        
        unknownLength += write(1, "%%", 1);

        if (formatSpecifier[*currentIndex - 1] == ' ') {
            unknownLength += write(1, " ", 1);
        } else if (fieldWidth) {
            (*currentIndex)--;
            while (formatSpecifier[*currentIndex] != ' ' && formatSpecifier[*currentIndex] != '%') {
                (*currentIndex)--;
            }
            if (formatSpecifier[*currentIndex] == ' ') {
                (*currentIndex)--;
            }
            return 1;
        }

        unknownLength += write(1, &formatSpecifier[*currentIndex], 1);
        return unknownLength;
    }

    return printedCharacters;
}

