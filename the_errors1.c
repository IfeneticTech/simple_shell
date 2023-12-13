#include "shell.h"

/**
 * _erratoi - function that converts a string to an integer.
 * @s: the string to be converted.
 * Return: 0 if no numbers in string, converted number otherwise
 *       -1 on error.
 */
int _erratoi(char *s)
{
	int y = 0;
	unsigned long int the_result = 0;

	if (*s == '+')
		s++;  /* TODO: why does this make main return 255? */
	for (y = 0;  s[y] != '\0'; y++)
	{
		if (s[y] >= '0' && s[y] <= '9')
		{
			the_result *= 10;
			the_result += (s[y] - '0');
			if (the_result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (the_result);
}

/**
 * print_error - function that prints an error message.
 * @info: the parameter & return info struct.
 * @estr: the string containing specified error type.
 * Return: 0 if no numbers in string, converted number otherwise
 *        -1 on error.
 */
void print_error(info_t *info, char *estr)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estr);
}

/**
 * print_d - function that prints a decimal (integer) number (base 10).
 * @input: the input.
 * @fd: the filedescriptor to write to.
 *
 * Return: number of characters printed.
 */
int print_d(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int y, count = 0;
	unsigned int _abs_, current;

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		count++;
	}
	else
		_abs_ = input;
	current = _abs_;
	for (y = 1000000000; y > 1; y /= 10)
	{
		if (_abs_ / y)
		{
			__putchar('0' + current / y);
			count++;
		}
		current %= y;
	}
	__putchar('0' + current);
	count++;

	return (count);
}

/**
 * convert_number - a converter function, a clone of itoa.
 * @num: the number.
 * @base: the base.
 * @flags: the argument flags.
 *
 * Return: string.
 */
char *convert_number(long int num, int base, int flags)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long m = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		m = -num;
		sign = '-';

	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[m % base];
		m /= base;
	} while (m != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * remove_comments - function that replaces first instance of '#' with '\0'.
 * @buf: the address of the string to modify.
 *
 * Return: Always 0.
 */
void remove_comments(char *buf)
{
	int y;

	for (y = 0; buf[y] != '\0'; y++)
		if (buf[y] == '#' && (!y || buf[y - 1] == ' '))
		{
			buf[y] = '\0';
			break;
		}
}
