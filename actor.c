#include "actor.h"
#include "queue.h"
#include "linked_list"

struct actor {
    threadsafe_queue * msgq;
};

typedef struct {
    int handled_message;
    int (*handling_function)(void *);
} messagetype_handler;

struct message_handler {
    linked_list * handlers;
};

