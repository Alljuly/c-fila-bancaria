#include "transaction.h"


//Retorna um No do tipo transaction que aponta para NULL
Transaction* createNode(int cod);

//Recebe uma transação e insere no final da lista
void add(Transaction tr, Transaction *queue);

//Apaga a primeira transação da lista
void pop(Transaction *queue);

void getAll(Transaction *queue);
