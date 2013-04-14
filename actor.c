#include "actor.h"
#include "queue.h"
#include "SimCList/simclist.h"
#include <stdlib.h>
#include <unistd.h>

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

int msgtypeseek(messagetype_handler * hnd, int * indicator){
    if(hnd->handled_message = *indicator)
        return 1;
    else
        return 0;
}
            

//TODO: error checking
message_handler * new_message_handler(){
    message_handler * ret = malloc(sizeof(message_handler));
    list_init(&(ret->handlers));
    list_attributes_seeker(&(ret->handlers), &msgtypeseek)
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

int actorrun(message_handler * handler, threadsafe_queue * queue){
    void * persistent_data = NULL;
    while(1){
        message * msg = threadsafe_deq(queue);
        if(msg == NULL){
            usleep(1000); //TODO: set this up with condition variable
        } else {
            handler * hnd = list_seek(&(handler->handlers), &(msg->msgtype));
            (hnd->handling_function)(msg->data, &persistent_data);
        }
    }
    return 0;
}

actor * create_actor(message_handler * handler){
    actor * ret = malloc(sizeof(actor));
    ret->msgq = new_threadsafe_queue();
    //TODO: pthread here
}
