#ifndef SIMPLEACTOR_LINKED_LIST_H_
#define SIMPLEACTOR_LINKED_LIST_H_

typedef struct linked_list linked_list;
typedef struct listnode listnode;

//returns null on error
linked_list * new_list();
void free_list(linked_list * list);
void free_list_and_data(linked_list * list);

//appends to the head of the list unless tail is true
int list_append(linked_list * list, void * data, int tail);
listnode * list_head(linked_list * list);
listnode * list_next(listnode * node);
listnode * list_previous(listnode * node);
listnode * list_tail(linked_list * list);
void * list_node_data(listnode * node);
linked_list * list_map(linked_list * list, void *(*func)(void *), int keep_result);

#endif
