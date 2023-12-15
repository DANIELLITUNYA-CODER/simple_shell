#include "shell.h"

int handle_builtin(char *command)
{
	if (strcmp(command, "exit") == 0)
	{
		exit_shell();
		return 0;
	}
	else if (strcmp(command, "printenv") == 0)
	{
		print_environment();
		return 0;
	}
	else
	{
		fprintf(stderr, "Error: Unknown built-in command: %s\n", command);
		return -1;
	}
}
