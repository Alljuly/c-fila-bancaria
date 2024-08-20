#include "menu.h"

#include "../structs/client/client.h"
#include "../structs/clientQueue/clientQueue.h"
#include "../utils/colors.h"
#include <stdio.h>
#include <stdlib.h>

void printMenu() {
  printf("%s+-------------------------------+\n",
         colors[colorIndex++ % numColors]);
  printf("%s|            Menu               |\n",
         colors[colorIndex++ % numColors]);
  printf("%s+-------------------------------+\n",
         colors[colorIndex++ % numColors]);
  printf("%s| 1. Adicionar cliente           |\n",
         colors[colorIndex++ % numColors]);
  printf("%s| 2. Atender Cliente             |\n",
         colors[colorIndex++ % numColors]);
  printf("%s| 3. Exibir relatorio atual      |\n",
         colors[colorIndex++ % numColors]);
  printf("%s+-------------------------------+\n",
         colors[colorIndex++ % numColors]);
}

void addClientToQueue(ClientQueue *queue) {
  int id;
  printf("%s| Digite o ID do cliente:      |\n",
         colors[colorIndex++ % numColors]);
  scanf("%d", &id);

  Client *newClient = createClient(id);
  if (newClient == NULL) {
    printf("%s| Erro ao criar o cliente. |\n",
           colors[colorIndex++ % numColors]);
    return;
  }

  enqueueClient(queue, newClient);
  printf("%s| Cliente adicionado à fila com sucesso. |\n",
         colors[colorIndex++ % numColors]);
}

void viewClientInQueue(Client *current) {

  if (current != NULL) {

    char entryTimeStr[26];
    char exitTimeStr[26];
    strftime(entryTimeStr, sizeof(entryTimeStr), "%Y-%m-%d %H:%M:%S",
             localtime(&current->entryTime));
    strftime(exitTimeStr, sizeof(exitTimeStr), "%Y-%m-%d %H:%M:%S",
             localtime(&current->exitTime));

    double diff = difftime(current->exitTime, current->exitTime);

    printf("%s+--------------------------------------+\n",
           colors[colorIndex++ % numColors]);
    printf("%s| Cliente ID: %d                       |\n",
           colors[colorIndex++ % numColors], current->id);
    printf("%s| Entrada: %s                          |\n",
           colors[colorIndex++ % numColors], entryTimeStr);
    printf("%s| Tempo na Fila: %.2f s                |\n",
           colors[colorIndex++ % numColors], diff);
    printf("%s+--------------------------------------+\n",
           colors[colorIndex++ % numColors]);
  }
}
void removeClientFromQueue(ClientQueue *queue) {
  Client *removedClient = dequeueClient(queue);
  if (removedClient != NULL) {
    free(removedClient); // Libere a memória do cliente removido
  }
}

void viewClientTransactions(Client *queue) {}

void attendClient(ClientQueue *queueClients, ClientQueue *attemptedClients) {
  if (isQueueEmpty(queueClients)) {
    printf("Nenhum cliente para atender.\n");
    return;
  }

  Client *clientToAttend = dequeueClient(queueClients);

  if (clientToAttend != NULL) {
    printf("Atendendo cliente %d...\n", clientToAttend->id);

    Transaction *currentTransaction = clientToAttend->transactionList;
    int totalProcessingTime = 0;

//não entendi
    while (currentTransaction != NULL) {
      totalProcessingTime += currentTransaction->seconds;
      currentTransaction = currentTransaction->prox;
    }

    clientToAttend->exitTime = time(NULL);
    enqueueClient(attemptedClients, clientToAttend);
    printf("Cliente %d atendido.\n", clientToAttend->id);

    free(clientToAttend);
  }
}

void printRelatory(ClientQueue *queue) {
  while (queue->front != NULL) {
    Client *current = queue->front;
    viewClientInQueue(current);
    viewClientTransactions(current);

    queue->front = current->next;
  }

  if (queue == NULL) {
    printf("%s+--------------------------------------+\n",
           colors[colorIndex++ % numColors]);
    printf("%s|              FIM DA FILA             |\n",
           colors[colorIndex++ % numColors]);
    printf("%s+--------------------------------------+\n",
           colors[colorIndex++ % numColors]);
    return;
  }
}
