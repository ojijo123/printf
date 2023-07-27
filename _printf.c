#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _putchar - helper function to print a character
 *@c: the character to be printed
 * Return: returns character printed
 */
int _putchar(char c)
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
	int digits;
	int divisor;
	int number;
	char ch;
	int chars_printed = 0;
	int i;
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
			else if (ch == 's')
			{
				char *str;

				str = va_arg(args, char*);
				for (i = 0; str[i] != '\0'; i++)
				{
					_putchar(str[i]);
					chars_printed++;
				}
			}
			else if (ch == '%')
			{
				_putchar(*format);
				chars_printed++;
			}
			else if (ch == 'd' || ch == 'i')
			{
				number = va_arg(args, int);

				/*account for negative number*/
				if (number < 0)
				{
					_putchar('-');
					chars_printed++;
					number = -number;
				}
				/*for number with more than one digit*/
				divisor = 1;

				while (number > 9)
				{
					divisor *= 10;
				}
				if (number > 9)
				{
					digits = number / divisor;
					_putchar(digits + '0');
					chars_printed++;
					number = number % 10;
					divisor /= 10;
				}
				else 
				{
					_putchar(number + '0');
					chars_printed++;
				}

			}

		}
		format++;
	}
	va_end(args);
	return (chars_printed);
}
