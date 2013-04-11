#ifndef SIMPLEACTOR_ACTOR_H
#define SIMPLEACTOR_ACTOR_H

typedef struct actor actor;
typedef struct message_handler message_handler;

typedef struct {
    int msgtype;
    void * data;
} message;

message_handler * new_message_handler();

actor * create_actor(message_handler ** handler); //consumes the message handler
int send_message_to(actor * recipient, message msg);
int kill_actor(actor * target);

#endif
