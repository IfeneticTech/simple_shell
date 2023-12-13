#include "shell.h"

/**
 * interactive - it returns true if shell is interactive mode.
 * @info: the struct address.
 *
 * Return: 1 if interactive mode, 0 otherwise.
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}


/**
 * is_delim - function that checks if character is a delimeter.
 * @c: the char to check.
 * @delim: the delimeter string.
 * Return: 1 if true, 0 if false.
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}


/**
 * _isalpha - function that checks for alphabetic character.
 * @c: the character to input.
 * Return: 1 if c is alphabetic, 0 otherwise.
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - function that converts a string to an integer.
 * @s: the string to be converted.
 * Return: 0 if no numbers in string, converted number otherwise.
 */


int _atoi(char *s)
{
	int y, sign = 1, flag = 0, the_output;
	unsigned int the_result = 0;

	for (y = 0; s[y] != '\0' && flag != 2; y++)
	{
		if (s[y] == '-')
			sign *= -1;

		if (s[y] >= '0' && s[y] <= '9')
		{
			flag = 1;
			the_result *= 10;
			the_result += (s[y] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		the_output = -the_result;
	else
		the_output = the_result;

	return (the_output);
}
