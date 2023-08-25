#include "shell.h"

/**
 **_memset - fills mem with  const byte.
 *@s: ptr to memory.
 *@b: byte to fill mem with.
 *@n: amnt of bytes to be used to fill.
 *Return: a ptr to the memory.
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int m;

	for (m = 0; m < n; m++)
		s[m] = b;
	return (s);
}

/**
 * ffree - frees a string in mem.
 * @pp: str.
 */
void ffree(char **pp)
{
	char **a = pp;/*str pointer*/

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(a);
}

/**
 * _realloc - reallocates the amount of memory.
 * @ptr: pointer to the memory to be reallocated.
 * @old_size: size of previous block of mem.
 * @new_size: byte size of new block mem.
 *
 * Return: pointer to new mem.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}
