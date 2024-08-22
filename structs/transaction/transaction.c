#include "transaction.h"
#include <stdio.h>
#include <stdlib.h>

// Cria uma transação
Transaction *createTransaction(int cod, int seconds)
{
  Transaction *newTransaction = (Transaction *)malloc(sizeof(Transaction));
  newTransaction->cod = cod;
  newTransaction->seconds = seconds;
  newTransaction->prox = NULL;
  return newTransaction;
}

// Adiciona uma transação ao final da lista
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

// Remove a primeira transação da lista
void pop(Transaction **queue)
{
  if (*queue == NULL)
  {
    printf("Nenhuma transacao encontrada.\n");
    return;
  }
  Transaction *aux = *queue;
  *queue = (*queue)->prox;
  free(aux);
  return;
};

// Mostra todas as transações caso tenha, se não informa que a lista está vazia
void getAll(Transaction *queue)
{
  printf("|        TRANSACOES DO CLIENTE         |\n");
  printf("+--------------------------------------+\n");
  printf("|       TIPO        |       TEMPO(s)   |\n");
  printf("+--------------------------------------+\n");
  while (queue != NULL)
  {
    printf("| %-17d | %-17d|\n", queue->cod, queue->seconds);
    printf("+--------------------------------------+\n");
    queue = queue->prox;
  }
  printf("\n");
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