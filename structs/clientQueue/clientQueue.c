#include <stdio.h>
#include <stdlib.h>
#include "clientQueue.h"

// Criação de uma nova fila de clientes
ClientQueue *createQueue()
{
    ClientQueue *queue = (ClientQueue *)malloc(sizeof(ClientQueue));
    if (queue != NULL)
    {
        queue->front = NULL;
        queue->rear = NULL;
    }
    return queue;
}

// Adicionar cliente à fila
void enqueueClient(ClientQueue *queue, Client *newClient)
{
    if (queue->rear == NULL)
    {
        queue->front = newClient;
        queue->rear = newClient;
    }
    else
    {
        queue->rear->next = newClient;
        queue->rear = newClient;
    }
    newClient->next = NULL;
}

// Remover cliente da fila
Client *dequeueClient(ClientQueue *queue)
{
    if (isQueueEmpty(queue))
    {
        return NULL;
    }

    Client *clientToDequeue = queue->front;
    queue->front = queue->front->next;

    if (queue->front == NULL)
    {
        queue->rear = NULL;
    }

    return clientToDequeue;
}

// Verificar se a fila está vazia
int isQueueEmpty(ClientQueue *queue)
{
    return queue->front == NULL;
}

// Imprimir todos os clientes na fila
void printQueue(ClientQueue *queue)
{
    if (queue == NULL || isQueueEmpty(queue))
    {
        printf("A fila está vazia.\n");
        return;
    }

    Client *current = queue->front;
    while (current != NULL)
    {
        printf("Cliente ID: %d\n", current->id);
        current = current->next;
    }
}
