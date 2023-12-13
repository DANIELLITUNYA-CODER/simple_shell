#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
#include <signal.h>

#define MAX_COMMAND_LENGTH 1024
#define PROMPT "#cisfun$ "

void display_prompt() {
    printf("%s", PROMPT);
}

void execute_command(char *command) {
    pid_t pid = fork();

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
        int status;
        waitpid(pid, &status, 0);
    }
}

int main() {
    char command[MAX_COMMAND_LENGTH];
    size_t len;

    signal(SIGINT, SIG_IGN);

    while (1) {
        display_prompt();

        if (fgets(command, sizeof(command), stdin) == NULL) {
            printf("\n");
            break;
        }

        
        len = strlen(command);
        if (len > 0 && command[len - 1] == '\n') {
            command[len - 1] = '\0';
        }

        
        if (strlen(command) > 0) {
            execute_command(command);
        }
    }

    return 0;
}

