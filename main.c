#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "structs/clientQueue/clientQueue.h"
#include "menu/menu.h"


int main()
{
    ClientQueue *enqueue = createQueue();
    ClientQueue *attempt = cretateQueue();

    int choice;

    while (1)
    {
        printMenu();
        scanf("%d",&choice);

        switch(choice){
            case 1:
                addClientToQueue(enqueue);
            case 2:
                attendClient(enqueue, attempt);
            case 3:
                printRelatory(enqueue);
            case 4:
                printRelatory(attempt);
        }

    }

    return 0;
}