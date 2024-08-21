#include "menu.h"

#include "../structs/client/client.h"
#include "../structs/clientQueue/clientQueue.h"
#include "../structs/transaction/transaction.h"
#include "./menuTransaction.h"

#include <stdio.h>
#include <stdlib.h>

void printMenu()
{
  printf("+-------------------------------+\n");
  printf("|            Menu               |\n");
  printf("+-------------------------------+\n");
  printf("| 1. Adicionar cliente          |\n");
  printf("| 2. Atender cliente            |\n");
  printf("| 3. Exibir relatorio da fila   |\n");
  printf("| 4. Exibir relatorio geral     |\n");
  printf("+-------------------------------+\n");
}

void addClientToQueue(ClientQueue *queue)
{
  int id;
  printf("Digite o ID do cliente: ");
  scanf("%d", &id);

  Client *newClient = createClient(id);
  if (newClient == NULL)
  {
    printf("Erro ao criar o cliente.\n");
    return;
  }

  newClient->transactionList = addTransactionsToClient();

  enqueueClient(queue, newClient);
  printf("Cliente adicionado a fila com sucesso. \n");
}

Transaction *addTransactionsToClient()
{
  int aux = 1;
  Transaction *t = NULL;
  while (aux)
  {
    printf("\nAdicionar transacao?\n\n1 - SIM 0 - NAO\n");
    scanf("%d", &aux);
    if (aux)
    {
      int choice = 0;
      menuTransaction();
      scanf("%d", &choice);
      addTransactionHandle(choice, &t);
    }
  }
  return t;
}

void viewClientInQueue(Client *current)
{

  if (current != NULL)
  {

    char entryTimeStr[26];
    char exitTimeStr[26];
    strftime(entryTimeStr, sizeof(entryTimeStr), "%Y-%m-%d %H:%M:%S",
             localtime(&current->entryTime));

    if (current->exitTime)
    {
      strftime(exitTimeStr, sizeof(exitTimeStr), "%Y-%m-%d %H:%M:%S",
               localtime(&current->exitTime));
      double diff = difftime(current->exitTime, current->entryTime);
    }
    else
    {
      current->exitTime = time(NULL);
      strftime(exitTimeStr, sizeof(exitTimeStr), "%Y-%m-%d %H:%M:%S",
               localtime(&current->exitTime));
    }
    double diff = difftime(current->exitTime, current->entryTime);

    printf("+--------------------------------------+\n");
    printf("| Cliente ID: %d                       |\n", current->id);
    printf("| Entrada: %s       |\n", entryTimeStr);
    printf("| Tempo na Fila: %.lfs                 |\n", diff);
    printf("+--------------------------------------+\n");
  }
}

void removeClientFromQueue(ClientQueue *queue)
{
  Client *removedClient = dequeueClient(queue);
  if (removedClient != NULL)
  {
    free(removedClient); // Libere a memória do cliente removido
  }
}

void viewClientTransactions(Client *current)
{
  Transaction *currentTransactions = current->transactionList;

  if (currentTransactions != NULL)
  {
    getAll(currentTransactions);
  }
}

void attendClient(ClientQueue *queueClients, ClientQueue *attemptedClients)
{
  Client *clientToAttend = dequeueClient(queueClients);

  if (clientToAttend == NULL)
  {
    return;
  }

  printf("Atendendo cliente %d ...\n", clientToAttend->id);

  int totalProcessingTime = 0;
  Transaction *currentTransactions = clientToAttend->transactionList;

  while (currentTransactions)
  {
    totalProcessingTime += currentTransactions->seconds;
    // adicionar sleep para os s do atendimento
    printf("..... Em atendimento a %ds......\n", totalProcessingTime);
    currentTransactions = currentTransactions->prox;
  }

  clientToAttend->exitTime = time(NULL);

  enqueueClient(attemptedClients, clientToAttend);
  printf("Cliente %d atendido.\n", clientToAttend->id);
  attendClient(queueClients, attemptedClients);
}

// imprime o relátorio de uma fila de clientes
void printRelatory(ClientQueue *queue)
{

  if (!isQueueEmpty(queue))
  {

    int count = 0;

    while (queue->front)
    {
      Client *current = queue->front;
      viewClientInQueue(current);
      viewClientTransactions(current);
      count++;
      queue->front = current->next;
    }
    printf("+--------------------------------------+\n");
    printf("|        Contagem de clientes: %d       |\n", count);
    printf("+--------------------------------------+\n");
  }
  printf("+--------------------------------------+\n");
  printf("|              FIM DA FILA             |\n");
  printf("+--------------------------------------+\n");
  return;
}

/* Teste das funções
execute
gcc ../main.c ./menu.c ./handles/handleTransaction.c ../structs/client/client.c ../structs/transaction/transaction.c ../structs/clientQueue/clientQueue.c -o ./main
./main

int main() {
  ClientQueue *q = createQueue();
  ClientQueue *at = createQueue();

  printMenu();
  addClientToQueue(q);
  attendClient(q, at);
  printRelatory(q);
  printRelatory(at);

  return 0;
}
*/