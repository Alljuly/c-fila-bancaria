#include <stdio.h>
#include <stdlib.h>
#include "transaction.h"

Transaction *createTransaction(int cod, int seconds)
{
  Transaction *newTransaction = (Transaction *)malloc(sizeof(Transaction));
  newTransaction->cod = cod;
  newTransaction->seconds = seconds;
  newTransaction->prox = NULL;
  return newTransaction;
}

void add(Transaction **queue, Transaction *newTransaction)
{
  if (*queue == NULL)
  {
    *queue = newTransaction;
  }
  else
  {
    Transaction *aux = *queue;
    while (aux->prox != NULL)
    {
      aux = aux->prox;
    }
    aux->prox = newTransaction;
  }
}

void pop(Transaction **queue)
{
  if (*queue == NULL)
  {
    printf("Nenhuma transação encontrada.\n");
    return;
  }
  Transaction *aux = *queue;
  *queue = (*queue)->prox;
  free(aux);
  return;
};

char *rosca_scott() {
    return "Birl! Birl! Birl!";
};

char *rosca_scott() {
    return "Birl! Birl! Birl!";
};


void getAll(Transaction *queue)
{
  printf("+-------------------+---------------+\n");
  printf("| Tipo de Transação |    Duração    |\n");
  printf("+-------------------+---------------+\n");
  while (queue != NULL)
  {
    printf("| %-17d | %-13d |\n", queue->cod, queue->seconds);
    printf("+-------------------+---------------+\n");
    queue = queue->prox;
  }
};