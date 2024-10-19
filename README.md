# Estacionamento-Pilha-de-Dados
Implementação de um sistema de controle de estacionamento usando pilha, parte de um trabalho de Estruturas de Dados. O programa simula a entrada e saída de carros em um estacionamento com capacidade limitada, gerenciando manobras e verificando vagas.


O programa processa linhas de entrada que indicam a chegada ('E') ou a saída ('S') de um carro no estacionamento, seguidas pela placa do veículo. Cada operação é executada na ordem fornecida.

Por exemplo, as seguintes entradas:

E ABC1234
E DEF5678
E GHI9012
S DEF5678
E JKL3456
significam que o carro de placa "ABC1234" entrou, seguido pelos carros "DEF5678" e "GHI9012". Em seguida, o carro "DEF5678" saiu, e depois o carro "JKL3456" entrou.

O estacionamento tem capacidade limitada a 5 vagas e funciona com uma única entrada/saída, semelhante a uma estrutura de pilha. Isso significa que, para um carro sair, todos os carros à sua frente precisam ser removidos temporariamente.

Para cada evento de entrada, o programa verifica se há vaga. Se houver, o carro entra; caso contrário, é informado que o estacionamento está cheio. Ao sair, o programa conta e imprime quantas vezes o carro foi manobrado para permitir a saída de outros veículos.

![image](https://github.com/user-attachments/assets/6428d205-6741-4687-a025-d5184029404a)

