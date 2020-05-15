#include "monty.h"

/**
 * _isdigit - checks if input is a digit
 * @c: input to be checked
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int _isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}


/**
 * _isnumber - checks if input is a number
 * @num: string input to be checked
 *
 * Return: 1 if num is a number, 0 otherwise.
 */

int _isnumber(char *num)
{
	int i = 0;

	if (num[i] == '-')
		++i;
	if (num[i] == '\0' || num[i] == '0')
		return (0);
	while (num[i] != '\0')
	{
		if (_isdigit(num[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}
