#include "shell.h"

/**
 * list_len - function determines length of linked list.
 * @h: the pointer to first node.
 *
 * Return: size of list.
 */
size_t list_len(const list_t *h)
{
	size_t y = 0;

	while (h)
	{
		h = h->next;
		y++;
	}
	return (y);
}

/**
 * list_to_strings - function that returns an array
 * of strings of the list->str.
 * @head: the pointer to first node.
 *
 * Return: array of strings.
 */
char **list_to_strings(list_t *head)
{
	list_t *node = head;
	size_t y = list_len(head), k;
	char **strs;
	char *str;

	if (!head || !y)
		return (NULL);
	strs = malloc(sizeof(char *) * (y + 1));
	if (!strs)
		return (NULL);
	for (y = 0; node; node = node->next, y++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (k = 0; k < y; k++)
				free(strs[k]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		strs[y] = str;
	}
	strs[y] = NULL;
	return (strs);
}


/**
 * print_list - function that prints all elements of a list_t linked list.
 * @h: the pointer to first node.
 *
 * Return: size of list.
 */
size_t print_list(const list_t *h)
{
	size_t y = 0;

	while (h)
	{
		_puts(convert_number(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		y++;
	}
	return (y);
}

/**
 * node_starts_with - function that returns node
 * whose string starts with prefix.
 * @node: the pointer to list head.
 * @prefix: the string to match.
 * @c: the next character after prefix to match.
 *
 * Return: match node or null.
 */
list_t *node_starts_with(list_t *node, char *prefix, char c)
{
	char *b = NULL;

	while (node)
	{
		b = starts_with(node->str, prefix);
		if (b && ((c == -1) || (*b == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * get_node_index - function that gets the index of a node.
 * @head: the pointer to list head.
 * @node: the pointer to the node.
 *
 * Return: index of node or -1.
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t y = 0;

	while (head)
	{
		if (head == node)
			return (y);
		head = head->next;
		y++;
	}
	return (-1);
}
