#ifndef CLIENT_H
#define CLIENT_H

#include "transaction.h"
//lista encadeada
struct client {
    int info;
    Client *next;
    Transaction tr;             // FIFO?
};


typedef struct client Client;

Client* create(int cod);

void add(Client cli, Client *list);

void getAdd(Client cli, Client pr, Client *list);

void pop(Client *list);

void getAll(Client *list);


#endif