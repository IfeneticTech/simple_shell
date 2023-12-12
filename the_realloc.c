#include "shell.h"


/**
 * _memset - function that fills memory with a constant byte.
 * @s: the pointer to the memory area.
 * @b: the byte to fill *s with.
 * @n: the amount of bytes to be filled.
 * Return: (s) a pointer to the memory area s.
 */
char *_memset(char *s, char b, unsigned int n)
{
    unsigned int y;


    for (y = 0; y < n; y++)
        s[y] = b;
    return (s);
}


/**
 * ffree - function that frees a string of strings.
 * @pp: the string of strings.
 */
void ffree(char **pp)
{
    char **s = pp;


    if (!pp)
        return;
    while (*pp)
        free(*pp++);
    free(s);
}


/**
 * _realloc - function that reallocates a block of memory.
 * @ptr: the pointer to previous malloc'ated block.
 * @old_size: the byte size of previous block.
 * @new_size: the byte size of new block.
 *
 * Return: pointer to da ol'block nameen.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
    char *b;


    if (!ptr)
        return (malloc(new_size));
    if (!new_size)
        return (free(ptr), NULL);
    if (new_size == old_size)
        return (ptr);


    b = malloc(new_size);
    if (!b)
        return (NULL);


    old_size = old_size < new_size ? old_size : new_size;
    while (old_size--)
        b[old_size] = ((char *)ptr)[old_size];
    free(ptr);
    return (b);
}
