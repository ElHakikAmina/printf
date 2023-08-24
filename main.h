/*
 * THIS PROJECT IS CREATED BY EL HAKIK AMINA AND  ASMA AOUBRAIM
 * */
#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>


/*set the size of buffer to 1024*/
#define BUFFER_SIZE 1024
/*this to vid compiler error*/
#define UNUSED(x) (void)(x)


/* this flags will be used in the program */
/* 1 for - */
#define FLAG_MINUS 1
/* 2 for + */
#define FLAG_PLUS 2
/* 4 for 0*/
#define FLAG_ZERO 4
/* 8 for hash*/
#define FLAG_HASH 8
/* 16 for space */
#define FLAG_SPACE 16

/* will be used in util */
#define SIZE_LONG 2
#define SIZE_SHORT 1


/**
 * struct format - Struct specifier
 *
 * @specifier: The specifier.
 * @handler: The handler function.
 */
struct format
{
    char specifier;
    int (*handler)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct format format_t - Struct specifier
 *
 * @specifier: The specifier.
 * @handler: The handler function.
 */
typedef struct format format_t;

int _printf(const char *format, ...);
int handle_print(const char *specifier, int *index,
                 va_list list, char b[], int f,
                 int w, int p, int s);

/************** FUNCTIONS PROTOTYPES ***************/
/* b:buffer, f:flags, w:width, p:precision , s:  */
/* Functions to print characters and strings */
int print_character(va_list args, char b[],
                    int f, int w, int p, int s);
int print_custom_string(va_list args, char b[],
                        int f, int w, int p, int s);
int print_percentage(va_list args, char b[],
                     int f, int w, int p, int s);

/* Print numbers */
int print_integer(va_list args, char b[],
                  int f, int w, int p, int s);
int print_binary_number(va_list args, char b[],
                        int f, int w, int p, int s);
int print_unsigned_number(va_list args, char b[],
                          int f, int w, int p, int s);
int print_octal_number(va_list args, char b[],
                       int f, int w, int p, int s);
int print_hexadecimal_number(va_list args, char b[],
                            int f, int w, int p, int s);
int print_uppercase_hexadecimal(va_list args, char b[],
                            int f, int w, int p, int s);

int print_hexadecimal(va_list args, char mapping[],
                      char b[], int f, char flag_char,
                      int w, int p, int s);

/* Print non-printable characters */
int print_non_printable_characters(va_list args, char b[],
                                   int f, int w, int p, int s);

/* Print memory addresses */
int print_memory_address(va_list args, char b[],
                         int f, int w, int p, int s);

/* Handle other specifiers */
int extract_flags(const char *format, int *index);
int extract_width(const char *format, int *index, va_list args);
int extract_precision(const char *format, int *index, va_list args);
int extract_size(const char *format, int *index);

/* Print a string in reverse */
int print_reversed_string(va_list args, char b[],
                          int f, int w, int p, int s);

/* Print a string in ROT13 */
int print_rot13_encoded_string(va_list args, char b[],
                              int f, int w, int p, int s);

/* Width handler */
int write_char(char c, char b[],
               int f, int w, int p, int s);
int write_number(int is_positive, int index, char b[],
                 int f, int w, int p, int s);
int write_integer(int index, char b[], int f,
                  int w, int p, int length, char padding,
                  char extra_char);
int write_memory_address(char b[], int index, int length,
                        int w, int f, char padding, char extra_char,
                        int padding_start);

int write_unsigned(int is_negative, int index,
                   char b[], int f, int w, int p, int s);

/****************** UTILS and other tools ******************/
int is_printable_character(char);
int append_hexadecimal_code(char, char[], int);
int is_digit_character(char);

long int convert_number_size(long int num, int s);
long int convert_unsigned_size(unsigned long int num, int s);

#endif 

