#ifndef SIMPLEACTOR_ACTOR_H
#define SIMPLEACTOR_ACTOR_H

typedef struct actor actor;
typedef struct message message;
typedef struct message_handler_t message_handler_t;

actor * create_actor(message_handler_t handler);
int send_message_to(actor * recipient, message msg);
