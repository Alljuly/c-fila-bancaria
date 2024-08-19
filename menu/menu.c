void printMenu()
{
    printf("\nMenu:\n");
    printf("1. Adicionar cliente à fila\n");
    printf("2. Ver clientes na fila existente\n");
    printf("3. Remover cliente da fila\n");
    printf("4. Ver transações por cliente\n");
    printf("5. Atender cliente\n");
    printf("6. Sair\n");
}


void addClientToQueue(ClientQueue *queue)
{
    int id;
    printf("Digite o ID do cliente: ");
    scanf("%d", &id);

    Client *newClient = createClient(id);
    if (newClient == NULL)
    {
        printf("Erro ao criar o cliente.\n");
        return;
    }

    enqueueClient(queue, newClient);
    printf("Cliente adicionado à fila com sucesso.\n");
}

void viewClientsInQueue(ClientQueue *queue)
{
    printQueue(queue);
}

void removeClientFromQueue(ClientQueue *queue)
{
    Client *removedClient = dequeueClient(queue);
    if (removedClient == NULL)
    {
        printf("Fila vazia. Nenhum cliente para remover.\n");
    }
    else
    {
        printf("Cliente com ID %d removido da fila.\n", removedClient->id);
        free(removedClient); // Libere a memória do cliente removido
    }
}

void viewClientTransactions(ClientQueue *queue)
{
    if (queue->front != NULL)
    {
        Client *currentClient = queue->front;
        printClientTransactions(currentClient);
    }
    else
    {
        printf("Nenhum cliente na fila para visualizar transações.\n");
    }
}

void attendClient(ClientQueue *queue)
{
    if (isQueueEmpty(queue))
    {
        printf("Nenhum cliente para atender.\n");
        return;
    }

    int currentTime = time(NULL); // Tempo atual
    Client *clientToAttend = dequeueClient(queue);

    if (clientToAttend != NULL)
    {
        clientToAttend->entryTime = currentTime;
        printf("Atendendo cliente %d...\n", clientToAttend->id);

        Transaction *currentTransaction = clientToAttend->transactionList;
        int totalProcessingTime = 0;

        while (currentTransaction != NULL)
        {
            totalProcessingTime += currentTransaction->seconds;
            currentTransaction = currentTransaction->prox;
        }

        // Espera simulada do atendimento
        sleep(totalProcessingTime);

        clientToAttend->exitTime = time(NULL);
        printf("Cliente %d atendido.\n", clientToAttend->id);

        free(clientToAttend);
    }
}
