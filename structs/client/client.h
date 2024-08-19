#ifndef CLIENT_H
#define CLIENT_H

#include <time.h>

#include "../transaction/transaction.h"
#include "../clientQueue/clientQueue.h"
typedef struct client
{
    int id;
    Transaction *transactionList; // Lista de transações
    time_t entryTime;
    time_t exitTime;
    struct client *next; // Para a fila de clientes
} Client;

Client *createClient(int id);

void addTransactionToClient(Client *client, Transaction *transaction);

void printClientTransactions(Client *client);

#endif // CLIENT_H
