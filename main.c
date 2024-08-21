#include "menu/menu.h"
#include "structs/client/client.h"
#include "structs/clientQueue/clientQueue.h"
#include "structs/transaction/transaction.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* Teste das funções
execute
gcc -mconsole  ./main.c ./menu/menu.c ./menu/handles/handleTransaction.c ./structs/client/client.c ./structs/transaction/transaction.c ./structs/clientQueue/clientQueue.c -o main
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
      printRelatory(enqueue);
      break;
    case 4:
      printRelatory(attempt);
      break;
    default:
      printf("\nOpcao invalida\n\n");
      break;
    }
  }

  return 0;
}