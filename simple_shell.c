#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

void display_prompt(void) {
    printf("#cisfun$ ");
}

char *read_command(void) {
    char *command = NULL;
    size_t bufsize = 0;

    if (getline(&command, &bufsize, stdin) == -1) {
        free(command);
        return NULL;
    }

    return command;
}

int main(void) {
    char *command;
    size_t len;
    pid_t pid;

    while (1) {
        display_prompt();
        command = read_command();

        if (command == NULL) {
            printf("\n");
            break;
        }

        len = strlen(command);
        if (len > 0 && command[len - 1] == '\n') {
            command[len - 1] = '\0';
        }

        pid = fork();

        if (pid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        }

        if (pid == 0) {
            if (execlp(command, command, (char *)NULL) == -1) {
                perror("execlp");
                exit(EXIT_FAILURE);
            }
        } else {
            wait(NULL);
        }

        free(command);
    }

    return 0;
}

