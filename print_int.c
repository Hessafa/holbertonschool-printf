#include <unistd.h>
#include <stdarg.h>

/**
 * print_number - prints positive long number
 * @n: number to print
 * Return: number of characters
 */
int print_number(long n)
{
	int count = 0;
	char digit;
	int remainder;

	if (n / 10)
		count += print_number(n / 10);

	remainder = n % 10;

	if (remainder < 0)
		remainder = -remainder;
	digit = '0' + remainder;
	count += write(1, &digit, 1);

	return (count);
}

/**
 * print_int - Print an integer
 * @args: The argument list
 * Return: number of characters to be printed
 */
int print_int(va_list args)
{
	int n = va_arg(args, int);
	long num = n;
	int count = 0;

	if (n == 0)
		return (write(1, "0", 1));

	if (n < 0)
	{
		count += write(1, "-", 1);
		n = -n;
	}

	count += print_number(num);

	return (count);
}
