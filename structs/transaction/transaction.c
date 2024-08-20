#include "transaction.h"
#include <stdio.h>
#include <stdlib.h>

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

  printf("+-------------------+---------------+\n");
  printf("|       TIPO        +      TEMPO    |\n");
  printf("+-------------------+---------------+\n");
  while (queue != NULL) {
    printf("| %-17d | %-13d |\n", queue->cod, queue->seconds);
    printf("+-------------------+---------------+\n");
    queue = queue->prox;
  }
};

/* Testar da funções 
Remova os comentarios e execute
gcc-9 ./transaction.c -o ./main
./main
int main(){
  Transaction *t = createTransaction(1,50);
  Transaction *t1 = createTransaction(2,100);


  getAll(t);

  add(&t, t1);

  getAll(t);

  pop(&t);

  getAll(t);

  return 0;

}
*/