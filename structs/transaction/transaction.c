#include <stdio.h>
#include <stdlib.h>
#include "transaction.h"


Transaction* createNode(int cod, int s){
    Transaction *newTransaction = (Transaction*)malloc(sizeof(Transaction));
    newTransaction->cod = cod;
    newTransaction->seconds = s;

};

//Recebe uma transação e insere no final da lista
void add(Transaction **tr, Transaction *queue);

//Apaga a primeira transação da lista
void pop(Transaction **queue);

void getAll(Transaction *queue);
