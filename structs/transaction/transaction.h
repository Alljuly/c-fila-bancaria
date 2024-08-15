#ifndef TRANSACTION_H
#define TRANSACTION_H

//Lista encadeada

typedef struct transaction {
    int cod;
    int seconds;
    struct transaction *prox;
} Transaction;

Transaction* createTransaction(int cod, int seconds);

void add(Transaction **newTransaction, Transaction *queue);

void pop(Transaction **queue);

void getAll(Transaction *queue);

#endif

