#ifndef MENU_H
#define MENU_H

#include "../../structs/client/client.h"
#include "../../structs/transaction/transaction.h"
#include "../../structs/clientQueue/clientQueue.h"
#include "../transaction/menuTransaction.h"

void printMenu();

void addClientToQueue(ClientQueue *queue);

Transaction *addTransactionsToClient();

void viewClientInQueue(Client *queue);

void removeClientFromQueue(ClientQueue *queue);

void viewClientTransactions(Client *queue);

void attendClient(ClientQueue *queueClients, ClientQueue *attemptedClients);

void printRelatory(ClientQueue *queue);

#endif
