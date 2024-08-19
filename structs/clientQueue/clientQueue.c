#include <stdio.h>
#include <stdlib.h>
#include "clientQueue.h"
#include "../client/client.h"

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
    int aux = isQueueEmpty(queue);

    if(aux == 0){

        Client *clientToDequeue = queue->front;
        queue->front = queue->front->next;

        if (queue->front == NULL)
        {
            queue->rear = NULL;
        }

        return clientToDequeue;
    }
    
}

// Verificar se a fila está vazia
int isQueueEmpty(ClientQueue *queue)
{
    if (queue->front == NULL)
    {
        printf("+-------------------+---------------+\n");
        printf("|          A fila está vazia        |\n");
        printf("+-------------------+---------------+\n");
        return 1;
    } 
    return 0;
}

// Imprimir todos os clientes na fila
void printQueue(ClientQueue *queue)
{

    int aux = isQueueEmpty(queue);
    if(aux == 0){
        Client *current = queue->front;
        while (current != NULL)
        {   
            printf("+-------------------+---------------+\n");
            printf("|            Cliente ID: %d          |\n", current->id);
            printf("+-------------------+---------------+\n");
            current = current->next;
        }
    }
}
