#include <stdio.h>
#include <stdlib.h>

#include "../../utils/colors.h"
#include "../client/client.h"
#include "clientQueue.h"

// Criação de uma nova fila de clientes
ClientQueue *createQueue() {
  ClientQueue *queue = (ClientQueue *)malloc(sizeof(ClientQueue));
  if (queue != NULL) {
    queue->front = NULL;
    queue->rear = NULL;
  }
  return queue;
}

// Adicionar cliente à fila
void enqueueClient(ClientQueue *queue, Client *newClient) {
  if (queue->rear == NULL) {
    queue->front = newClient;
    queue->rear = newClient;
  } else {
    queue->rear->next = newClient;
    queue->rear = newClient;
  }
  newClient->next = NULL;
}

// Remover cliente da fila
Client *dequeueClient(ClientQueue *queue) {
  if (isQueueEmpty(queue)) {
    return NULL;
  }

  Client *clientToDequeue = queue->front;
  queue->front = queue->front->next;

  if (queue->front == NULL) {
    queue->rear = NULL;
  }

  return clientToDequeue;
}

// Verificar se a fila está vazia
int isQueueEmpty(ClientQueue *queue) {
  if (queue->front == NULL) {
    printf("+-------------------+---------------+\n");
    printf("|          A fila está vazia        |\n");
    printf("+-------------------+---------------+\n");
    return 1;
  }
  return 0;
}

// Imprimir todos os clientes na fila
void printQueue(ClientQueue *queue) {

  if (isQueueEmpty(queue)) {
    Client *current = queue->front;
    while (current != NULL) {
      printf("%s+-------------------+---------------+\n",
             colors[colorIndex++ % numColors]);
      printf("%s|            Cliente ID: %d          |\n",
             colors[colorIndex++ % numColors], current->id);
      printf("%s+-------------------+---------------+\n",
             colors[colorIndex++ % numColors]);
      current = current->next;
    }
  }
}

int main() {
  Client *c = createClient(1);

  printClientTransactions(c);
  return 0;
}