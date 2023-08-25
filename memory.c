#include "shell.h"

/**
 * bfree - frees a ptr address.
 * @ptr: address ptr to free.
 *
 * Return: 1 for success.
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
