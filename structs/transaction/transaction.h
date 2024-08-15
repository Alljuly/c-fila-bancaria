#ifndef TRANSACTION_H
#define TRANSACTION_H

//fila ?

struct transaction {
    int cod;
    int s;
    //filas apontam para o primeiro elemento e o ultimo
};

typedef struct transaction Transaction;

Transaction* createTr(int cod, int s);

void add(Transaction tr, Transaction *queue);

void pop(Transaction *queue);

void getAll(Transaction *queue);

#endif

// link util https://gabrielbueno072.github.io/rea-aed/aula_pilha_fila.html