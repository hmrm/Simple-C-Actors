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
    list_t handlers;
    int (*default_handler)(void *);
};

typedef struct actor actor;
typedef struct message_handler message_handler;

//TODO: error checking
message_handler * new_message_handler(){
    message_handler * ret = malloc(sizeof(message_handler));
    list_init(&(ret->handlers));
    ret->default_handler = NULL; //TODOL perhaps we want to make a default handler?
    return ret;
}

//TODO: error checking
int register_handler(message_handler *handler, int msgtype, int (*func)(void * data, void ** persistent_data)){
    if(msgtype != 0){
        messagetype_handler * nhandler = malloc(sizeof(messagetype_handler));
        nhandler->handled_message = msgtype;
        nhandler->handling_function = func;
        list_append(&(handler->handlers), nhandler);
    } else {
        handler->default_handler = func;
    }
    return 0;
}

