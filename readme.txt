Olá meu querido.

Estou um pouco desocupada então vou anotar algumas ideias aqui.

1 - Vi que temos um tópico no relatório final onde se fala de prioriade, para isso pensei em separar numeros impares para clientes prioritarios e ordernar:
  A cada 2 atendimentos como prioridade 1 atendimento normal.
  Nesse caso a info do cliente seria um int, ou escolher uma letra para normal ou prioridade.
  Se você pensar em fazer isso de outra forma me conte.

*Isso entraria na lógica na hora de ordenar os atendimentos então não vai implicar em nada por enquanto na implementação das structs, etc.

2 - Temos que gerenciar o tempo que cada cliente leva em atendimento, mas o que impede de chegar outro cliente enquanto o primeiro está em atendimento?
Então alocamos todos os clientes e depois começamos a atender?
Ou criamos uma fila de atendimentos, e outra para os cliente que estão chegando.
Isso pode ficar mais complicado de implementar.

3 - Acho importante fazer primeiro o layout do relatório final, para sabermos exatamente quais informações serão necessárias.

4 - E se ao adicionar o cliente:
    I - Salvamos o instante que ele entrou, numa lista de atendimentos. 
    II - Ordenamos nessa lista de acordo sua prioriade.
    III - Só começamos a adicionar suas transações se ele for o primeiro da lista.
    IV - Pegamos o instante (i) em que começamos a adicionar as trasações, criar uma função ATENDER, que irá somar em outra variavel ´fim´ ao *i* os segundos de cada operação.
    V - O cliente sai da lista de atendimentos, e vai para atendidos.
    V -  Nessa realocação e definido o instante que ele saiu de acordo com ´fim´.

5 -  Função atender:
  - Precisa verificar se a lista está vazia, se n tiver atende.
  - Talvez uma var "ocupado" tipo booleana;
