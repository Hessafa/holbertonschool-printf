#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * _printf - Custom printf function
 * @format: Format string containing the specifiers
 *
 * Return: Total number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list valist;
    int i = 0, len = 0;
    int num;

    va_start(valist, format);

    while (format && format[i] != '\0') {
        if (format[i] == '%') {
            i++;  // Move to the next character after '%'

            // Check if it's %d or %i
            if (format[i] == 'd' || format[i] == 'i') {
                num = va_arg(valist, int);  // Get the next integer argument
                len += print_int(num);  // Print the integer
            }
            else if (format[i] == '%') {  // Handle '%%' case
                write(1, "%", 1);
                len++;
            }
        }
        else {
            write(1, &format[i], 1);  // Print the regular characters
            len++;
        }
        i++;
    }

    va_end(valist);
    return len;
}

/**
 * print_int - Helper function to print an integer
 * @num: The integer to print
 *
 * Return: The number of characters printed
 */
int print_int(int num)
{
    int len = 0;
    char buffer[20];
    int i = 0;
    int is_negative = 0;

    // Handle negative numbers
    if (num < 0) {
        is_negative = 1;
        num = -num;  // Make num positive
    }

    // Convert the number to a string
    if (num == 0) {
        buffer[i++] = '0';
    } else {
        while (num > 0) {
            buffer[i++] = (num % 10) + '0';  // Get the last digit
            num /= 10;
        }
    }

    // If the number was negative, prepend the '-' sign
    if (is_negative) {
        buffer[i++] = '-';
    }

    // Print the string in reverse order (to account for the digits being collected backwards)
    for (int j = i - 1; j >= 0; j--) {
        write(1, &buffer[j], 1);
        len++;
    }

    return len;
}
