# 🫰 Conheça o _Nosso Banco_
Projeto construído para a matéria de Estrutura de Dados para implementação de um fila de banco.

_Contribuições_ 

[Alice Julia Silva Costa](https://github.com/Alljuly)

[Emanuel Vilela de Souza](https://github.com/emanuelvsz)
<div style="display: flex; flex-direction:row;">
    <div style="box-sizing: border-box;">
    <h2>Descrição geral da atividade</h2>
    <i>Simulação de atendimento bancário, com uma fila de clientes, que podem realizar 1 ou mais transações.</i>
    <br>
    <br>
    <i>Para avaliação da atividade, será observado:</i>
    <ul>
      <li>Todo o projeto em C.</li>
      <li>Uso de listas encadeadas e filas.</li>
      <li>Modularidade do código.</li>
      <li>Documentação interna.</li>
      <li>Outros assuntos abordados na matéria.</li>
      <li>Justificativa das estruturas de dados utilizadas.</li>
    </ul>
  </div>
    <div style=" box-sizing: border-box;">
    <h2>Requisitos</h2>
    <i>Além de fazer o gerenciamento da fila, o sistema deve:</i>
    <ul>
      <li>Exibir o tempo que o cliente permaneceu na fila.</li>
      <li>Quando o cliente entra na fila o tempo é registrado para ser adicionado no tempo final que ele ficou.</li>
      <li>O cliente pode fazer uma ou várias das transações.</li>
      <li>No final do expediente, relatório que a gerência analisa sobre o atendimento.</li>
    </ul>
    <h4>Relatório sobre o atendimento</h4>
    <ul>
      <li>Quantidade de clientes.</li>
      <li>Tempo total.</li>
      <li>Tempo de cada cliente.</li>
      <li>Atendimento por prioridade.</li>
    </ul>
    <h4>Transações</h4>
    <table>
      <tr>
      <th>Código</th>
      <th>Transação</th> 
      <th>Duração</th> 
      </tr>
      <tr>
      <th>1</th>
      <th>Saque</th> 
      <th>50s</th> 
      </tr>
      <tr>
      <th>2</th>
      <th>Depósito</th> 
      <th>70s</th> 
      </tr>
      <tr>
      <th>3</th>
      <th>Pagamento</th> 
      <th>100s</th> 
      </tr>
      <tr>
      <th>4</th>
      <th>Transferência</th> 
      <th>60s</th> 
      </tr>
      </table>
    </td>
  </tr>
</table>
  </div>
  

</div>

## Processo para elaboração do projeto

### Estrutura de Diretórios do Projeto

```shell
.
├── LICENSE
├── README.md
├── main.c
├── menu
│   ├── client
│   │   ├── menuClient.c
│   │   └── menuClient.h
│   └── transaction
│       ├── menuTransaction.c
│       └── menuTransaction.h
├── readme.txt
└── structs
    ├── client
    │   ├── client.c
    │   └── client.h
    ├── clientQueue
    │   ├── clientQueue.c
    │   └── clientQueue.h
    └── transaction
        ├── transaction.c
        └── transaction.h
```

### Bibliotecas Utilizadas
- #include <stdio.h>
- #include <stdlib.h>
- #include <unistd.h>
- #include <time.h>

### Definições das Structs

- Para Transações `Transaction`:
  - Para a fila de transações foi implementada uma lista encadeada, permitindo um gerenciamento dinâmico.
    ```C
    struct transaction {
    int cod; // Codigo do tipo da transação
    int s; // Tempo estimado para efetuar a transação
    Transaction *prox; // ponteiro para a proxima transação da lista
    };
    typedef struct transaction Transaction;
    ```
  - Metódos:
    ```C
    Transaction *createTransaction(int cod, int seconds);
    void add(Transaction **queue, Transaction *newTransaction);
    void pop(Transaction **queue);
    void getAll(Transaction *queue);
    ```
      
- Para Cliente `Client`:
  - Foi definido que a estrutura de cliente seria utilizado uma fila, dessa forma "Client".
    ```C
    typedef struct client
    {
    int id; // Identificação do cliente
    int priority; // Indentificação de prioridade
    Transaction *transactionList; // Lista de transações que o cliente irá realizar
    time_t entryTime;  // Momento que o cliente foi alocado na fila
    time_t exitTime;   // Momento que o cliente teve seu atendimento finalizado
    struct client *next; // Aponta para o proximo cliente na fila 
    } Client;
    ```
  - Seguindo a lógica de uma fila real de um banco, o conceito de uma estrutura FIFO se encaixaria bem.
  - Metódos:
    ```C
    Client *createClient(int id);
    void addTransactionToClient(Client *client, Transaction *transaction);
    void printClientTransactions(Client *client);
    ```
  - Por se Tratar de uma fila, a clientQueue foi definida para genrencia-la.
    
- Para a Fila de clientes `ClientQueue`:
  - Responsável por gerenciar os clientes, sua estrutura consiste em:
    ```C
    typedef struct clientQueue
    {
    Client *front; // Aponta para o primeiro cliente da fila
    Client  *rear;  // Aponta para o último cliente da fila
    } ClientQueue;
    ```
  - Metódos:
    ```C
    ClientQueue *createQueue();
    int isQueueEmpty(ClientQueue *queue);
    void enqueueClient(ClientQueue *queue, Client *newClient);
    void enqueueAttemptClient(ClientQueue *queue, Client *newClient);
    Client *dequeueClient(ClientQueue *queue);
    void printQueue(ClientQueue *queue);
    ```
    
### Definindo Menu
#### Os diretórios `menu/client` e `menu/transaction` possuem as funções responsáveis por gerenciar todas as funcionalidades do banco.
  - menu/client.h:
    ```C
        // imprime o menu para atender o cliente
    void printMenu();

        // responsável por adicionar cliente a fila para ser atendido de acordo sua prioridade
    void addClientToQueue(ClientQueue *queue);
    
        //simula tempo de atendimento
    void waitForTransaction(int seconds);
    
        // adiciona as transações para o cliente
    Transaction *addTransactionsToClient();

        // imprime relatório de clientes na fila
    void viewClientInQueue(Client *queue);

        // imprime relatório das transacoes do cliente
    void viewClientTransactions(Client *queue);

        // remove cliente da fila 
    void removeClientFromQueue(ClientQueue *queue);
    
        // Começa os atendimentos dos clientes na fila
    void attendClient(ClientQueue *queueClients, ClientQueue *attemptedClients);

        // imprime o relátorio geral da fila.
    void printRelatory(ClientQueue *queue);
    
        // Verifica filas de atendimento para encerrar expediente.
    int endAttendence(ClientQueue *enqueue, ClientQueue *attempt);
    ```
    
#### Visualização do `menuClient.c` que o usuário acessa em `main`
![menuClient](https://github.com/user-attachments/assets/62c1b014-6c5e-425d-abb2-ab76c00a219c)

  - menu/transaction:
    ```C
        // imprime o menu das transações, auxiliar de cliente
    void menuTransaction();

        // adiciona um saque a lista de transações
    void withdraw(Transaction **transactions);   // Saque (50s)
    
        // adiciona um depósito a lista de transações
    void deposit(Transaction **transactions);    // Depósito (70s)
    
        // adiciona um pagamento a lista de transações
    void payment(Transaction **transactions);    // Pagamento (100s)
    
        // adiciona uma transferência a lista de transações
    void transfer(Transaction **transactions);   // Transferência (60s)
    
         // switch para tipo de transação
    void addTransactionHandle(int type, Transaction **transactions);
    ```
#### Visualização do `menuTransaction.c` que o usuário acessa em `main`
![menuTransaction](https://github.com/user-attachments/assets/b5a3e3f8-a484-47ca-bd4d-a846fa956f9b)
    
### Como Utilizar

Clone o repo
```Shell
    ~ git clone https://github.com/Alljuly/c-fila-bancaria/
```
Dentro da raiz do projeto, execute:
```Shell
    ~ gcc ./main.c ./menu/client/menuClient.c ./menu/transaction/menuTransaction.c ./structs/client/client.c ./structs/transaction/transaction.c ./structs/clientQueue/clientQueue.c -o ./main

    ~ ./main
```


