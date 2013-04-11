#ifndef HMRM_THREADSAFE_QUEUE_H_
#define HMRM_THREADSAFE_QUEUE_H_

typedef struct threadsafe_queue threadsafe_queue;

threadsafe_queue * new_threadsafe_queue();
int enq(threadsafe_queue * queue, void * data);
void * deq(threadsafe_queue * queue);
void free_threadsafe_queue(threadsafe_queue * queue);
void free_threadsafe_queue_and_data(threadsafe_queue * queue);

#endif

