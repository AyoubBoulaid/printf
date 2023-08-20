#include "main.h"

/**
 * get_size - Determines the size to cast the argument for printf conversion
 * @format: Formatted string in which to print the arguments
 * @i: Pointer to the index in the format string
 *
 * Return: Size specifier value or 0 if no size specifier found
 */
int get_size(const char *format, int *i)
{
	int curr_i = *i + 1;
	int size = 0;

	/* Check for size specifiers 'l' and 'h' */
	if (format[curr_i] == 'l')
		size = S_LONG;
	else if (format[curr_i] == 'h')
		size = S_SHORT;

	/* Update the index based on whether a size specifier was found */
	if (size == 0)
		*i = curr_i - 1;
	else
		*i = curr_i;

	return (size);
}
