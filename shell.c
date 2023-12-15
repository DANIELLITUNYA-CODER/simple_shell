#include "shell.h"

int main(void)
{
    char *line;

    while (1)
    {
        line = read_line();
        process_line(line);
        free(line);
    }

    return (0);
}
