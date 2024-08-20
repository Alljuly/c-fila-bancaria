#ifndef MENU_H
#define MENU_H

#include "../structs/clientQueue/clientQueue.h"

void printMenu();

void addClientToQueue(ClientQueue *queue);

void viewClientInQueue(Client *queue);

void removeClientFromQueue(ClientQueue *queue);

void viewClientTransactions(Client *queue);

void attendClient(ClientQueue *queueClients, ClientQueue *attemptedClients);

void printRelatory(ClientQueue *queue);

#endif