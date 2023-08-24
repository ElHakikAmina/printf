/*
 * THIS PROJECT IS CREATED BY EL HAKIK AMINA AND  ASMA AOUBRAIM
 * */
#include "main.h"

/**
 * getFlags - Extracts and calculates active flags from the format string.
 * @format: The formatted string.
 * @currentIndex: Pointer to the current index within the format string.
 * 
 * Return: Calculated flags.
 */
int extract_flags(const char *format, int *currentIndex) {
    /* Flag characters and their corresponding values */
    const char FLAG_CHARS[] = {'-', '+', '0', '#', ' ', '\0'};
    const int FLAG_VALUES[] = {FLAG_MINUS, FLAG_PLUS, FLAG_ZERO, FLAG_HASH, FLAG_SPACE, 0};

    int flags = 0;
    int currentIdx = *currentIndex + 1; /* Start checking after the '%' */

    /* Loop through the format string starting from the current index */
    while (format[currentIdx] != '\0') {
        int flagIndex;

        /* Check if the character is one of the flag characters */
        for (flagIndex = 0; FLAG_CHARS[flagIndex] != '\0'; flagIndex++) {
            if (format[currentIdx] == FLAG_CHARS[flagIndex]) {
                /* Set the corresponding flag using bitwise OR (|) */
                flags |= FLAG_VALUES[flagIndex];
                break;
            }
        }

        /* If it's not a flag character, stop searching */
        if (FLAG_CHARS[flagIndex] == '\0') {
            break;
        }

        currentIdx++; /* Move to the next character in the format string */
    }

    /* Update the current index to point to the last processed character */
    *currentIndex = currentIdx - 1;

    return flags; /* Return the calculated flags */
}
