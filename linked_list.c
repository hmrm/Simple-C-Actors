#include "linked_list.h"
#include <stdlib.h>

struct listnode {
    void * data;
    struct listnode * prev;
    struct listnode * next;
};

struct linked_list {
    struct listnode * head;
    struct listnode * tail;
};

typedef struct linked_list linked_list;
typedef struct listnode listnode;

linked_list * new_list(){
    return calloc(1, sizeof(linked_list));
}

void free_list(linked_list * list){
    if(head == NULL){
        free(list);
        return;
    }

    listnode * current = list->head;
    while(current != NULL){
        listnode * next = current->next;
        free(current);
        current = next;
    }
}

void free_list_and_data(linked_list * list){
    if(head != NULL){
        listnode * current = list->head;
        while(current != NULL){
            if(current->data != NULL){
                free(current->data);
                current->data = NULL;
            }
            current = current->next;
        }
    }
    free_list(list);
}

int list_append(linked_list * list, void * data, int tail){
    listnode * new_node = calloc(1, sizeof(listnode));
    new_node->data = data;
    
    if(list_head(list) == NULL){
        list->head = new_node;
        list->tail = new_node;
        return;
    }

    if(tail){
        listnode * current = list_tail(list);
        current->next = new_node;
        new-node->prev = current;
        list->tail = new_node;
    } else {
        listnode * current = list_head(list);
        current->prev = new_node;
        new_node->next = current;
        list->head = new_node;
    }
}

listnode * list_head(linked_list * list){
    return list->head;
}

listnode * list_tail(linked_list * list){
    return list->tail;
}

listnode * list_next(listnode * node){
    return node->next;
}

listnode * list_prev(listnode * node){
    return node->prev;
}

void * list_node_data(listnode * node){
    return node->data;
}

linked_list * list_map(linked_list * list, void * (*func)(void *), int keep_result){
    linked_list * ret;
    if(keep_result)
        ret = new_list();
    else
        ret = NULL;
    
    listnode * current = head(list);
    while(current != NULL){
        void * res = func(list_node_data(current));
        if(keep_result)
            list_append(list, res, 1);
        current = list_next(current);
    }

    return ret;
}
