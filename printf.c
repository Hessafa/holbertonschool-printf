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
 * print_int - Prints an integer.
 * @args: The argument list containing the integer.
 *
 * Return: Number of characters printed.
 */
int print_int(va_list args)
{
	int num = va_arg(args, int);
	int count = 0;

	if (num == 0)
		return (write(1, "0", 1));

	if (num < 0)
	{
		count += write(1, "-", 1);
		num = -num;
	}

	if (num / 10)
		count += print_int((va_list)&num / 10);

	count += write(1, &"0123456789"[num % 10], 1);

	return (count);
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
	const char *ptr;

	if (!format)
		return (-1);

	va_start(args, format);

	for (ptr = format; *ptr != '\0'; ptr++)
	{
		if (*ptr == '%')
		{
			ptr++;
			if (!*ptr)
				return (-1);
			if (*ptr == 'c')
				count += print_char(args);
			else if (*ptr == 's')
				count += print_string(args);
			else if (*ptr == '%')
				count += print_percent();
			else if (*ptr == 'd' || *ptr == 'i')
				count += print_int(args);
			else
			{
				count += write(1, "%", 1);
				count += write(1, ptr, 1);
			}
		}
		else
		{
			count += write(1, ptr, 1);
		}
	}

	va_end(args);

	return (count);
}
