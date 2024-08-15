#include <stdio.h>
#include <stdlib.h>
#include "structs/clientQueue/clientQueue.h"

int main()
{
    ClientQueue *queue = createQueue();

    if (queue == NULL)
    {
        printf("Erro ao criar a fila.\n");
        return 1;
    }
    printf("Fila de clientes criada\n");

    if (isQueueEmpty(queue))
    {
        printf("A fila está vazia.\n");
    }

    free(queue);
    return 0;
}