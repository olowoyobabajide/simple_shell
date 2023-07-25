#include "shell.h"

/**
 **_strncpy - copies a string
 *@dest: dest str
 *@src: the source
 *@n: no of char to be copied
 *Return: the concatenated string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int a, b;

	char *s = dest;

	a = 0;
	while (src[a] != '\0' && a < n - 1)
	{
		dest[a] = src[a];
		a++;
	}
	if (a < n)
	{
		b = a;
		while (b < n)
		{
			dest[b] = '\0';
			b++;
		}
	}
	return (s);
}

/**
 **_strncat - joins 2 strings
 *@dest: the first str
 *@src: the second str
 *@n: the amount of bytes to be maximally used
 *Return: concatenated string
 */
char *_strncat(char *dest, char *src, int n)
{
	int a, b;
	char *s = dest;

	a = 0;
	b = 0;
	while (dest[a] != '\0')
		a++;
	while (src[b] != '\0' && b < n)
	{
		dest[a] = src[b];
		a++;
		b++;
	}
	if (b < n)
		dest[a] = '\0';
	return (s);
}

/**
 **_strchr - locates a char in a string
 *@s: the string to be parsed
 *@c: the character to look for
 *Return: pointer to the memory area s
 */
char *_strchr(char *s, char c)
{
	do
	{
		if (*s == c)
			return (s);
	}
	while (*s++ != '\0');

	return (NULL);
}
