#include "transaction.h"
#include "../../utils/colors.h"
#include <stdio.h>
#include <stdlib.h>

extern const char *colors[];
extern int numColors;
extern int colorIndex;
Transaction *createTransaction(int cod, int seconds) {
  Transaction *newTransaction = (Transaction *)malloc(sizeof(Transaction));
  newTransaction->cod = cod;
  newTransaction->seconds = seconds;
  newTransaction->prox = NULL;
  return newTransaction;
}

// adiciona uma transação no final da lista
void add(Transaction **queue, Transaction *newTransaction) {
  if (*queue == NULL) {
    *queue = newTransaction;
  } else {
    Transaction *aux = *queue;
    while (aux->prox != NULL) {
      aux = aux->prox;
    }
    aux->prox = newTransaction;
  }
}

// remove a primeira transação
void pop(Transaction **queue) {
  if (*queue == NULL) {
    printf("Nenhuma transação encontrada.\n");
    return;
  }
  Transaction *aux = *queue;
  *queue = (*queue)->prox;
  free(aux);
  return;
};

// imprime todas as transações caso tenha, se não informa que a lista está vazia
void getAll(Transaction *queue) {

  printf("%s+-------------------+---------------+\n",
         colors[colorIndex++ % numColors]);
  printf("%s| Tipo de Transacao |    Duracao    |\n",
         colors[colorIndex++ % numColors]);
  printf("%s+-------------------+---------------+\n",
         colors[colorIndex++ % numColors]);
  while (queue != NULL) {
    printf("| %-17d | %-13d |\n", queue->cod, queue->seconds);
    printf("%s+-------------------+---------------+\n",
           colors[colorIndex++ % numColors]);
    queue = queue->prox;
  }
};

int main() {
  Transaction *c = createTransaction(1, 250);

  getAll(c);
  return 0;
}