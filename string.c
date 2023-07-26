#include "shell.h"

/**
 * _strlen - length of a string
 * @s: string whose length to check
 * Return: integer length of string
 */
int _strlen(char *s)
{
    	int a = 0;


    	if (!s)
            	return (0);


    	while (*s++)
            	a++;
    	return (a);
}


/**
 * _strcmp - performs lexicogarphic comparison of two strangs.
 * @s1: 1st string
 * @s2: 2nd string
 * Return: negative if s1 < s2, positive if s1 > s2, zero if s1 == s2
 */
int _strcmp(char *s1, char *s2)
{
    	while (*s1 && *s2)
    	{
            	if (*s1 != *s2)
                    	return (*s1 - *s2);
            	s1++;
            	s2++;
    	}
    	if (*s1 == *s2)
            	return (0);
    	else
            	return (*s1 < *s2 ? -1 : 1);
}


/**
 * starts_with - checks if needle starts with haystack
 * @haystack: string
 * @needle: the substring
 * Return: address of haystack
 */
char *starts_with(const char *haystack, const char *needle)
{
    	while (*needle)
            	if (*needle++ != *haystack++)
                    	return (NULL);
    	return ((char *)haystack);
}


/**
 * _strcat - joins 2 strings
 * @dest: destination buff
 * @src: source buff
 * Return: pointer
 */
char *_strcat(char *dest, char *src)
{
    	char *ret = dest;


    	while (*dest)
            	dest++;
    	while (*src)
            	*dest++ = *src++;
    	*dest = *src;
    	return (ret);
}
/**
 * _puts - prints an inputted string
 * @str: string
 * Return: Nothing
 */
void _puts(char *str)
{
    	int a = 0;


    	if (!str)
            	return;
    a = 0;

    	for (a = 0; str[a] != '\0'; a++)
    	{
            	_putchar(str[a]);
    	}
}


/**
 * _putchar - outputs character c to stdout
 * @c: char to print
 * Return: On success 1 on error, -1 is returned.
 */
int _putchar(char c)
{
    	static int a;
    	static char buf[WRITE_BUF_SIZE];


    	if (c == BUF_FLUSH || a >= WRITE_BUF_SIZE)
    	{
            	write(1, buf, a);
            	a = 0;
    	}
    	if (c != BUF_FLUSH)
            	buf[a++] = c;
    	return (1);
}
