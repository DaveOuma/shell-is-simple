#include "shell.h"

/**
 * list_len - determines len of the list.
 * @h: ptr to the first node.
 *
 * Return: list size
 */
size_t list_len(const list_t *h)
{
	size_t s = 0;

	while (h)
	{
		h = h->next;
		s++;
	}
	return (s);
}

/**
 * list_to_strings - array of strings list->str.
 * @head: ptr to first node
 *
 * Return: string array
 */
char **list_to_strings(list_t *head)
{
	list_t *node = head;
	size_t i = list_len(head), j;
	char **strs;
	char *str;

	if (!head || !i)
		return (NULL);
	strs = malloc(sizeof(char *) * (i + 1));
	if (!strs)
		return (NULL);
	for (i = 0; node; node = node->next, i++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (j = 0; j < i; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		strs[i] = str;
	}
	strs[i] = NULL;
	return (strs);
}


/**
 * print_list - displays elements of a list
 * @h: ptr to first node.
 *
 * Return: list size
 */
size_t print_list(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		_puts(convert_number(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * node_starts_with - begining node
 * @node: ptr to head
 * @prefix: string.
 * @c: next char.
 *
 * Return: node.
 */
list_t *node_starts_with(list_t *node, char *prefix, char c)
{
	char *t = NULL;

	while (node)
	{
		t = starts_with(node->str, prefix);/*begining node*/
		if (t && ((c == -1) || (*t == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * get_node_index - gets index of node.
 * @head: ptr to first node.
 * @node: ptr to the node.
 *
 * Return: index or -1
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t i = 0;

	while (head)
	{
		if (head == node)
			return (i);
		head = head->next;
		i++;
	}
	return (-1);
}
