#include "menuClient.h"

#include "../../structs/client/client.h"
#include "../../structs/clientQueue/clientQueue.h"
#include "../../structs/transaction/transaction.h"
#include "../transaction/menuTransaction.h"

#include <stdio.h>
#include <stdlib.h>

void printMenu()
{
  printf("\n+--------------------------------------+\n");
  printf("|            Menu                      |\n");
  printf("+--------------------------------------+\n");
  printf("| 1. Adicionar cliente                 |\n");
  printf("| 2. Atender clientes                  |\n");
  printf("| 3. Exibir relatorio da fila atual    |\n");
  printf("| 4. Exibir relatorio geral            |\n");
  printf("+--------------------------------------+\n\n");
}

const char *getTransactionName(int cod)
{
  switch (cod)
  {
  case 1:
    return "Saque";
  case 2:
    return "Depósito";
  case 3:
    return "Pagamento";
  case 4:
    return "Transferência";
  default:
    return "Desconhecido";
  }
}

void addClientToQueue(ClientQueue *queue)
{
  int id;
  system("clear");
  printf("ID do cliente: ");
  scanf("%d", &id);

  Client *newClient = createClient(id);
  if (newClient == NULL)
  {
    printf("Erro ao criar o cliente.\n");
    return;
  }

  newClient->transactionList = addTransactionsToClient();

  enqueueClient(queue, newClient);
  printf("-> Cliente adicionado a fila com sucesso. \n");
}

Transaction *addTransactionsToClient()
{
  char aux = 's';
  Transaction *transaction = NULL;
  while (aux == 's')
  {
    printf("\nAdicionar transacao?\n(s/n): ");
    scanf(" %c", &aux);
    system("clear");

    if (aux == 's')
    {
      int choice = 0;
      menuTransaction();
      scanf("%d", &choice);
      addTransactionHandle(choice, &transaction);
    }
    else if (aux != 'n')
    {
      printf("\nOpcao invalida\n\n");
      aux = 's';
    }
  }
  return transaction;
}

void viewClientInQueue(Client *current)
{
  if (current != NULL)
  {
    char entryTimeStr[26];
    char exitTimeStr[26];
    strftime(entryTimeStr, sizeof(entryTimeStr), "%Y-%m-%d %H:%M:%S",
             localtime(&current->entryTime));

    if (!current->exitTime)
    {
      current->exitTime = time(NULL);
    }
    strftime(exitTimeStr, sizeof(exitTimeStr), "%Y-%m-%d %H:%M:%S", localtime(&current->exitTime));
    double diff = difftime(current->exitTime, current->entryTime);

    printf("+--------------------------------------+\n");
    printf("| Cliente ID: %d%-22s |\n", current->id, current->priority ? " (prioridade)" : "");
    printf("| Entrada: %s         |\n", entryTimeStr);
    printf("| Tempo na Fila: %.lfs                    |\n", diff);
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

  printf("Atendendo cliente %d%s ...\n", clientToAttend->id, clientToAttend->priority ? " (prioridade)" : "");

  int totalProcessingTime = 0;
  Transaction *currentTransactions = clientToAttend->transactionList;

  while (currentTransactions)
  {
    totalProcessingTime += currentTransactions->seconds;
    // Adicionar sleep para simular o tempo de atendimento
    printf("..... Em atendimento a %ds (%s)......\n", totalProcessingTime, getTransactionName(currentTransactions->cod));
    currentTransactions = currentTransactions->prox;
  }

  clientToAttend->exitTime = time(NULL);

  enqueueAttemptClient(attemptedClients, clientToAttend);
  printf("Cliente %d atendido.\n", clientToAttend->id);
  if (queueClients->front == NULL)
  {
    return;
  }
  attendClient(queueClients, attemptedClients);
}

// Mostra o relátorio de uma fila de clientes
void printRelatory(ClientQueue *queue)
{
  if (!isQueueEmpty(queue))
  {
    int count = 0;
    Client *current = queue->front;

    while (current != NULL)
    {
      viewClientInQueue(current);
      viewClientTransactions(current);
      count++;
      current = current->next;
    }

    printf("\n\n+--------------------------------------+\n");
    printf("|              FIM DA FILA             |\n");
    printf("+--------------------------------------+\n");
    printf("|        Contagem de clientes: %d       |\n", count);
    printf("+--------------------------------------+\n");
    return;
  }
}

/* Teste das funções
execute
gcc ../main.c ./menu.c ./menuTransaction.c ../structs/client/client.c
../structs/transaction/transaction.c ../structs/clientQueue/clientQueue.c -o
./main
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