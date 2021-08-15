TAD's - Estrutura de Dados

Realocação Interplanetária 2076 - Aaron de Carvalho Balbino - Universidade Federal de Minas Gerais (UFMG) - Belo Horizonte – MG –Brasil 

Contato: carvalhosins@ufmg.br

1.	Introdução:
Esta documentação tem como objetivo realizar a descrição do Trabalho Prático 1, que tem a finalidade criar um sistema que representasse um grupo de servidores capazes de fazer transferências de consciência através da mega-net. Dada uma quantidade especificada de servidores, estes deveriam recolher não só dados mas também comandos respectivos a tratativa, envio, transição de informações de consciências internamente e também possíveis invasões ao sistema, a formulação deste será detalhada no tópico 2(Implementação).

2.	Implementacão:
O programa foi desenvolvido na linguagem C++, compilada pelo compilador G++ da GNU Compiler Collection.

2.1	– Estrutura de Dados:
O sistema foi implementado utilizando como base a estrutura de dados de fila duplamente encadeada. Este tipo foi escolhido devido ao fato de que, conforme documentação, a funcionalidade deveria respeitar regra de FIFO(first in first out).
Este fila foi composta por 5 elementos principais, sendo estes:
1 - Apontador para a frente da fila
2 - Apontador para o fim
3 - Apontador para próxima célula. (Incorporado dentro das células da fila)
4 - Apontador para célula anterior. (Incorporado dentro das células da fila)
5 – Dado para armazenar o tamanho da fila. (Evitando verificações e custos desnecessários)
 

Podemos definir a fila como uma estrutura que tem os ponteiros ini e fim (e, eventualmente, o tamanho da fila, n). Neste caso duplamente encadeada.

2.2	– Classes
Para modularização do sistema foram usadas 4 classes principais, segue esta e sua descrição de funcionalidade:

- SERVIDOR: Encarregada de carregar os buffer com as informações de envio de consciências(INFO) de sua respectiva chave, ou seja, servidor 0 contém somente dados enviados com a chave 0.
- FIFO: Encarregada de armazenar os comandos principais da fila e o escopo de apontadores tipo CELULA para a frente e o final da fila. Contém também tamanho conforme inserção de comandos.
- CELULA: Encarregada de armazenar um comando em sua estrutura, assim como os apontadores para a célula anterior e para a próxima célula. 
- COMANDO: Encarregada de armazenar os comandos recebidos e fazer a breve tratativa destes, esta armazena o identificador do comando, o servidor o qual este deve ser executado.

O sistema ainda conta com uma quarta classe chamada ARQUIVO que se encarrega estritamente da funções de leitura do arquivo e envio destes para a fila. Um breve esquema de organização pode ser verificado abaixo:


3 – Instruções de Compilação e Execução

3.1 – O programa, após compilado, pede que seja inserido o nome do arquivo “.txt” que será lido, este arquivo deve estar dentro da pasta src, sendo assim, digitar no terminal este nome sem adicionar o “.txt” ao final, conforme imagem abaixo:

4 – Análise de Complexidade
OBS: Internamente na fila, temos um duplo encadeamento entre as células(CELULA) que se comporta como a TAD lista duplamente encadeada, para esta, foi feita a tabela a seguir para conferência das complexidades gerais, as principais funcionalidades usadas foram caminhamento para impressão, sendo assim T(n) = O(n):
  

Sobre a fila encadeada principal(FIFO), dividi este tópico foi divido em sub-tópicos descritos abaixo:

4.1 – Tempo:
Classe Fifo:
Iniciando pela adição de um novo comando nesta fila, temos uma complexidade T(n) = O(1) para esta função pois o custo de inserção será sempre o mesmo. (FIFO::ENFILEIRA)
Seguido por funções que fazem a retirada de um elemento da fila, este elemento sempre será retirado do início da fila, tendo assim a complexidade T(n) = O(1). (FIFO::DESENFILEIRA)
Para a função que realiza a limpeza da lista, ou seja, a retirada de todos os elementos começando pelo início, temos uma complexidade de T(n) = O(n) pois esta deverá percorrer n vezes dentro da fila para apagar todos os elementos.(FIFO::LIMPA)
Temos também a função que faz a saída(output) conforme especificado que tem complexidade T(n) = O(n) pois esta percorre todas as células da fila de forma ascendente(último ao primeiro) para fazer a impressão dos dados. (FIFO::SAIDA)

Classe Servidor:
Funções de complexidade T(n) = O(1):
- AddBuffer(): Adiciona sempre ao final do buffer.
- setTamanho(): Seta o tamanho do buffer.
- getTamanho(): Retorna o tamanho do buffer.
- Warn(): Seta a primeira posição do buffer com a posição indica no parâmetro.

Por fim temos duas funções com complexidade T(n) = O(n):
- Imprime(): Esta percorre todo o buffer afim de imprimir na tela os resultados.
- limpaBuffer(): Percorre todas as posições do buffer e utiliza o comando .clear() para limpeza.

Classe Celula:
Temos a função Executa(), que define os valores chaves para o comando, como seu identificador(char com primeira letra do comando), os servidor que este comando pertence, assim como, em caso de transferência a relação de de-para de servidores. Este tem complexidade O(1) pois essa função faz a verificação por linha a linha do arquivo.

Classe Comando:
Funções de complexidade T(n) = O(1):
- GetChave(): Retorna a chave do comando.
- getServidor(): Retorna o servidor do comando.
- getComando(): Retorna o comando(string).
- getIdentificador(): Retorna o identificador(char com primeira letra do comando).
- SetChave(): Define o valor da chave do comando.
- setServidor(): Define o referente ao comando.
- setComando(): Define o comando(string) da classe.
- setIdentificador(): Define o identificador da classe.
- Imprime(): Imprime a string comando contida na classe.


4.1 – Espaço:
Considerando que cada célula comando da fila ocupe uma unidade de espaço, estas foram divididas em 3 filas, sendo uma(FIFO1) que armazena somente os dados tipo INFO e os envia para buffer dos respectivos servidores.
Uma segunda(FIFO2) que armazena qualquer tipo de comando que não seja INFO para serem enviados e tratados conforme descrição nos servidores totalizando assim uma complexidade O(n).
E por fim uma fila quer armazena todos os comando obtidos para representar um histórico global(FIFO3) que totaliza uma complexidade O(n).
Desta forma, temos que a complexidade final de n-qtdINFO para FIFO1, n-qtdNAOINFO em FIFO dois2 totalizando n, e na FIFO3 temos n para a cópia completa da fila. 

O(n) + O(n) = 2O(n) = O(n)
 

5 – Conclusão
Após iniciar a implementação do trabalho pode se notar que não somente será necessário fazer a criação de uma fila, mas também instâncias de estruturas que representam os servidores, pois uma fila de comandos qualquer pode ter comandos de n servidores.
 
A primeira parte implementada foi a estrutura que ficaria responsável pela leitura do arquivo, esta é muito importante pois a partir de uma leitura correta as informações seriam distribuídas na segunda parte da implementação. 

A segunda parte, que é constituída pela implementação da fila encadeada e suas respectivas funcionalidades de inserção, busca e impressão e posteriormente a implementação da classe responsável por representar os servidores que carregam consigo um buffer para armazenar os dados. 

Referências:
- Ziviani, N. (2006). Projetos de Algoritmos com Implementac¸oes em Java e C++: ˜ Capítulo 3: Estruturas de Dados Basicas . Editora Cengage.

- Prof. Ronaldo S. Mello - Estruturas de Dados e Análises de Complexidade - UFSC 
