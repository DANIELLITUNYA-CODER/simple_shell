#ifndef GETENV_H
#define GETENV_H

char **list_to_strings(struct Node *head);
int starts_with(const char *str, const char *prefix);
void delete_node_at_index(struct Node **head, int index);
size_t _strlen(const char *str);
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, const char *src);
void _strcat(char *dest, const char *src);
void add_node_end(struct Node **head, const char *data);

#endif /* GETENV_H */

