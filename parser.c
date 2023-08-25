#include "shell.h"

/**
 * is_cmd - determines if excecutable or not (file)
 * @info: info struct.
 * @path: path to file the subject file.
 *
 * Return: 1 for true, 0 false
 */
int is_cmd(info_t *info, char *path)
{
	struct stat st;

	(void)info;
	if (!path || stat(path, &st))/*checks state of path*/
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);/*state return*/
	}
	return (0);
}

/**
 * dup_chars - duplicates chars.
 * @pathstr: the path str.
 * @start: first index
 * @stop: last index.
 *
 * Return: ptr to the new buffer.
 */
char *dup_chars(char *pathstr, int start, int stop)
{
	static char buf[1024];
	int i = 0, j = 0;

	for (j = 0, i = start; i < stop; i++)
		if (pathstr[i] != ':')
			buf[j++] = pathstr[i];
	buf[j] = 0;
	return (buf);
}

/**
 * find_path - findscommand in path str.
 * @info: info struct.
 * @pathstr: PATH string.
 * @cmd: command to be found.
 *
 * Return: path of command or else NULL
 */
char *find_path(info_t *info, char *pathstr, char *cmd)
{
	int i = 0, curr_pos = 0;
	char *path;

	if (!pathstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))/* checking command*/
	{
		if (is_cmd(info, cmd))/*if path is not empty*/
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[i] || pathstr[i] == ':')
		{
			path = dup_chars(pathstr, curr_pos, i);
			if (!*path)
				_strcat(path, cmd);
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}
			if (is_cmd(info, path))
				return (path);
			if (!pathstr[i])
				break;
			curr_pos = i;
		}
		i++;
	}
	return (NULL);
}
