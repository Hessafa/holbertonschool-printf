#include <stdio.h>
#include <stdarg.h>
#include "main.h"

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

			count += printf("%d", num); /* Use printf to print integers */
			ptr++; /* Skip the specifier (d or i) */
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
