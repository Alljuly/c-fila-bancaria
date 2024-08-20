#ifndef TRANSACTION_H
#define TRANSACTION_H

typedef struct transaction {
  int cod;
  int seconds;
  struct transaction *prox;
} Transaction;

Transaction *createTransaction(int cod, int seconds);

void add(Transaction **queue, Transaction *newTransaction);

void pop(Transaction **queue);

void getAll(Transaction *queue);

#endif // TRANSACTION_H
