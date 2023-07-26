#include "main.h"
#include <stdarg.h>
/**
 * _printf - cutom printf
 * @format: format string
 * Return: printed charaters excluding the null byte
 */
int _printf(const char *format, ...)
{
	char ch;
	int chars_printed = 0;

	va_list args;

	va_start(args, format);

	while (*format)
	{
		if (*format != '%')
		{
			_putchar(*format);
			chars_printed++;
		}
		else
		{
			format++;
			ch = *format;
			if (ch == 'c')
			{
				char c = va_arg(args, int);

				_putchar(c);
				chars_printed++;
			}

		}
		format++;
	}
	va_end(args);
	return (chars_printed);
}
