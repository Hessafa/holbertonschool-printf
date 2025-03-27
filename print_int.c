#include <unistd.h>
#include <stdarg.h>

/**
 * print_int - Print an integer
 * @args: The argument list 
 * Return: number of characters to be printed
 */

int print_int(va_list args)
{
        int n = va_arg(args, int);
        int count = 0;
        char buffer[12];
        int i = 0;
        

        if (n == 0)
                return write(1, "0", 1);

        if (n < 0)
        {
                is_negative = 1;
                n = -n;
        }

        while (n > 0)
        {
                buffer[i++] = (n % 10) + '0';
                n /= 10;
        }

        if (is_negative)
                buffer[i++] = '-';

        while(i--)
                count += write(1, &buffer[i], 1);

        return count;
}

