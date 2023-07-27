#include "shell.h"

/**
 * _myhistory - displays history list
 * @info: Struct containing args
 *  Return: Always 0
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - sets alias to string
 * @info: struct
 * @str: the string alias
 * Return: Always 0 on success
 */
int unset_alias(info_t *info, char *str)
{
	char *a, b;
	int set;

	a = _strchr(str, '=');

	if (!a)
	{
		return (1);
	}
	b = *a;
	*a = 0;
	set = delete_node_at_index(&(info->alias),
			get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*a = b;
	return (set);
}

/**
 * set_alias - sets alias to string
 * @info: parameter struct
 * @str: the string
 * Return: Always 0 on success
 */
int set_alias(info_t *info, char *str)
{
	char *a;

	a = _strchr(str, '=');

	if (!a)
	{
		return (1);
	}
	if (!*++a)
	{
		return (unset_alias(info, str));
	}
	unset_alias(info, str);

	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - prints an alias string
 * @node: the alias node
 * Return: Always 0 on success
 */
int print_alias(list_t *node)
{
	char *i = NULL, *b = NULL;
	if (node)
	{
		i = _strchr(node->str, '=');
		
		for (b = node->str; b <= i; b++)
		{
			_putchar(*b);
		}
		_putchar('\'');
		_puts(i + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - mimics the alias builtin (man alias)
 * @info: Struct containing args.
 * Return: Always 0
 */
int _myalias(info_t *info)
{
	int a = 0;
	char *p = NULL;
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
	for (a = 1; info->argv[a]; a++)
	{
		p = _strchr(info->argv[a], '=');
		if (p)
		{
			set_alias(info, info->argv[a]);
		}
		else
			print_alias(node_starts_with(info->alias, info->argv[a], '='));
	}
	return (0);
}
