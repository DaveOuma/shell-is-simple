#include "shell.h"

/**
 * get_history_file - Retrieves the history file path
 * @info: parameter structure
 *
 * Return: The allocated string comprising the history file path.
 */
char *get_history_file(info_t *info)
{
	char *path, *dir;

	dir = _getenv(info, "HOME=");
	if (!dir)
		return (NULL);
	path = malloc(sizeof(char) * (_strlen(dir) + _strlen(HIST_FILE) + 2));
	if (!path)
		return (NULL);
	path[0] = 0;
	_strcpy(path, dir);
	_strcat(path, "/");
	_strcat(path, HIST_FILE);
	return (path);
}

/**
 * write_history - Develops or appends to a history file
 * @info: Parameter structure.
 *
 * Return: 1 on success, -1 on failure
 */
int write_history(info_t *info)
{
	ssize_t fd;
	char *filename = get_history_file(info);
	list_t *node = NULL;

	if (!filename)
		return (-1);

	fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(filename);
	if (fd == -1)
		return (-1);
	for (node = info->history; node; node = node->next)
	{
		_putsfd(node->str, fd);
		_putfd('\n', fd);
	}
	_putfd(BUF_FLUSH, fd);
	close(fd);
	return (1);
}

/**
 * read_history - This reads history from a file.
 * @info: The parameter structure.
 *
 * Return: The count of history entries on success, 0 on failure
 */
int read_history(info_t *info)
{
	int i, last = 0, line_count = 0;
	ssize_t fd, read_length, file_size = 0;
	struct stat st;
	char *buf = NULL, *filename = get_history_file(info);

	if (!filename)
		return (0);

	fd = open(filename, O_RDONLY);
	free(filename);
	if (fd == -1)
		return (0);
	if (!fstat(fd, &st))
		file_size = st.st_size;
	if (file_size < 2)
		return (0);
	buf = malloc(sizeof(char) * (file_size + 1));
	if (!buf)
		return (0);
	read_length = read(fd, buf, file_size);
	buf[file_size] = 0;
	if (read_length <= 0)
		return (free(buf), 0);
	close(fd);
	for (i = 0; i < file_size; i++)
		if (buf[i] == '\n')
		{
			buf[i] = 0;
			build_history_list(info, buf + last, line_count++);
			last = i + 1;
		}
	if (last != i)
		build_history_list(info, buf + last, line_count++);
	free(buf);
	info->histcount = line_count;
	while (info->histcount-- >= HIST_MAX)
		delete_node_at_index(&(info->history), 0);
	renumber_history(info);
	return (info->histcount);
}

/**
 * build_history_list - This appends an entry to the history linked list.
 * @info: parameter structure
 * @buffer: the buffer containing the history entry
 * @line_count: the history line count
 *
 * Return: Always 0
 */
int build_history_list(info_t *info, char *buffer, int line_count)
{
	list_t *node = NULL;

	if (info->history)
		node = info->history;
	add_node_end(&node, buffer, line_count);

	if (!info->history)
		info->history = node;
	return (0);
}

/**
 * renumber_history - Updates the history line numbers.
 * @info: Parameter structure.
 *
 * Return: This is the new histcount.
 */
int renumber_history(info_t *info)
{
	list_t *node = info->history;
	int count = 0;

	while (node)
	{
		node->num = count++;
		node = node->next;
	}
	return (info->histcount = count);
}
