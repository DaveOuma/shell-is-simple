#include "shell.h"

/**
 * _strlen - gets length of a string.
 * @s: str to be checked.
 * Return: string len.
 */
int _strlen(char *s)
{
	int t = 0;

	if (!s)
		return (0);

	while (*s++)
		t++;
	return (t);
}

/**
 * _strcmp - lexicogarphically compares two strangs.
 * @s1: str1.
 * @s2: str2.
 * Return: -ve if s1 < s2, +ve if s1 > s2, 0 if s1 == s2
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
 * starts_with - checks if haystack stats in needle.
 * @haystack: string to check.
 * @needle: substring to find
 *
 * Return: ptr of first char of haystack otherwise NULL.
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat - concatenates strings.
 * @dest: destination buffer.
 * @src: source buffer.
 * Return: ptr to dest.
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
