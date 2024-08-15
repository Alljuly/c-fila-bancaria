#ifndef TRANSACTION_H
#define TRANSACTION_H

//Lista encadeada

typedef struct transaction {
    int cod;
    int s;
    struct transaction *prox;
} Transaction;


Transaction* createTr(int cod, int s);

void add(Transaction **newTr, Transaction *queue);

void pop(Transaction **queue);

void getAll(Transaction *queue);

#endif

