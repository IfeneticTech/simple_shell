#include "shell.h"

/**
 * is_chain - test if current char in buffer is a chain delimeter
 * @info: the parameter struct
 * @buf: the char buffer
 * @p: address of current position in buf
 *
 * Return: 1 if chain delimeter, 0 otherwise
 */
int is_chain(info_t *info, char *buf, size_t *p)
{
	size_t k = *p;

	if (buf[k] == '|' && buf[k + 1] == '|')
	{
		buf[k] = 0;
		k++;
		info->cmd_buf_type = CMD_OR;
	}
	else if (buf[k] == '&' && buf[k + 1] == '&')
	{
		buf[k] = 0;
		k++;
		info->cmd_buf_type = CMD_AND;
	}
	else if (buf[k] == ';') /* found end of this command */
	{
		buf[k] = 0; /* replace semicolon with null */
		info->cmd_buf_type = CMD_CHAIN;
	}
	else
		return (0);
	*p = k;
	return (1);
}

/**
 * check_chain - function checks we should continue chaining
 * based on last status.
 * @info: the parameter struct.
 * @buf: the char buffer.
 * @p: the address of current position in buf.
 * @i: the starting position in buf.
 * @len: the length of buf.
 *
 * Return: Void.
 */
void check_chain(info_t *info, char *buf, size_t *p, size_t i, size_t len)
{
	size_t k = *p;

	if (info->cmd_buf_type == CMD_AND)
	{
		if (info->status)
		{
			buf[i] = 0;
			k = len;
		}
	}
	if (info->cmd_buf_type == CMD_OR)
	{
		if (!info->status)
		{
			buf[i] = 0;
			k = len;
		}
	}

	*p = k;
}

/**
 * replace_alias - function that replaces an aliases in the tokenized string.
 * @info: the parameter struct.
 *
 * Return: 1 if replaced, 0 otherwise.
 */
int replace_alias(info_t *info)
{
	int y;
	list_t *node;
	char *b;

	for (y = 0; y < 10; y++)
	{
		node = node_starts_with(info->alias, info->argv[0], '=');
		if (!node)
			return (0);
		free(info->argv[0]);
		b = _strchr(node->str, '=');
		if (!b)
			return (0);
		b = _strdup(b + 1);
		if (!b)
			return (0);
		info->argv[0] = b;
	}
	return (1);
}

/**
 * replace_vars - function that replaces vars in the tokenized string.
 * @info: the parameter struct.
 *
 * Return: 1 if replaced, 0 otherwise.
 */
int replace_vars(info_t *info)
{
	int y = 0;
	list_t *node;

	for (y = 0; info->argv[y]; y++)
	{
		if (info->argv[y][0] != '$' || !info->argv[y][1])
			continue;

		if (!_strcmp(info->argv[y], "$?"))
		{
			replace_string(&(info->argv[y]),
					_strdup(convert_number(info->status, 10, 0)));
			continue;
		}
		if (!_strcmp(info->argv[y], "$$"))
		{
			replace_string(&(info->argv[y]),
					_strdup(convert_number(getpid(), 10, 0)));
			continue;
		}
		node = node_starts_with(info->env, &info->argv[y][1], '=');
		if (node)
		{
			replace_string(&(info->argv[y]),
					_strdup(_strchr(node->str, '=') + 1));
			continue;
		}
		replace_string(&info->argv[y], _strdup(""));

	}
	return (0);
}

/**
 * replace_string - function that replaces string.
 * @old: the address of old string.
 * @new: the new string.
 *
 * Return: 1 if replaced, 0 otherwise.
 */
int replace_string(char **old, char *new)
{
	free(*old);
	*old = new;
	return (1);
}
