#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int _putchar(char c);
int _printf(const char *format, ...);
int handle_char(va_list args);
int handle_string(va_list args);
int handle_percent(void);
int print_int(va_list args);
#endif /* MAIN_H */
