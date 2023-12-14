#include "shell.h"
#include <stdio.h>

/**
 * interactive_mode - Handles interactive mode of the shell
 */
void interactive_mode(void)
{
	char command[100];

	while (1)
	{
		printf("($) ");
		if (fgets(command, sizeof(command), stdin) == NULL)
		{
			break;
		}
	}
}

/**
 * non_interactive_mode - Handles non-interactive mode of the shell
 */
void non_interactive_mode(void)
{
	char command[100];

	while (fgets(command, sizeof(command), stdin) != NULL)
	{
	}
}

/**
 * main - Entry point of the shell program
 * @argc: Number of command line arguments
 * @argv: Array of command line arguments
 * Return: 0 on success, -1 on failure
 */
int main(int argc __attribute__((unused)), char *argv[] __attribute__((unused)))
{
	interactive_mode();
	return (0);
}

