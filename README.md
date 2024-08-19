# 🫰 Conheça o _Nosso Banco_
Projeto construído para a matéria de Estrutura de Dados para implementação de um fila de banco.

## O que foi pedido
_Simulação de atendimento bancário, com uma fila de clientes, que podem realizar 1 ou mais transações._

_Para avaliação da atividade, será observado:_
- Todo o projeto em C.
- Uso de listas encadeadas e filas.
- Modularidade do código.
- Documentação interna.
- Outros assunstos abordados na matéria.
- Justificativa das estruturas de dados utilizadas.

### Requisitos
_Além de fazer o gerenciamento da fila, o sistema deve:_

- Exibir o tempo que o cliente permaneceu na fila.
- Quando o cliente entra na fila o tempo é registrado para ser adicionado no tempo final que ele ficou.
- O cliente pode fazer uma ou várias das transações.
- No final do expediente, relatório que a gerência analisa sobre o atendimento.
  
  #### Relário sobre o atendimento
    - Quantidade de clientes.
    - Tempo total.
    - Tempo de cada cliente.
    - Atendimento por prioridade.

  #### Transações

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

## Processo para elaboração do projeto

### Estrutura de Diretórios do Projeto

```shell
.
├── LICENSE
├── README.md
├── main.c
├── menu
│   └── menu.c
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

### Definindo as Structs
- Para Cliente:
  - Lista encadeada ou fila (definir ainda);
  - sei la
  - bla bla
  - bla bla
```C
typedef struct client {
    int info;
    //adicionar variavel que guarde o instante que o cliente chegou
    Transaction *transactionList; // Cabeça da lista encadeada de transações do cliente
    struct client *next;          // Ponteiro para o próximo cliente na fila
} Client;
```   
- Para Transações:
  - Lista encadeada ou fila (definir ainda);
  - sei la
  - bla bla
  - bla bla
```C
struct transaction {
    int cod;
    int s;
    Transaction *prox;
};
typedef struct transaction Transaction;
```  
 
