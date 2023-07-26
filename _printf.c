#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _putchar - print a character
 * Return: character on success otherwise -1 is retuned
 */

int _putchar (char c)

{
	return (write(1, &c, 1));
}

/**
 * _printf - cutom printf
 * @format: format string
 * Return: printed charaters excluding the null byte
 */

int _printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);

	char ch;
	int chars_printed = 0;

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
			else if (ch == 's')
			{
				char *str;

				str = va_arg(args, char*);
				while (*str)
				{	
					_putchar(*str);
					chars_printed++;
				}
			}
		}
		format++;
	}
	va_end(args);
	return (chars_printed);
}
