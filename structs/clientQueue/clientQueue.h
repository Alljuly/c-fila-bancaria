#ifndef CLIENT_QUEUE_H
#define CLIENT_QUEUE_H

#include "../client/client.h"
typedef struct clientQueue {
  Client *front; 
  Client *rear;  
} ClientQueue;

ClientQueue *createQueue();
int isQueueEmpty(ClientQueue *queue);
void enqueueClient(ClientQueue *queue, Client *newClient);
void enqueueAttemptClient(ClientQueue *queue, Client *newClient);
Client *dequeueClient(ClientQueue *queue);
void printQueue(ClientQueue *queue);

#endif
