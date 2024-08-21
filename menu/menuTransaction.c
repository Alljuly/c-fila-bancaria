#include <stdio.h>
#include "../structs/transaction/transaction.h"

void menuTransaction()
{
    printf("+-------------------------------+\n");
    printf("|           Operacoes           |\n");
    printf("+-------------------------------+\n");
    printf("| 1. Saque                      |\n");
    printf("| 2. Deposito                   |\n");
    printf("| 3. Pagamento                  |\n");
    printf("| 4. Transferencia              |\n");
    printf("+-------------------------------+\n");
}

void withdraw(Transaction **transactions)
{
    Transaction *t = createTransaction(1, 50);
    add(transactions, t);
} // Saque (50s)
void deposit(Transaction **transactions)
{
    Transaction *t = createTransaction(2, 70);
    add(transactions, t);
} // Depósito (70s)
void payment(Transaction **transactions)
{
    Transaction *t = createTransaction(3, 100);
    add(transactions, t);
} // Pagamento (100s)
void transfer(Transaction **transactions)
{
    Transaction *t = createTransaction(4, 60);
    add(transactions, t);
} // Transferência (60s)

void addTransactionHandle(int type, Transaction **transactions)
{
    switch (type)
    {
    case 1:
        withdraw(transactions);
        break;
    case 2:
        deposit(transactions);
        break;
    case 3:
        payment(transactions);
        break;
    case 4:
        transfer(transactions);
        break;
    default:
        printf("..... Opção invalida\n\n");
        break;
    }
}
