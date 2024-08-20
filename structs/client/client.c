#include "client.h"
#include "../transaction/transaction.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//Cria um novo cliente
Client *createClient(int id) {
  Client *newClient = (Client *)malloc(sizeof(Client));
  newClient->id = id;
  newClient->transactionList = NULL;
  newClient->entryTime = time(NULL);
  newClient->exitTime = 0;
  newClient->next = NULL;
  return newClient;
}

//Adiciona uma transação a fila de transações de cliente
void addTransactionToClient(Client *client, Transaction *transaction) {
  if (client->transactionList == NULL) {
    client->transactionList = transaction;
  } else {
    Transaction *current = client->transactionList;
    while (current->prox != NULL) {
      current = current->prox;
    }
    current->prox = transaction;
  }
}


//Imprime todas as transações caso tenha
void printClientTransactions(Client *client) {
  if (client->transactionList == NULL) {

    printf("+---------------------------------------------+\n");
    printf("| Nenhuma transação encontrada para o cliente |\n");
    printf("|                     %d                      |\n", client->id);
    printf("+---------------------------------------------+\n");
    
    return;
  }
  printf("+----------------------------------+\n");
  printf(" |    Transacoes para o cliente %d |\n", client->id);
  printf("+----------------------------------+\n");
  getAll(client->transactionList);
}

/*Teste das funções 
Remova os comentarios e execute
gcc-9 ./client.c ../transaction/transaction.c -o ./main
./main
int main(){
  Transaction *t = createTransaction(1,50);
  Transaction *t1 = createTransaction(2,100);

  Client *c = createClient(1);
  Client *c1 = createClient(1);
  addTransactionToClient(c, t);

  printClientTransactions(c);

  printClientTransactions(c1);



  return 0;

}

*/