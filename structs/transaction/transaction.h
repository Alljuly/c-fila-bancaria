#ifndef TRANSACTION_H
#define TRANSACTION_H

//Lista encadeada

typedef struct transaction {
    int cod;
<<<<<<< HEAD
    int s;
    struct transaction *prox;
} Transaction;
=======
    int seconds;
    Transaction *prox;
};

typedef struct transaction Transaction;
>>>>>>> 14dc0d44f13b7e0a2570d2b5489a5255406335fd


Transaction* createTr(int cod, int seconds);

void add(Transaction **newTransaction, Transaction *queue);

void pop(Transaction **queue);

void getAll(Transaction *queue);

#endif

