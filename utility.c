#include "main.h"

/**
 * is_char_printable - Checks if a character is within the printable range.
 * @c: The character to check.
 * Return: 1 if c is printable, 0 otherwise.
 */
int is_char_printable(char c)
{
	return (c >= 32 && c < 127);
}

/**
 * append_hex_format - Appends ASCII in hexadecimal format to the buffer.
 * @ascii_code: The ASCII code to be appended.
 * @buffer: The buffer array to handle appending.
 * @i: The index at which to start appending.
 * Return: The number of characters appended (always 3).
 */
int append_hex_format(char ascii_code, char buffer[], int i)
{
	char map[] = "0123456789ABCDEF";

	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map[ascii_code / 16];
	buffer[i] = map[ascii_code % 16];

	return (3);
}

/**
 * is_character_digit - Checks if a character is a digit.
 * @c: The character to check.
 * Return: 1 if c is a digit, 0 otherwise.
 */
int is_character_digit(char c)
{
	return (c >= '0' && c <= '9');
}

/**
 * convert_number_to_size - Converts a number to the specified size.
 * @num: The number to be converted.
 * @size: The size indicating the type to be casted.
 * Return: The casted value of num.
 */
long int convert_number_to_size(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_unsigned_to_size - Converts an unsigned number
 * to the specified size.
 * @num: The unsigned number to be converted.
 * @size: The size indicating the type to be casted.
 * Return: The casted value of num.
 */
unsigned long int convert_unsigned_to_size(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
