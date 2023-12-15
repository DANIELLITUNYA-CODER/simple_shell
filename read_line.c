#include "shell.h"

/**
 * read_line - Read a line from standard input.
 *
 * Return: A pointer to the read line, or NULL on failure or EOF.
 */
char *read_line(void)
{
	char *line = NULL;
	size_t bufsize = 0;

	if (getline(&line, &bufsize, stdin) == -1)
	{
		free(line);
		line = NULL;
	}

	return (line);
}
