#include "client.h"
#include "../transaction/transaction.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

Client *createClient(int id) {
  Client *newClient = (Client *)malloc(sizeof(Client));
  newClient->id = id;
  newClient->transactionList = NULL;
  newClient->entryTime = time(NULL);
  newClient->exitTime = 0;
  newClient->next = NULL;
  return newClient;
}

void addTransactionToClient(Client *client, Transaction *transaction) {
  if (client->transactionList == NULL) {
    client->transactionList = transaction;
  } else {
    Transaction *current = client->transactionList;
    while (current->prox != NULL) {
      current = current->prox;
    }
    current->prox = transaction;
  }
}

void printClientTransactions(Client *client) {
  const char *colors[] = {
      "\033[1;31m", // Vermelho
      "\033[1;34m", // Azul
      "\033[1;35m", // Magenta
      "\033[1;36m", // Ciano
  };
  int numColors = sizeof(colors) / sizeof(colors[0]);
  int colorIndex = 0;
  if (client->transactionList == NULL) {

    printf("%s+----------------------------------+\n",
           colors[colorIndex++ % numColors]);
    printf("%s| Nenhuma transação encontrada para o cliente |\n",
           colors[colorIndex++ % numColors]);
    printf("%s+----------------------------------+\n",
           colors[colorIndex++ % numColors]);
    printf(" %d.\n", client->id);
    return;
  }
  printf("%s+----------------------------------+\n",
         colors[colorIndex++ % numColors]);
  printf("%s|     Transacoes para o cliente %d  |\n",
         colors[colorIndex++ % numColors], client->id);
  printf("%s+----------------------------------+\n",
         colors[colorIndex++ % numColors]);
  getAll(client->transactionList); // Função para listar transações
}
