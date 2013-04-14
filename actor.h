#ifndef SIMPLEACTOR_ACTOR_H
#define SIMPLEACTOR_ACTOR_H

typedef struct actor actor;
typedef struct message_handler message_handler;

//message of type 0 will be handled with default behavior
typedef struct {
    int msgtype;
    void * data;
} message;

message_handler * new_message_handler();

//registers func as the handler for messages of type msgtype. msgtype = 0 will define a default handler. Persistent_data is a pointer to a null initialized void * that will always be called on any handler.
//Behavior if you register for the same msgtype twice is unspecified.
int register_handler(message_handler *message, int msgtype, int (*func)(void * data, void ** persistent_data));

actor * create_actor(message_handler * handler);
int send_message_to(actor * recipient, message msg);

void free_handler(message_handler * handler);

#endif
