#include "actor.h"
#include "queue.h"
#include "SimCList/simclist.h"
#include <stdlib.h>

struct actor {
    threadsafe_queue * msgq;
};

typedef struct {
    int handled_message;
    int (*handling_function)(void *);
} messagetype_handler;

struct message_handler {
    list_t * handlers;
};

