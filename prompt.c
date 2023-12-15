#include "shell.h"

/**
 * read_line - Read a line from standard input.
 *
 * Return: The line read.
 */
char *read_line(void)
{
	char *line = NULL;
	size_t len = 0;

	if (getline(&line, &len, stdin) == -1)
	{
		free(line);
		return (NULL);
	}

	return (line);
}
