#include "queue.h"
#include "SimCList/simclist.h"
#include <stdlib.h>
#include <pthread.h>

struct threadsafe_queue {
    pthread_mutex_t lock;
    list_t data;
};

typedef struct threadsafe_queue threadsafe_queue;

threadsafe_queue * new_threadsafe_queue(){
    threadsafe_queue * ret = malloc(sizeof(threadsafe_queue));
    if(!ret)
        return NULL;

    if(pthread_mutex_init(&(ret->lock), NULL) != 0){
        free(ret);
        return NULL;
    }
    
    if(list_init(&(ret->data)) != 0){
        //TODO: free stuff
        return NULL;
    }
    
    return ret;
}

int threadsafe_enq(threadsafe_queue * queue, void * data){
    pthread_mutex_lock(&(queue->lock));
    int ret = list_append(&(queue->data), data);
    pthread_mutex_unlock(&(queue->lock));
    return ret;
}
    
void * threadsafe_deq(threadsafe_queue * queue){
    pthread_mutex_lock(&(queue->lock));
    void * ret = list_fetch(&(queue->data));
    pthread_mutex_unlock(&(queue->lock));
    return ret;
}

void free_threadsafe_queue(threadsafe_queue * queue){
    pthread_mutex_destroy(&(queue->lock));
    list_destroy(&(queue->data));
}
