#include "main.h"

/**
 * _printf - Produces output according to a format.
 * @format: Format string containing directives.
 *
 * Return: Number of characters printed, or -1 on error.
 */
int _printf(const char *format, ...)
{
    int count = 0;
    va_list args;

    if (!format)
        return (-1); /* Return error for NULL format */

    va_start(args, format);
    while (*format)
    {
        if (*format == '%')
        {
            format++;
            if (*format == '\0') /* Handle case where format ends with '%' */
            {
                count += _putchar('%');
                break;
            }
            if (*format == 'c')
                count += handle_char(args);
            else if (*format == 's')
                count += handle_string(args);
            else if (*format == '%')
                count += handle_percent();
            else
            {
                count += _putchar('%');
                count += _putchar(*format);
            }
        }
        else
        {
            count += _putchar(*format);
        }
        format++;
    }
    va_end(args);

    return (count);
}
