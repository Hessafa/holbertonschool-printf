#include "main.h"

/**
 * _printf - Custom printf function
 * @format: Format string
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
    va_list args;
    int i = 0, count = 0;
    char *str;
    char ch;

    va_start(args, format);

    while (format && format[i] != '\0')
    {
        if (format[i] == '%')
        {
            i++;
            if (format[i] == 'c')  // Handle character
            {
                ch = (char)va_arg(args, int);
                write(1, &ch, 1);
                count++;
            }
            else if (format[i] == 's')  // Handle string
            {
                str = va_arg(args, char*);
                while (str && *str)
                {
                    write(1, str, 1);
                    str++;
                    count++;
                }
            }
            else if (format[i] == '%')  // Handle percent sign
            {
                write(1, "%", 1);
                count++;
            }
            else  // Handle invalid format
            {
                write(1, &format[i - 1], 1);
                write(1, &format[i], 1);
                count += 2;
            }
        }
        else
        {
            write(1, &format[i], 1);
            count++;
        }
        i++;
    }

    va_end(args);
    return (count);
}
