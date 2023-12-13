#include "shell.h"

/**
 **_strncpy - function that copies a string.
 *@dest: the destination string to be copied to.
 *@src: the source string.
 *@n: the amount of characters to be copied.
 *Return: the concatenated string.
 */

char *_strncpy(char *dest, char *src, int n)
{
	int y, k;
	char *d = dest;

	y = 0;
	while (src[y] != '\0' && y < n - 1)
	{
		dest[y] = src[y];
		y++;
	}
	if (y < n)
	{
		k = y;
		while (k < n)
		{
			dest[k] = '\0';
			k++;
		}
	}
	return (d);
}

/**
 **_strncat - function that concatenates two strings.
 *@dest: the first string.
 *@src: the second string.
 *@n: the amount of bytes to be maximally used.
 *
 *Return: the concatenated string.
 */

char *_strncat(char *dest, char *src, int n)
{
	int y, k;
	char *d = dest;

	y = 0;
	k = 0;
	while (dest[y] != '\0')
		y++;
	while (src[k] != '\0' && k < n)
	{
		dest[y] = src[k];
		y++;
		k++;
	}
	if (k < n)
		dest[y] = '\0';
	return (d);
}

/**
 **_strchr - function that locates a character in a string.
 *@s: the string to be parsed.
 *@c: the character to look for.
 *Return: (s) a pointer to the memory area s.
 */

char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
