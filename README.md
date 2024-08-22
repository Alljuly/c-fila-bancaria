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
├── main.exe
├── menu
│   ├── main.exe
│   ├── menu.c
│   ├── menu.h
│   ├── menuTransaction.c
│   └── menuTransaction.h
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

### Definições das Structs

- Para Transações (Transaction):
  - Para a fila de transações foi implementada uma lista encadeada, permitindo um gerenciamento dinâmico.
    ```C
    struct transaction {
    int cod;
    int s;
    Transaction *prox;
    };
    typedef struct transaction Transaction;
    ```
  - Metódos:
    - Transaction *createTransaction(int cod, int seconds);
    - void add(Transaction **queue, Transaction *newTransaction);
    - void pop(Transaction **queue);
    - void getAll(Transaction *queue);
- Para Cliente (Client):
  - Foi definido que a estrutura de cliente seria utilizado uma fila, dessa forma "Client".
    ```C
    typedef struct client
    {
    int id; // Identificação do cliente
    Transaction *transactionList; // Lista de transações que o cliente irá realizar
    time_t entryTime;  // Momento que o cliente foi alocado na fila
    time_t exitTime;   // Momento que o cliente teve seu atendimento finalizado
    struct client *next; // Aponta para o proximo cliente na fila 
    } Client;
    ```
  - Seguindo a lógica de uma fila real de um banco, o conceito de uma estrutura FIFO se encaixaria bem.
  - Metódos:
    - Client *createClient(int id);
    - void addTransactionToClient(Client *client, Transaction *transaction);
    - void printClientTransactions(Client *client);
  - Por se Tratar de uma fila, a clientQueue foi definida para genrencia-la.
- Para a Fila de clientes (ClientQueue):
  - Responsável por gerenciar os clientes, sua estrutura consiste em:
    ```C
    typedef struct clientQueue
    {
    Client *front; // Aponta para o primeiro cliente da fila
    Client  *rear;  // Aponta para o último cliente da fila
    } ClientQueue;
     ```
  - Metódos:
    - ClientQueue *createQueue();
    - int isQueueEmpty(ClientQueue *queue);
    - void enqueueClient(ClientQueue *queue, Client *newClient);
    - Client *dequeueClient(ClientQueue *queue);
    - void printQueue(ClientQueue *queue);
    
### Definindo Menu


### Definindo Handle


### Como Utilizar

- Entre no diretório ``menu``:
```shell
cd menu
```
- Execute
```shell
gcc ../main.c ./client/menuClient.c ./transaction/menuTransaction.c ../structs/client/client.c ../structs/transaction/transaction.c ../structs/clientQueue/clientQueue.c -o ./main

./main
```
- Main


