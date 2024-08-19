#ifndef CLIENT_QUEUE_H
#define CLIENT_QUEUE_H

#include "../client/client.h"
typedef struct clientQueue
{
    Client *front; // Aponta para o primeiro cliente
    Client  *rear;  // Aponta para o último cliente
} ClientQueue;



ClientQueue *createQueue();
int isQueueEmpty(ClientQueue *queue);
void enqueueClient(ClientQueue *queue, Client *newClient);
Client *dequeueClient(ClientQueue *queue);
void printQueue(ClientQueue *queue);

#endif // CLIENT_QUEUE_H
