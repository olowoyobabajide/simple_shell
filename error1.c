#include "shell.h"

/**
 * _erratoi - string to int
 * @s: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 *       -1 on error
 */
int _erratoi(char *s)
{
	int a;
	unsigned long int result;

	if (*s == '+')
		s++;
	a = 0, result = 0;
	while (s[a] != '\0')
	{
		if (s[a] >= '0' && s[a] <= '9')
		{
			result *= 10;
			result += (s[a] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
		a++;
	}
	return (result);
}

/**
 * print_error - outputs error message
 * @info: the parameter & return info struct
 * @estr: string containing specified error type
 * Return: 0 if no numbers in string, converted number otherwise
 */
void print_error(info_t *info, char *estr)
{
        _eputs(info->fname);
        _eputs(": ");
        print_d(info->line_count, STDERR_FILENO);
        _eputs(": ");
        _eputs(info->argv[0]);
        _eputs(": ");
        _eputs(estr);
}

/**
 * print_d - prints a decimal (integer) number (base 10)
 * @input: input
 * @fd: filedescriptor to write to
 * Return: number of characters printed
 */
int print_d(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int a, count = 0;
	unsigned int _abs_, current;

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		count++;
	}
	else
		_abs_ = input;
	current = _abs_;
	for (a = 1000000000; a > 1; a /= 10)
	{
		if (_abs_ / a)
		{
			__putchar('0' + current / a);
			count++;
		}
		current %= a;
	}
	__putchar('0' + current);
	count++;

	return (count);
}

/**
 * convert_number - converter function
 * @num: number
 * @base: base
 * @flags: arg flags
 * Return: string
 */
char *convert_number(long int num, int base, int flags)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long a = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		a = -num;
		sign = '-';
	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';
	
	do
	{
		*--ptr = array[a % base];
		a /= base;
	}
	while (a != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * remove_comments - it replaces first instance of '#' with '\0'
 * @buf: string address to modify
 * Return: Always 0;
 */
void remove_comments(char *buf)
{
	int a;

	a = 0;
	
	while (buf[a] != '\0')
	{
		if (buf[a] == '#' && (!a || buf[a - 1] == ' '))
		{
			buf[a] = '\0';
			break;
		}
		a++;
	}
}
