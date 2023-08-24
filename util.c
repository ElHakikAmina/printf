#include "main.h"





/**
 * THIS PROJECT IS CREATED BY EL HAKIK AMINA AND  ASMA AOUBRAIM
 * is_printable_character -  Char is printable or NO
 * @character: Char that we evaluate.
 *
 *
 * Return: 1 : character is printable, 0: otherwise
 */
int is_printable_character(char character) {
    /* Check if the character is within the printable ASCII range*/
    return (character >= 32 && character < 127);
}


/**
 * THIS PROJECT IS CREATED BY EL HAKIK AMINA AND  ASMA AOUBRAIM
 * append_hexadecimal_code - Append ascci in hexadecimal code to buffer
 * @b: (buffer) Array of chars.
 * @inex: Index at which to start appending.
 * @ascii_code: ASSCI CODE.
 * Return: Always 3
 */
int append_hexadecimal_code(char ascii_code, char b[], int index)
{
	char map_to[] = "0123456789ABCDEF";
	/* The hexa format code is always 2 digits long */
	if (ascii_code < 0){
		ascii_code *= -1;
}
	b[index++] = '\\';
	b[index++] = 'x';

	b[index++] = map_to[ascii_code / 16];
	b[index] = map_to[ascii_code % 16];

	return (3);
}
/**
 * THIS PROJECT IS CREATED BY EL HAKIK AMINA AND  ASMA AOUBRAIM
 * is_digit_character - Is a char is a digit?
 * @character: Char that we will  evaluate
 *
 * Return: 1 if c : digit, 0 : otherwise
 */
int is_digit_character(char character) {
    /* Check if the character is a digit (0-9)*/
    return (character >= '0' && character <= '9');
}


/**
 * THIS PROJECT IS CREATED BY EL HAKIK AMINA AND  ASMA AOUBRAIM
 * convert_number_size - Converts a number to the specified size using type casting
 * @n:(num) Number that will be casted.
 * @s: (size)Number that indicate the type that will be  casted.
 *
 * Return: Casted value of n
 */
long int convert_number_size(long int n, int s) {
    switch (s) {
        case SIZE_LONG:
            return n;
        case SIZE_SHORT:
            return (short)n;
        default:
            return (int)n;
    }
}






/**
 * THIS PROJECT IS CREATED BY EL HAKIK AMINA AND  ASMA AOUBRAIM
 * convert_unsigned_size - Changes the size of a number to the specified size through casting
 * @n: num that will  be casted
 * @s: the size Number that indicate the type to be casted
 *
 * Return: The value of 'n' after casting.
 */
long int convert_unsigned_size(unsigned long int n, int s)
{
	if (s == SIZE_LONG)
		return (n);
	else if (s == SIZE_SHORT)
		return ((unsigned short)n);

	return ((unsigned int)n);
}


