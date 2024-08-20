#ifndef CLIENT_H
#define CLIENT_H

#include <time.h>

#include "../transaction/transaction.h"
typedef struct client {
  int id;
  Transaction *transactionList;
  time_t entryTime;
  time_t exitTime;
  struct client *next;
} Client;

Client *createClient(int id);

void addTransactionToClient(Client *client, Transaction *transaction);

void printClientTransactions(Client *client);

#endif // CLIENT_H
