#include <stdio.h>
#include <stdlib.h>

#include "transaction.h"

Transaction *createNode(int cod, int s) {
  Transaction *newTransaction = (Transaction *)malloc(sizeof(Transaction));
  newTransaction->cod = cod;
  newTransaction->seconds = s;
  newTransaction->prox = NULL;
  return newTransaction;
};

void addTransaction(Transaction *newTransaction, Transaction **queue) {
  if (*queue == NULL) {
    *queue = newTransaction;
  } else {
    Transaction *aux = *queue;
    while (aux->prox != NULL) {
      aux = aux->prox;
    }
    aux->prox = newTransaction;
  }
};

void pop(Transaction **queue) {
  if (queue == NULL) {
    printf("Nenhuma transacao encontrada");
  }
  Transaction *aux = *queue;
  *queue = (*queue)->prox;
  free(aux);
  return;
};

void getAll(Transaction *queue) {

  printf("+-------------------+---------------+\n");
  printf("| Tipo de Transação |    Duração    |\n");
  printf("+-------------------+---------------+\n");
  while (queue != NULL) {
    printf("| %-17d | %-13d |\n", queue->cod, queue->seconds);
    printf("+-------------------+---------------+\n");
    queue = queue->prox;
  }
}

int main() {
  Transaction *x = NULL;

  getAll(x);

  Transaction *x1 = createNode(1, 5);
  getAll(x);
  addTransaction(x1, &x);
  getAll(x);
  Transaction *x2 = createNode(2, 10);
  addTransaction(x2, &x);
  getAll(x);

  return 0;
}