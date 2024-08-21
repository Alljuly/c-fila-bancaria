#ifndef MENU_TRANSACTION_H
#define  MENU_TRANSACTION_H
#include <stdio.h>
#include "../structs/transaction/transaction.h"

void menuTransaction();


void withdraw(Transaction **transactions);   // Saque (50s)
void deposit(Transaction **transactions);    // Depósito (70s)
void payment(Transaction **transactions);    // Pagamento (100s)
void transfer(Transaction **transactions);   // Transferência (60s)
void addTransactionHandle(int type, Transaction **transactions);


#endif