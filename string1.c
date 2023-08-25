#include "shell.h"

/**
 * _strcpy - copies a string of chars.
 * @dest: destination.
 * @src: source.
 *
 * Return: ptr to destination location.
 */
char *_strcpy(char *dest, char *src)
{
	int x = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[x])
	{
		dest[x] = src[x];
		x++;
	}
	dest[x] = 0;
	return (dest);
}

/**
 * _strdup - duplicates a string of chars.
 * @str: str of chars to duplicate
 *
 * Return: pointer to str.
 */
char *_strdup(const char *str)
{
	int length = 0;
	char *ret;

	if (str == NULL)
		return (NULL);
	while (*str++)
		length++;
	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (NULL);
	for (length++; length--;)
		ret[length] = *--str;
	return (ret);
}

/**
 *_puts - prints input str.
 *@str: str to be printed.
 * Return: Nothing (void).
 */
void _puts(char *str)
{
	int j = 0;

	if (!str)
		return;
	while (str[j] != '\0')
	{
		_putchar(str[j]);
		j++;
	}
}

/**
 * _putchar - displays char to standardoutput.
 * @c: The char to display.
 * Return: 1 success.
 * On error, -1 is returned.
 */
int _putchar(char c)
{
	static int m;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || m >= WRITE_BUF_SIZE)
	{
		write(1, buf, m);
		m = 0;
	}
	if (c != BUF_FLUSH)
		buf[m++] = c;
	return (1);
}
