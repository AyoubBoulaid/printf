#include "main.h"

/**
 * _printf - Custom printf function
 * @format: Format string
 * Return: Number of printed characters
 */
int _printf(const char *format, ...)
{
	int i, printed_chars = 0;
	va_list args;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
			write(1, &format[i], 1);
			printed_chars++;
		else
		{
			i++; /* Move past '%' */

			if (format[i] == 'c')
			{
				char c = (char)va_arg(args, int);

				write(1, &c, 1);
				printed_chars++;
			}
			else if (format[i] == 's')
			{
				char *str = va_arg(args, char *);

				if (str == NULL)
					str = "(null)";
				while (*str)
					write(1, str, 1);
					str++;
					printed_chars++;
			}
			else if (format[i] == '%')
				write(1, &format[i], 1);
				printed_chars++;
		}
	}
	va_end(args);
	return (printed_chars);
}
