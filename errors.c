#include "simple_shell.h"

/**
 *_eputs - fuction to Print string that was inputted.
 * @str: The printed string
 *
 * no return void.
 */
void _eputs(char *str)
{
	int p;

	p = 0;

	if (!str)
		return;
	while (str[p] != '\0')
	{
		_eputchar(str[p]);
		p++;
	}
}

/**
 * _eputchar - function that Writes the character c to stderr.
 * @c: The character to print.
 * Return: 1 on success or -1 on failure.
 */
int _eputchar(char c)
{
	static int p;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || p >= WRITE_BUF_SIZE)
	{
		write(2, buf, p);
		p = 0;
	}
	if (c != BUF_FLUSH)
		buf[p++] = c;
	return (1);
}

/**
 * _putfd - function toWrite the character
 * c to given fd.
 * @c: The character to be printed.
 * @fd: The filedescriptor to be written to.
 * Return: 1, on success or -1, on failure.
 */
int _putfd(char c, int fd)
{
	static int p;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || p >= WRITE_BUF_SIZE)
	{
		write(fd, buf, p);
		p = 0;
	}
	if (c != BUF_FLUSH)
		buf[p++] = c;
	return (1);
}

/**
 *_putsfd - Prints a string input.
 * @str: The will be printed string.
 * @fd: The filedescriptor to bewritten to.
 * Return: The number of chars inputted.
 */
int _putsfd(char *str, int fd)
{
	int p;

	p = 0;

	if (!str)
		return (0);
	while (*str)
	{
		p += _putfd(*str++, fd);
	}
	return (p);
}
