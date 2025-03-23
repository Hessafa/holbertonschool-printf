#include "main.h"

int main(void)
{
    _printf("Simple sentence: Hello, world!\n");
    _printf("Character: %c\n", 'H');
    _printf("String: %s\n", "Hello, world!");
    _printf("Percent: %%\n");
    _printf("NULL string: %s\n", (char *)0);

    return (0);
}
