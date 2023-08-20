#include "main.h"

/**
 * get_flags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @i: Pointer to the index in the format string
 * Return: Flags calculated based on the format string
 */
int get_flags(const char *format, int *i)
{
	/* - + 0 # ' ' */
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	int flags = 0;
	int j, curr_i;

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		/* Check if the current character is a recognized flag */
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
		{
			if (format[curr_i] == FLAGS_CH[j])
			{
				/* Set the corresponding flag bit */
				flags |= FLAGS_ARR[j];
				break;
			}
		}

		/* If the character isn't a recognized flag, stop parsing */
		if (FLAGS_CH[j] == '\0')
			break;
	}

	/* Update the index in the format string */
	*i = curr_i - 1;

	return (flags);
}
