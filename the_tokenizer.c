#include "shell.h"

/**
 * **strtow - function that splits a string into words.
 * repeat delimiters are ignored.
 * @str: the input string.
 * @d: the delimeter string.
 * Return: a pointer to an array of strings, or NULL on failure.
 */

char **strtow(char *str, char *d)
{
	int y, j, k, m, numwords = 0;
	char **f;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (y = 0; str[y] != '\0'; y++)
		if (!is_delim(str[y], d) && (is_delim(str[y + 1], d) || !str[y + 1]))
			numwords++;

	if (numwords == 0)
		return (NULL);
	f = malloc((1 + numwords) * sizeof(char *));
	if (!f)
		return (NULL);
	for (y = 0, j = 0; j < numwords; j++)
	{
		while (is_delim(str[y], d))
			y++;
		k = 0;
		while (!is_delim(str[y + k], d) && str[y + k])
			k++;
		f[j] = malloc((k + 1) * sizeof(char));
		if (!f[j])
		{
			for (k = 0; k < j; k++)
				free(f[k]);
			free(f);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			f[j][m] = str[y++];
		f[j][m] = 0;
	}
	f[j] = NULL;
	return (f);
}

/**
 * **strtow2 - function that splits a string into words.
 * @str: the input string.
 * @d: the delimeter.
 * Return: a pointer to an array of strings, or NULL on failure.
 */
char **strtow2(char *str, char d)
{
	int y, j, k, m, numwords = 0;
	char **f;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (y = 0; str[y] != '\0'; y++)
		if ((str[y] != d && str[y + 1] == d) ||
				    (str[y] != d && !str[y + 1]) || str[y + 1] == d)
			numwords++;
	if (numwords == 0)
		return (NULL);
	f = malloc((1 + numwords) * sizeof(char *));
	if (!f)
		return (NULL);
	for (y = 0, j = 0; j < numwords; j++)
	{
		while (str[y] == d && str[y] != d)
			y++;
		k = 0;
		while (str[y + k] != d && str[y + k] && str[y + k] != d)
			k++;
		f[j] = malloc((k + 1) * sizeof(char));
		if (!f[j])
		{
			for (k = 0; k < j; k++)
				free(f[k]);
			free(f);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			f[j][m] = str[y++];
		f[j][m] = 0;
	}
	f[j] = NULL;
	return (f);
}
