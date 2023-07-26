#include "shell.h"

/**
 * list_len - determines length of linked list
 * @h: pointer to first node
 * Return: size of list
 */
size_t list_len(const list_t *h)
{
    	size_t a = 0;


    	while (h)
    	{
            	h = h->next;
            	a++;
    	}
    	return (a);
}


/**
 * list_to_strings - returns an array of list->str
 * @head: pointer to first node
 * Return: string array
 */
char **list_to_strings(list_t *head)
{
    	list_t *node = head;
    	size_t a = list_len(head), j;
    	char **strs;
    	char *str;


    	if (!head || !a)
            	return (NULL);
    	strs = malloc(sizeof(char *) * (a + 1));
    	if (!strs)
            	return (NULL);
    	for (a = 0; node; node = node->next, a++)
    	{
            	str = malloc(_strlen(node->str) + 1);
            	if (!str)
            	{
                    	for (j = 0; j < a; j++)
                            	free(strs[j]);
                    	free(strs);
                    	return (NULL);
            	}


            	str = strcpy(str, node->str);
            	strs[a] = str;
    	}
    	strs[a] = NULL;
    	return (strs);
}


/**
 * print_list - prints all elements of list_t
 * @h: pointer to first node
 * Return: list size
 */
size_t print_list(const list_t *h)
{
    	size_t a = 0;

    	while (h)
    	{
            	_puts(convert_number(h->num, 10, 0));
            	_putchar(':');
            	_putchar(' ');
            	_puts(h->str ? h->str : "(nil)");
            	_puts("\n");
            	h = h->next;
            	a++;
    	}
    	return (a);
}


/**
 * node_starts_with - node whose string starts with prefix
 * @node: pointer to head
 * @prefix: string to match
 * @c: next character after prefix
 * Return: match node
 */
list_t *node_starts_with(list_t *node, char *prefix, char c)
{
    	char *a = NULL;


    	while (node)
    	{
            	a = starts_with(node->str, prefix);
            	if (a && ((c == -1) || (*a == c)))
                    	return (node);
            	node = node->next;
    	}
    	return (NULL);
}

/**
 * get_node_index - returns node index
 * @head: pointer to head
 * @node: pointer to node
 * Return: index of node
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
    	size_t a = 0;


    	while (head)
    	{
            	if (head == node)
                    	return (a);
            	head = head->next;
            	a++;
    	}
    	return (-1);
}
