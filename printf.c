#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * print_char - Prints a single character.
 * @args: The argument list containing the character.
 *
 * Return: Number of characters printed.
 */
int print_char(va_list args)
{
	char c = va_arg(args, int);

	return (write(1, &c, 1));
}

/**
 * print_string - Prints a string.
 * @args: The argument list containing the string.
 *
 * Return: Number of characters printed.
 */
int print_string(va_list args)
{
	char *str = va_arg(args, char *);
	int count = 0;

	if (!str)
		str = "(null)";

	while (*str)
		count += write(1, str++, 1);

	return (count);
}

/**
 * print_percent - Prints a literal percent sign.
 *
 * Return: Number of characters printed.
 */
int print_percent(void)
{
	return (write(1, "%", 1));
}

/**
 * _printf - Produces output according to a format.
 * @format: A character string containing directives.
 *
 * Return: Number of characters printed (excluding null byte),
 *         or -1 if an error occurs.
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	if (!format)
		return (-1);

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (!*format)
				return (-1);

			if (*format == 'c')
				count += print_char(args);
			else if (*format == 's')
				count += print_string(args);
			else if (*format == '%')
				count += print_percent();
			else
			{
				count += write(1, "%", 1);
				count += write(1, format, 1);
			}
		}
		else
		{
			count += write(1, format, 1);
		}
		format++;
	}

	va_end(args);
	return (count);
}

/**
 * _printf - Custom printf implementation
 * @format: The format string
 *
 * Return: The number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	const char *ptr;

	/* Initialize the va_list */
	va_start(args, format);

	/* Loop through the format string */
	for (ptr = format; *ptr != '\0'; ptr++)
	{
		if (*ptr == '%' && (*(ptr + 1) == 'd' || *(ptr + 1) == 'i'))
		{
			/* Handle %d and %i specifiers (print integers) */
			int num = va_arg(args, int);

			count += printf("%d", num);
		       /* Use printf to print integers */

			ptr++;
		       /* Skip the specifier (d or i) */
		}
		else
		{
			/* Print other characters as they are */
			putchar(*ptr);
			count++;
		}
	}

	/* Clean up the va_list */
	va_end(args);

	return (count);
}
