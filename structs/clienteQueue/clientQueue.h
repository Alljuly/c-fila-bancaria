#ifndef CLIENT_QUEUE_H
#define CLIENT_QUEUE_H

#include "client.h"

typedef struct clientQueue {
    Client *front; // Aponta para primeiro cliente 
    Client *rear;  // Aponta para ultimo cliente 
} ClientQueue;


ClientQueue* createQueue();                   // Cria uma fila de clientes vazia

void enqueueClient(ClientQueue *queue, Client *newClient); // Adiciona um cliente no final da fila

Client* dequeueClient(ClientQueue *queue);    // Remove o cliente do início da fila

int isQueueEmpty(ClientQueue *queue);         // Verifica se a fila está vazia

void printQueue(ClientQueue *queue);    // Exibe todos os clientes na fila

#endif
