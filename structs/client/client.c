#include <stdio.h>
#include <stdlib.h>
#include "client.h"
#include "../transaction/transaction.h"

Client *createClient(int id)
{
    Client *newClient = (Client *)malloc(sizeof(Client));
    newClient->id = id;
    newClient->transactionList = NULL;
    newClient->entryTime = 0;
    newClient->exitTime = 0;
    newClient->next = NULL;
    return newClient;
}

void addTransactionToClient(Client *client, Transaction *transaction)
{
    if (client->transactionList == NULL)
    {
        client->transactionList = transaction;
    }
    else
    {
        Transaction *current = client->transactionList;
        while (current->prox != NULL)
        {
            current = current->prox;
        }
        current->prox = transaction;
    }
}

void printClientTransactions(Client *client)
{
    if (client->transactionList == NULL)
    {
        printf("Nenhuma transação encontrada para o cliente %d.\n", client->id);
        return;
    }
    printf("Transações para o cliente %d:\n", client->id);
    getAll(client->transactionList); // Função para listar transações
}
