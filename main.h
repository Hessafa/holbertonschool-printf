#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _putchar(char c);
int _printf(const char *format, ...);
int handle_char(va_list args);
int handle_string(va_list args);
int handle_percent(void);

#endif /* MAIN_H */
