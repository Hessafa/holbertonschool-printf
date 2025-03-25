#include "main.h"
#include <stdarg.h>
#include <unistd.h>

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

	if (!format)
		return (-1);

	/* Initialize the va_list */
	va_start(args, format);

	/* Loop through the format string */
	for (ptr = format; *ptr != '\0'; ptr++)
	{
		if (*ptr == '%')
		{
			ptr++; /* Move past the '%' character */
			count += handle_format_specifier(ptr, args);
		}
		else
		{
			/* Print normal characters */
			count += write(1, ptr, 1);
		}
	}

	/* Clean up the va_list */
	va_end(args);

	return (count);
}
