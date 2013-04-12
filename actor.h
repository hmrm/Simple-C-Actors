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

//registers func as the handler for messages of type msgtype. msgtype = 0 will define a default handler.
int register_handler(message_handler *message_handler, int msgtype, int (*func)(void *));

actor * create_actor(message_handler ** handler);
int send_message_to(actor * recipient, message msg);

#endif
