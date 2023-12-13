#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024

void execute_command(char **args);

int main(void)
{
    char *input = NULL;
    size_t len = 0;
    ssize_t read;

    while (1)
    {
        char *token;
        char *args[MAX_INPUT_SIZE];
        int i = 0;

        printf("($) ");
        if ((read = getline(&input, &len, stdin)) == -1)
        {
            perror("Error reading input");
            exit(EXIT_FAILURE);
        }

        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, "exit") == 0)
        {
            free(input);
            exit(EXIT_SUCCESS);
        }

        token = strtok(input, " ");
        while (token != NULL)
        {
            args[i++] = token;
            token = strtok(NULL, " ");
        }
        args[i] = NULL;

        execute_command(args);
    }

    free(input);
    return 0;
}

void execute_command(char **args)
{
    pid_t pid;
    int status;

    pid = fork();
    if (pid == 0)
    {
        if (execvp(args[0], args) == -1)
        {
            perror("Error");
        }
        exit(EXIT_FAILURE);
    }
    else if (pid < 0)
    {
        perror("Error");
    }
    else
    {
        waitpid(pid, &status, 0);
    }
}

