#include "shell.h"

/**
 * _memset - fills memory with a constant byte
 * @s: pointer to the memory
 * @b: byte to fill
 * @n: amount of bytes to fill
 * Return: (s) a pointer to the memory
 */
char *_memset(char *s, char b, unsigned int n)
{
    	unsigned int a;

    a = 0;

    	while (a < n)
            	s[a] = b;
   	 a++;
    	return (s);
}


/**
 * ffree - frees a string of strings
 * @pp: string of strings
 */
void ffree(char **pp)
{
    	char **str = pp;


    	if (!pp)
            	return;
    	while (*pp)
            	free(*pp++);
    	free(str);
}


/**
 * _realloc - reallocates a block of memory
 * @ptr: pointer to previous allocated block
 * @old_size: previous block byte size
 * @new_size: new block byte size
 * Return: pointer to da ol'block nameen.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
    	char *str;


    	if (!ptr)
            	return (malloc(new_size));
    	if (!new_size)
            	return (free(ptr), NULL);
    	if (new_size == old_size)
            	return (ptr);


    	str = malloc(new_size);
    	if (!ptr)
            	return (NULL);


    	old_size = old_size < new_size ? old_size : new_size;
    	while (old_size--)
            	str[old_size] = ((char *)ptr)[old_size];
    	free(ptr);
    	return (str);
}
