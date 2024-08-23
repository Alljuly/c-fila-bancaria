#ifndef MENU_H
#define MENU_H

#include "../../structs/client/client.h"
#include "../../structs/transaction/transaction.h"
#include "../../structs/clientQueue/clientQueue.h"
#include "../transaction/menuTransaction.h"

void printMenu();

void addClientToQueue(ClientQueue *queue);

//simula tempo de atendimento
void waitForTransaction(int seconds);

Transaction *addTransactionsToClient();

void viewClientInQueue(Client *queue);

void viewClientTransactions(Client *queue);

void removeClientFromQueue(ClientQueue *queue);

void attendClient(ClientQueue *queueClients, ClientQueue *attemptedClients);

void printRelatory(ClientQueue *queue);

int endAttendence(ClientQueue *enqueue, ClientQueue *attempt);

#endif
