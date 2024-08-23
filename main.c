#include "menu/client/menuClient.h"
#include "structs/client/client.h"
#include "structs/clientQueue/clientQueue.h"
#include "structs/transaction/transaction.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* Teste das funções
execute
gcc -mconsole  ./main.c ./menu/menu.c ./menu/handles/handleTransaction.c ./structs/client/client.c ./structs/transaction/transaction.c ./structs/clientQueue/clientQueue.c -o main
gcc-9  ./main.c ./menu/menuTransaction/MenuTransaction.c ./menu/menuClient/menuClient.c ./structs/client/client.c ./structs/transaction/transaction.c ./structs/clientQueue/clientQueue.c -o ./main

./main
*/

int main()
{
  ClientQueue *enqueue = createQueue();
  ClientQueue *attempt = createQueue();

  int choice;

  while (1)
  {
    printMenu();
    printf("Opcao: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      addClientToQueue(enqueue);
      break;
    case 2:
      attendClient(enqueue, attempt);
      break;
    case 3:
      system("clear");
      printRelatory(enqueue);
      break;
    case 4:
      system("clear");
      printRelatory(attempt);
      break;
    case 5:
      system("clear");
      if(endAttendence(enqueue, attempt)){
        return 0;
      }
      break;
    default:
      printf("\nOpcao invalida\n\n");
      break;
    }
  }

  return 0;
}