#include "shell.h"

/**
 * interactive - returns true if in interactive mode
 * @info: struct address
 * Return: 1 if interactive mode
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - checks if character is a delimeter
 * @c: char to check
 * @delim: delimeter string
 * Return: 1 if true
 */
int is_delim(char c, char *delim)
{
	while (*delim)
	{
		if (*delim++ == c)
			return (1);
	}
	return (0);
}

/**
 * _isalpha - checks for alphabetic char
 * @c: char to input
 * Return: 1 if c is alphabetic
 */
int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - converts string to an int
 * @s: string
 * Return: 0 if no numbers in string
 */
int _atoi(char *s)
{
	int a, chn = 1, flag = 0, output;

	unsigned int result = 0;

	for (a = 0; s[a] != '\0' && flag != 2; a++)
	{
		if (s[a] == '-')
		{
			chn *= -1;
		}
		if (s[a] >= '0' && s[a] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[a] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}
	if (chn == -1)
	{
		output = -result;
	}
	else
	{
		output = result;
	}
	return (output);
}