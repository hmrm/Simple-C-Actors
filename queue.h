#ifndef SIMPLEACTOR_QUEUE_H
#define SIMPLEACTOR_ACTOR_H

typedef struct threadsafe_queue threadsafe_queue;

threadsafe_queue * new_threadsafe_queue();
int enq(threadsafe_queue * queue, void * data);
void * deq(threadsafe_queue * queue);
void free_threadsafe_queue(threadsafe_queue * queue);
void free_threadsafe_queue_and_data(threadsafe_queue * queue);

#endif

