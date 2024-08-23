#include "clientQueue.h"
#include "../client/client.h"
#include <stdio.h>
#include <stdlib.h>

// Criação de uma nova fila de clientes (Inicialmente vazia)
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
  
  if (queue->front == NULL)
  {
    queue->front = newClient;
    queue->rear = newClient;
  }
  else if (newClient->priority == 1)
  {
    if (queue->front->priority == 0)
    {
      newClient->next = queue->front;
      queue->front = newClient;
    }
    else
    {
      Client *current = queue->front;
      while (current->next != NULL && current->next->priority == 1)
      {
        current = current->next;
      }
      newClient->next = current->next;
      current->next = newClient;
      if (newClient->next == NULL)
      {
        queue->rear = newClient;
      }
    }
  }
  else
  {
    queue->rear->next = newClient;
    queue->rear = newClient;

  }
}

// Adicionar clientes atendidos à fila
void enqueueAttemptClient(ClientQueue *queue, Client *newClient)
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
  if (queue->front == NULL)
  {
    printf("-> A fila esta vazia\n");
    return 1;
  }
  return 0;
}

// Imprimir todos os clientes na fila
void printQueue(ClientQueue *queue)
{
  if (isQueueEmpty(queue))
  {
    return;
  }
  Client *current = queue->front;
  printf("+-----------------------------------+\n");
  while (current != NULL)
  {
    printf("|            Cliente ID: %d          |\n", current->id);
    printf("+-----------------------------------+\n");
    current = current->next;
  }
}

/*Teste das funções
Remova os comentarios e execute
gcc-9 ./client.c ../transaction/transaction.c -o ./main
./main
int main(){
  Transaction *t = createTransaction(1,50);
  Transaction *t1 = createTransaction(2,100);

  Client *c = createClient(1);
  Client *c1 = createClient(3);

  ClientQueue *queue = createQueue();
  printQueue(queue);

  enqueueClient(queue, c);

  printQueue(queue);

  enqueueClient(queue, c1);

  printQueue(queue);

  dequeueClient(queue);

  printQueue(queue);


  addTransactionToClient(c, t);

  printClientTransactions(c);

  printClientTransactions(c1);



  return 0;

}
*/
