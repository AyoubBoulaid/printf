#include "main.h"

/**
 * get_width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments
 * @i: Pointer to the index in the format string
 * @list: List of arguments
 *
 * Return: Width value or 0 if not specified
 */
int get_width(const char *format, int *i, va_list list)
{
	int curr_i;
	int width = 0;

	/* Parse width value from format string */
	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(format[curr_i]))
		{
			/* Calculate width value */
			width *= 10;
			width += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			/* Width value is provided as argument */
			curr_i++;
			width = va_arg(list, int);
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

	return (width);
}
