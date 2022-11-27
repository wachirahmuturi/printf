#include <stdio.h>
#include "main.h"

/**
  * _puts - prints characters
  * @str: pointer to a string
  */
void _puts(const char *str)
{
	while (*str)
	{
		_putchar(*str);
		str++;
	}
}

/**
  *_printf - replica to stdio's printf
  * @format: the input argument
  * @...: number of arguments provided
  * Return: 0 if successful
  */
int _printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);

	_vprintf(format, args);

	va_end(args);
	return (0);
}

/**
  *_vprintf - carries specifier types
  * @fmt: the input argument
  * @args: list of arguments
  * Return: 0 if successful
  */
int _vprintf(const char *fmt, va_list args)
{
	int state = 0;
	int i;
	char buf[1024];

	while (*fmt)
	{
		if (state == 0)
		{
			if (*fmt == '%')
				state = 1;
			else
				_putchar(*fmt);
		}
		else if (state == 1)
		{
			switch (*fmt)
			{
				case 'c': {
						char ch = va_arg(args, int);

						_putchar(ch);
						break;
					}
				case 's': {
						const char *s = va_arg(args, const char *);

						_puts(s);
						break;
					}
				case '%': {
						_putchar(*fmt);
						break;
					}
				case 'd': {
						int n = va_arg(args, int);

						signed_number_to_string(n, 10, buf);
						for (i = 0; buf[i]; i++)
						{
							_putchar(buf[i]);
						}
						break;
					}
				case 'b': {
						int n = va_arg(args, int);

						unsigned_number_to_string(n, 2, buf);
						for (i = 0; buf[i]; i++)
						{
							_putchar(buf[i]);
						}
						break;
					}
				case 'x': {
						int n = va_arg(args, int);

						unsigned_number_to_string(n, 16, buf);
						for (i = 0; buf[i]; i++)
						{
							_putchar(buf[i]);
						}
						break;
					}
				case 'p': {
						void *p = va_arg(args, void *);

						_putchar('0');
						_putchar('x');
						unsigned_number_to_string((uint64_t) p, 16, buf);
						for (i = 0; buf[i]; i++)
						{
							_putchar(buf[i]);
						}
						break;
					}
				case 'o': {
						int n = va_arg(args, int);

						unsigned_number_to_string(n, 8, buf);
						for (i = 0; buf[i]; i++)
						{
							_putchar(buf[i]);
						}
						break;
					}
			}
			state = 0;
		}
	fmt++;
	}
	return (0);
}

/**
  * unsigned_number_to_string - converts int to base-type number
  * @number: input number in 64 bit type
  * @base: the conversion base format
  * @buffer: the memory holder
  */

void unsigned_number_to_string(uint64_t number, int base, char *buffer)
{
	int i;
	int cur = 0;
	char buf[65];

	if (number == 0)
	{
		*buffer++ = '0';
		*buffer = 0;
		return;
	}

	for (i = 0; i < 65; i++)
		buf[i] = 0;

	while (number)
	{
		int digit = number % base;

		if (digit >= 10)
		{
			buf[cur++] = 'a' + (digit - 10);
		}
		else
		{
			buf[cur++] = '0' + digit;
		}
		number /= base;
	}

	for (i = cur - 1; i != 0; i--)
		*buffer++ = buf[i];
	*buffer++ = buf[0];
	*buffer = 0;
}

/**
  * signed_number_to_string - specific for signed integers
  * @number: input number in 64-bit format
  * @base: the conversion base format
  * @buffer: the memory holder
  */

void signed_number_to_string(int64_t number, int base, char *buffer)
{
	if (number < 0)
	{
		*buffer++ = '-';
		number = -number;
	}
	unsigned_number_to_string(number, base, buffer);
}
