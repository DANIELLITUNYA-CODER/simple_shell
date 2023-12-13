#ifndef LIST_H
#define LIST_H

struct Node {
    char *data;
    struct Node *next;
};

void print_list(struct Node *head);
int node_starts_with(struct Node *node, const char *prefix);
int get_node_index(struct Node *head, const char *data);
void delete_node_at_index(struct Node **head, int index);
void add_node_end(struct Node **head, const char *data);

#endif /* LIST_H */

