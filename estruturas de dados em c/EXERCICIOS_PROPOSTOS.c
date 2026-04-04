/**
 * ============================================================
 * ESTRUTURAS DE DADOS EM C - EXERCÍCIOS PROPOSTOS
 * ============================================================
 * 
 * Este arquivo contém exercícios para você praticar e consolidar
 * seu conhecimento de estruturas de dados.
 * Dificuldade: Básica, Intermediária, Avançada
 * 
 */

// ============================================================
// EXERCÍCIOS COM LISTAS ENCADEADAS
// ============================================================

/*
EXERCÍCIO 1.1 - Básico (Lista Encadeada Linear)
Faça uma função que INVERTE uma lista encadeada.
Exemplo: 1 -> 2 -> 3 -> NULL vira NULL <- 1 <- 2 <- 3 (ou exibir de trás para frente)

Dica: Use uma pilha ou recursão para armazenar os valores durante a inversão.

SOLUÇÃO ESPERADA:
  - Função: no *inverter_lista(no *cabeca);
  - Deve liberar a memória corretamente
  - Testar: 1,2,3,4,5 -> 5,4,3,2,1
*/

/*
EXERCÍCIO 1.2 - Básico (Lista Linear)
Faça uma função que CONTA quantos elementos existem na lista.
Função: int contar_elementos(no *cabeca);

Desafio extra: Faça uma função RECURSIVA.
*/

/*
EXERCÍCIO 1.3 - Intermediário (Lista Linear)
Faça uma função que ORDENA a lista encadeada em ordem crescente.
Função: no *ordenar_lista(no *cabeca);

Dica: Pode usar bubble sort ou insertion sort.
Teste: 30 -> 10 -> 50 -> 20 -> NULL vira 10 -> 20 -> 30 -> 50 -> NULL
*/

/*
EXERCÍCIO 1.4 - Intermediário (Lista Dupla)
Faça uma função que CONCATENA duas listas duplamente encadeadas.
Função: no_duplo *concatenar_listas(no_duplo *lista1, no_duplo *lista2);

Teste: (1 <-> 2 <-> 3) concatenada com (4 <-> 5 <-> 6)
Resultado: 1 <-> 2 <-> 3 <-> 4 <-> 5 <-> 6
*/

/*
EXERCÍCIO 1.5 - Avançado (Lista Circular)
Faça uma função que ENCONTRA O MEIO de uma lista circular.
Função: no_circular *encontrar_meio(no_circular *cabeca);

Dica: Use dois apontadores (slow e fast).
*/

// ============================================================
// EXERCÍCIOS COM PILHA
// ============================================================

/*
EXERCÍCIO 2.1 - Básico (Pilha)
Faça uma função que CONVERTE um número decimal para BINÁRIO usando pilha.
Função: void decimal_para_binario(int numero);

Exemplo: 10 -> 1010
Passo a passo:
  10 % 2 = 0 (push)
  5  % 2 = 1 (push)
  2  % 2 = 0 (push)
  1  % 2 = 1 (push)
  Pop tudo: 1010
*/

/*
EXERCÍCIO 2.2 - Intermediário (Pilha)
Faça uma função que CONVERTE uma expressão INFIXA para POSFIXA (Notação Polonesa Reversa).
Função: void infixa_para_posfixa(const char *expressao);

Exemplo: "2 + 3 * 4" vira "2 3 4 * +"
Regra: * / têm prioridade sobre + -

Dica: Use pilha para operadores.
*/

/*
EXERCÍCIO 2.3 - Intermediário (Pilha)
Faça uma função que AVALIA uma expressão em notação POSFIXA.
Função: int avaliar_posfixa(const char *expressao);

Exemplo: "2 3 +" = 5
         "2 3 4 * +" = 14
*/

/*
EXERCÍCIO 2.4 - Avançado (Pilha)
Faça um DESFAZEDOR (Undo/Redo) para um editor de texto.
Operações:
  - add_caracter(char c)  -> push para pilha de undo
  - undo()                -> pop e push na pilha de redo
  - redo()                -> pop de redo e push em undo
*/

// ============================================================
// EXERCÍCIOS COM FILA
// ============================================================

/*
EXERCÍCIO 3.1 - Básico (Fila)
Faça uma SIMULAÇÃO DE FILA DE ATENDIMENTO BANCÁRIO.
Requisitos:
  - Cliente com ID, CPF e tempo de atendimento
  - Registrar chegada e atendimento
  - Mostrar tempo de espera

Dica: Pode usar timestamp ou apenas um contador.
*/

/*
EXERCÍCIO 3.2 - Intermediário (Fila)
Implemente uma FILA DUPLA (DEQUE - Double Ended Queue).
Funções necessárias:
  - push_frente()
  - push_tras()
  - pop_frente()
  - pop_tras()
  - ver_frente()
  - ver_tras()

Exemplo: começando com []
  push_frente(1) -> [1]
  push_tras(2)   -> [1, 2]
  push_frente(0) -> [0, 1, 2]
  pop_tras()     -> [0, 1] (removeu 2)
*/

/*
EXERCÍCIO 3.3 - Intermediário (Fila)
Simule um SISTEMA DE IMPRESSORAS com fila de documentos.
Requisitos:
  - Adicionar documentos à fila
  - Imprimir (remover) 1 documento por vez
  - Prioritários vão para a frente
  - Relatório de fila

Tipo de documento:
  struct documento {
    int id;
    char nome[50];
    int paginas;
    int prioridade;  // 1=baixa, 2=média, 3=alta
  }
*/

/*
EXERCÍCIO 3.4 - Avançado (Fila)
Simule um SEMÁFORO COM FILA DE CARROS.
Requisitos:
  - 2 pistas: A e B
  - Os 5 primeiros carros passam quando semáforo fica verde
  - Semáforo alterna a cada 20 "ticks"
  - Mostrar: carros passando, fila de espera
*/

// ============================================================
// EXERCÍCIOS MISTOS
// ============================================================

/*
EXERCÍCIO 4.1 - Intermediário (Listas + Pilha)
Faça um VALIDADOR DE EXPRESSÕES MATEMÁTICAS.
Checar:
  - Parênteses | colchetes | chaves balanceados
  - Operadores válidos (não começar/terminar com operador)
  - Número válido (0-9 apenas)

Função: int validar_expressao(const char *expr);
*/

/*
EXERCÍCIO 4.2 - Avançado (Todas as estruturas)
Crie um SIMULADOR DE ESTACIONAMENTO.
Requisitos:
  - Máximo 10 vagas
  - Entrada (fila) e saída (fila)
  - Placa do carro, hora entrada, hora saída
  - Liberar vaga quando sai
  - Calcular tempo de permanência
  - Listar carros estacionados
  - Histórico de saídas (usar lista)
*/

/*
EXERCÍCIO 4.3 - Avançado (Listas + Pilha + Fila)
Implemente um JOGO DE CARTAS SIMPLES:
  - Monte (pilha de compra)
  - Descarte (pilha)
  - Mão do jogador (lista)
  - Fila de oponentes esperando
  
Ações:
  - Comprar carta do monte
  - Descartar carta
  - Passar
*/

// ============================================================
// DICAS DE IMPLEMENTAÇÃO
// ============================================================

/*
DICAS GERAIS:
1. Sempre verificar se malloc() retornou NULL
2. Sempre liberar memória com free()
3. Testar com listas vazias
4. Testar com listas com 1 elemento
5. Usar printf() para debug

PADRÃO DE CÓDIGO:
- Usar typedef para structs
- Funções retornam novo apontador (pode mudar cabeça)
- Comentar o que cada função faz
- Testar no main() antes de usar em outro lugar

COMPILAR:
gcc -o arquivo_teste arquivo.c
./arquivo_teste

VALGRIND (verificar vazamento de memória):
valgrind --leak-check=full ./arquivo_teste
*/

// ============================================================
// GABARITO PARCIAL (Uncomment para ver dicas)
// ============================================================

/*
EXERCÍCIO 1.1 - Inverter Lista
Pseudocódigo:
  1. Criar uma pilha vazia
  2. Percorrer a lista e fazer push de cada valor
  3. Fazer pop da pilha e criar nova lista

EXERCÍCIO 2.1 - Decimal para Binário
Pseudocódigo:
  1. Enquanto número > 0:
       a. pilha.push(número % 2)
       b. número = número / 2
  2. Enquanto pilha não vazia:
       a. print(pilha.pop())

EXERCÍCIO 3.2 - DEQUE
Use lista duplamente encadeada para facilitar insert/remove nas duas pontas
*/

// ============================================================
// COMO USAR ESTE ARQUIVO
// ============================================================

/*
1. Escolha um exercício
2. Abra um novo arquivo .c (ex: exercicio_1_1.c)
3. Implemente a solução
4. Compile: gcc -o exercicio_1_1 exercicio_1_1.c
5. Teste: ./exercicio_1_1
6. Se precisar de ajuda, revise os arquivos de exemplo

ORDEM RECOMENDADA:
- Comece com exercícios 1.1, 1.2 (básicos)
- Depois 2.1, 3.1 (básicos de pilha e fila)
- Depois exercícios intermediários
- Por fim, os avançados

BOA SORTE NOS ESTUDOS! 📚💻
*/
