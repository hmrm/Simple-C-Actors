#ifndef SIMPLEACTOR_LINKED_LIST_H
#define SIMPLEACTOR_LINKED_LIST_H

typedef struct linked_list linked_list;
typedef struct listnode listnode;

linked_list * new_list();
void free_list(linked_list * list);
void free_list_and_data(linked_list * list);

int list_append(linked_list * list, void * data);
listnode * list_head(linked_list * list);
listnode * list_next(listnode * node);
listnode * list_previous(listnode * node);
listnode * list_tail(linked_list * list);
void * node_data(listnode * node);
linked_list * list_foreach(linked_list * list, int (*func)(void *));

#endif
