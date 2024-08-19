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

// adiciona uma transação no final da lista
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

// remove a primeira transação
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
}

// imprime todas as transações caso tenha, se não informa que a lista está vazia
void getAll(Transaction *queue)
{
   const char *colors[] = {
        "\033[1;31m", // Vermelho
        "\033[1;34m", // Azul
        "\033[1;35m", // Magenta
        "\033[1;36m", // Ciano
    };
    int numColors = sizeof(colors) / sizeof(colors[0]);
    int colorIndex = 0;
  printf("%s+-------------------+---------------+\n",  colors[colorIndex++ % numColors]);
  printf("%s| Tipo de Transação |    Duração    |\n",  colors[colorIndex++ % numColors]);
  printf("%s+-------------------+---------------+\n",  colors[colorIndex++ % numColors]);
  while (queue != NULL)
  {
    printf("| %-17d | %-13d |\n", queue->cod, queue->seconds);
    printf("%s+-------------------+---------------+\n", colors[colorIndex++ % numColors]);
    queue = queue->prox;
  }
}