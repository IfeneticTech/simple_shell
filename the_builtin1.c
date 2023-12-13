#include "shell.h"

/**
 * _myhistory - function that displays the history list,
 * one command by line, preceded with line numbers, starting at 0.
 * @info: structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - function that sets alias to string.
 * @info: the parameter struct.
 * @str: the string alias.
 *
 * Return: Always 0 on success, 1 on error.
 */
int unset_alias(info_t *info, char *str)
{
	char *b, v;
	int rett;

	b = _strchr(str, '=');
	if (!b)
		return (1);
	v = *b;
	*b = 0;
	rett = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*b = v;
	return (rett);
}

/**
 * set_alias - function that sets alias to string.
 * @info: the parameter struct.
 * @str: the string alias.
 *
 * Return: Always 0 on success, 1 on error.
 */
int set_alias(info_t *info, char *str)
{
	char *b;

	b = _strchr(str, '=');
	if (!b)
		return (1);
	if (!*++b)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - function that prints an alias string.
 * @node: the alias node.
 *
 * Return: Always 0 on success, 1 on error.
 */
int print_alias(list_t *node)
{
	char *b = NULL, *s = NULL;

	if (node)
	{
		b = _strchr(node->str, '=');
		for (s = node->str; s <= b; s++)
		_putchar(*s);
		_putchar('\'');
		_puts(b + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - function that mimics the alias builtin (man alias).
 * @info: the structure containing potential arguments.
 * used to maintain constant function prototype.
 *
 *  Return: Always 0
 */
int _myalias(info_t *info)
{
	int y = 0;
	char *b = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (y = 1; info->argv[y]; y++)
	{
		b = _strchr(info->argv[y], '=');
		if (b)
			set_alias(info, info->argv[y]);
		else
			print_alias(node_starts_with(info->alias, info->argv[y], '='));
	}

	return (0);
}
