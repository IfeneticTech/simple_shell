#include "shell.h"

/**
 * _myenv - function that prints the current environment.
 * @info: structure containing potential arguments.
 * used to maintain constant function prototype.
 *
 * Return: Always 0
 */
int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _getenv - function that gets the value of an environ variable.
 * @info: structure containing potential arguments.
 * used to maintain constant function prototype.
 *
 * @name: the env var name.
 *
 * Return: the value.
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *b;

	while (node)
	{
		b = starts_with(node->str, name);
		if (b && *b)
			return (b);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv - function that initialize a new environment variable,
 *             or modify an existing one.
 * @info: the structure containing potential arguments.
 * used to maintain constant function prototype.
 *
 *  Return: Always 0.
 */
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - function that remove an environment variable.
 * @info: the structure containing potential arguments.
 * used to maintain constant function prototype.
 *
 * Return: Always 0.
 */
int _myunsetenv(info_t *info)
{
	int y;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (y = 1; y <= info->argc; y++)
		_unsetenv(info, info->argv[y]);

	return (0);
}

/**
 * populate_env_list - function that populates env linked list.
 * @info: Structure containing potential arguments.
 * used to maintain constant function prototype.
 *
 * Return: Always 0
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t y;

	for (y = 0; environ[y]; y++)
		add_node_end(&node, environ[y], 0);
	info->env = node;
	return (0);
}
