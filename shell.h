#ifndef SHELL_H
#define SHELL_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *read_line(void);
void process_line(char *line);
void print_error(char *msg);
void *custom_realloc(void *ptr, size_t old_size, size_t new_size);
void print_environment(void);
void exit_shell(void);

#endif /* SHELL_H */
