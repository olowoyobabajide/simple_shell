#include "simple_shell.h"

/**
 * _myenv - This does printing of working environment.
 * @info: Struct that contains possible args to
 * ensure a constant function prototype.
 *
 * Return: Always 0, succeed or fail
 */

int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}


/**
 * _getenv - Retrieves the value of an environ var.
 * @info: Struct that contains possible args in
 * order to keep consistency.
 * @name: Name of the environ var.
 *
 * Return: just value of the environm variable string.
 */

char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *s;

	while (node)
	{
		s = starts_with(node->str, name);
		if (s && *s)
			return (s);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv - This starts a new environm variable,
 * or adjusts one that exists.
 * @info: Struct that could contain args
 * Used in keeping constant a function prototype.
 *
 *  Return: Always 0, on sucess or failure
 */
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect num of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - Deletes an environm variable.
 * @info: A pointer to a struct which contains possible args
 * used to keep constant a function prototype.
 *
 *  Return: Always 0, success or not
 */

int _myunsetenv(info_t *info)
{
	int o;

	if (info->argc == 1)
	{
		_eputs("Insufficient number of arguements provided.\n");
		return (1);
	}
	for (o = 1; o <= info->argc; o++)
		_unsetenv(info, info->argv[o]);

	return (0);
}

/**
 * populate_env_list - This populates an environm linked list.
 * @info: A pointer to a struct that probably contains further args
 * used to keep a constant function prototype.
 *
 * Return: Always 0, whether success or failure
 */

int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t o;

	for (o = 0; environ[o]; o++)
		add_node_end(&node, environ[o], 0);
	info->env = node;
	return (0);
}
