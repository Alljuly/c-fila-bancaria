#include "client.h"

Client *createClient(int cod);

void enqueueClient(Client **queue, Client *newClient);

Client *dequeueClient(Client **queue);

void addTransaction(Client *client, Transaction t);

void printTransaction(Client *client);

