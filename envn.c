#include "shell.h"

/**
 * _myenv - prints current env
 * @info: containing potential args.
 * Return: Always 0
 */
int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _getenv - gets the value of an environ var
 * @info: containing potential args
 * @name: env var
 * Return: value
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *a;
	while (node)
	{
		a = starts_with(node->str, name);
		if (a && *a)
			return (a);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv - Initialize a new env var or modify existing one
 * @info: containing potential arguments.
 *  Return: Always 0
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
 * _myunsetenv - Remove an env var
 * @info: containing potential args.
 * Return: Always 0
 */
int _myunsetenv(info_t *info)
{
	int i;
	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	i = 1;
	while (i <= info->argc)
	{
		_unsetenv(info, info->argv[i]);
		i++;
	}
	return (0);
}

/**
 * populate_env_list - populates env linked list
 * @info: containing potential args.
 * Return: Always 0
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t a;

	a = 0;
	while (environ[a])
		add_node_end(&node, environ[a], 0);
	info->env = node;
	return (0);
}
