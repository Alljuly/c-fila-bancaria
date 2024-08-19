#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "structs/clientQueue/clientQueue.h"
#include "structs/client/client.h"
#include "structs/transaction/transaction.h"


int main()
{
    ClientQueue *queue = createQueue();
    if (queue == NULL)
    {
        printf("Erro ao criar a fila.\n");
        return 1;
    }

    int choice;

    while (1)
    {
        printMenu();
        printf("Escolha uma opção: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addClientToQueue(queue);
            break;
        case 2:
            viewClientsInQueue(queue);
            break;
        case 3:
            removeClientFromQueue(queue);
            break;
        case 4:
            viewClientTransactions(queue);
            break;
        case 5:
            attendClient(queue);
            break;
        case 6:
            printf("Saindo...\n");
            // Liberar memória alocada
            while (!isQueueEmpty(queue))
            {
                Client *clientToFree = dequeueClient(queue);
                free(clientToFree);
            }
            free(queue);
            return 0;
        default:
            printf("Opção inválida. Tente novamente.\n");
        }
    }

    return 0;
}