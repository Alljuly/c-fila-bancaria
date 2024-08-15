#ifndef TRANSACTION_H
#define TRANSACTION_H

//Lista encadeada

struct transaction {
    int cod;
    int s;
    Transaction *prox;
};

typedef struct transaction Transaction;


Transaction* createTr(int cod, int s);

void add(Transaction **newTr, Transaction *queue);

void pop(Transaction **queue);

void getAll(Transaction *queue);

#endif

