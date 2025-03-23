#include "main.h"
#include <stdarg.h>

#define BUFF_SIZE 1024

int _putchar(char c);
void print_buffer(char buffer[], int *buff_ind);

/**
 * handle_char - Handles the %c format specifier
 * @args: Argument list containing the character
 *
 * Return: Number of characters printed
 */
int handle_char(va_list args)
{
    char c = va_arg(args, int);

    return (_putchar(c));
}

/**
 * handle_string - Handles the %s format specifier
 * @args: Argument list containing the string
 *
 * Return: Number of characters printed
 */
int handle_string(va_list args)
{
    int count = 0;
    char *str = va_arg(args, char *);

    if (!str)
        str = "(null)";

    while (*str)
        count += _putchar(*str++);

    return (count);
}

/**
 * handle_percent - Handles the %% format specifier
 *
 * Return: Number of characters printed
 */
int handle_percent(void)
{
    return (_putchar('%'));
}

/**
 * _printf - Produces output according to a format
 * @format: Format string containing specifiers
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
    int count = 0;
    int i, printed = 0;
    int flags, width, precision, size, buff_ind = 0;
    va_list args;
    char buffer[BUFF_SIZE];

    if (!format)
        return (-1); /* Return error for NULL format */

    va_start(args, format);

    for (i = 0; format[i] != '\0'; i++)
    {
        if (format[i] != '%')
        {
            buffer[buff_ind++] = format[i];
            if (buff_ind == BUFF_SIZE)
                print_buffer(buffer, &buff_ind);

            count++;
        }
        else
        {
            print_buffer(buffer, &buff_ind);
            flags = get_flags(format, &i);
            width = get_width(format, &i, args);
            precision = get_precision(format, &i, args);
            size = get_size(format, &i);

            i++;

            printed = handle_print(format, &i, args, buffer, flags, width, 
                                   precision, size);

            if (printed == -1)
                return (-1);

            count += printed;
        }
    }

    print_buffer(buffer, &buff_ind);

    va_end(args);

    return (count);
}

/**
 * print_buffer - Prints the contents of the buffer if it exists
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length
 */
void print_buffer(char buffer[], int *buff_ind)
{
    if (*buff_ind > 0)
        write(1, buffer, *buff_ind);
    *buff_ind = 0;
}
