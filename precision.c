#include "main.h"

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: Pointer to the index in the format string
 * @list: List of arguments
 *
 * Return: Precision value or -1 if not specified
 */
int get_precision(const char *format, int *i, va_list list)
{
	int curr_i = *i + 1;
	int precision = -1;

	/* Check for presence of precision indicator */
	if (format[curr_i] != '.')
		return (precision);

	precision = 0;

	/* Parse precision value from format string */
	for (curr_i += 1; format[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(format[curr_i]))
		{
			/* Calculate precision value */
			precision *= 10;
			precision += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			/* Precision value is provided as argument */
			curr_i++;
			precision = va_arg(list, int);
			break;
		}
		else
		{
			/* Stop parsing if not a digit or '*' */
			break;
		}
	}

	/* Update the index in the format string */
	*i = curr_i - 1;

	return (precision);
}
