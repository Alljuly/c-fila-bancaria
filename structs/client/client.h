#ifndef CLIENT_H
#define CLIENT_H

#include "transaction.h"

typedef struct client {
    int info;
    Transaction *transactionList; // Cabeça da lista encadeada de transações do cliente
    struct client *next;          // Ponteiro para o próximo cliente na fila
} Client;

// Funções para manipulação de clientes
Client* createClient(int cod);                      // Cria um novo cliente com um código específico

void enqueueClient(Client **queue, Client *newClient); // Adiciona um cliente na fila

Client* dequeueClient(Client **queue);              // Remove o próximo cliente da fila

void addTr(Client *client, Transaction t); // Adiciona uma transação na lista encadeada do cliente

void printTr(Client *client);             // Exibe todas as transações do cliente

#endif
