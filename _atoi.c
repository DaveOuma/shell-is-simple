#include "shell.h"

/**
 * Interactive - Checks if the shell is in interactive mode.
 * @info: Pointer to the info_t struct.
 *
 * Return: 1 if the shell is in interactive mode, 0 otherwise.
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - Checks if a Char is a delimiter.
 * @c: The Char to be checked.
 * @delim: The delimiter a string.
 * Return: 1 if the Char is a delimiter; 0 otherwise.
 */
int is_delim(char c, char *delim)
{
	while (*delim)

		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 * _isalpha - Checks if a Char is alphabetic.
 * @c: The character to be checked.
 * Return: 1 if the character is alphabetic; 0 otherwise.
 */
int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - Converting a str to an int.
 * @s: The string to be converted thereof.
 * Return: The converted int, or 0 if no num is in the str.
 */
int _atoi(char *s)
{
	int x, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (x = 0; s[x] != '\0' && flag != 2; x++)
	{
		if (s[x] == '-')
			sign *= -1;

		if (s[x] >= '0' && s[x] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[x] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
