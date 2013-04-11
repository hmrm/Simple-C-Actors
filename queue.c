#include "queue.h"
#include "linked_list.h"
#include <stdlib.h>
#include <pthread.h>

struct threadsafe_queue {
    pthread_mutex_t lock;
    linked_list * data;
};

typedef struct threadsafe_queue threadsafe_queue;

threadsafe_queue * new_threadsafe_queue(){
    threadsafe_queue * ret = malloc(sizeof(threadsafe_queue));
    if(!ret)
        return NULL;

    pthread_mutex_init(&(ret->lock), NULL); //TODO: error check
    ret->data = new_list();
    return ret;
}

int threadsafe_enq(threadsafe_queue * queue, void * data){
    pthread_mutex_lock(&(queue->lock)); //TODO error checking
    list_append(queue->data, data, 0);
    pthread_mutex_unlock(&(queue->lock));
    return 0;
}
    
void * threadsafe_deq(threadsafe_queue * queue){
    pthread_mutex_lock(&(queue->lock));
    void * ret = list_pop(queue->data, 1);
    pthread_mutex_unlock(&(queue->lock));
    return ret;
}

void free_threadsafe_queue(threadsafe_queue * queue){
    pthread_mutex_destroy(&(queue->lock));
    free_list(queue->data);
}

void free_threadsafe_queue_and_data(threadsafe_queue * queue){
    pthread_mutex_destroy(&(queue->lock));
    free_list_and_data(queue->data);
}
