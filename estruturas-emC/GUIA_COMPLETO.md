# 📚 Estruturas de Dados em C - Guia Completo

## 📂 Arquivos Criados

```
estruturas de dados em c/
├── lista_ponteiros.c                    (Arquivo original)
├── lista_ponteiros_completo.c           ✅ LISTA LINEAR + CIRCULAR
├── lista_duplamente_encadeada.c         ✅ LISTA DUPLA LINEAR
├── lista_dupla_circular.c               ✅ LISTA DUPLA CIRCULAR
├── pilha.c                              ✅ PILHA (Array + Lista)
├── fila.c                               ✅ FILA (Array + Lista)
├── exemplos_praticos.c                  ✅ APLICAÇÕES REAIS
├── EXERCICIOS_PROPOSTOS.c               📝 PROPOSTAS DE EXERCÍCIOS
└── GUIA_COMPLETO.md                     📖 ESTE ARQUIVO
```

---

## 🎯 Estruturas Implementadas

### 1️⃣ Lista Encadeada Linear (lista_ponteiros_completo.c)

```c
typedef struct no {
    int valor;
    struct no *proximo;  // Aponta só para o próximo
} no;
```

**Visualização:** `1 -> 2 -> 3 -> NULL`

**Operações:**

- ✅ Inserir início/fim
- ✅ Remover elemento
- ✅ Exibir lista
- ✅ Liberar memória

---

### 2️⃣ Lista Encadeada Circular (lista_ponteiros_completo.c)

```c
typedef struct no_circular {
    int valor;
    struct no_circular *proximo;  // O último aponta para o primeiro
} no_circular;
```

**Visualização:** `1 -> 2 -> 3 -> 1 (volta ao início)`

**Características:**

- ⚠️ Não tem NULL no final
- ⚠️ Risco de loop infinito ao percorrer
- ✅ Útil para sistemas cíclicos (rodas, playlists)

---

### 3️⃣ Lista Duplamente Encadeada (lista_duplamente_encadeada.c)

```c
typedef struct no_duplo {
    int valor;
    struct no_duplo *proximo;   // Próximo
    struct no_duplo *anterior;  // Anterior
} no_duplo;
```

**Visualização:** `NULL <- 1 <-> 2 <-> 3 -> NULL`

**Vantagens:**

- ✅ Percorrer para frente E para trás
- ✅ Inserir antes de um elemento
- ❌ Usa mais memória (2 ponteiros)

---

### 4️⃣ Lista Duplamente Encadeada Circular (lista_dupla_circular.c)

```c
typedef struct no_duplo_circ {
    int valor;
    struct no_duplo_circ *proximo;
    struct no_duplo_circ *anterior;
} no_duplo_circ;
```

**Visualização:** `... <- 1 <-> 2 <-> 3 <-> ... (loop)`

**Aplicações:**

- 🎵 Reprodutor de música com repetição
- 🎡 Estruturas de carrossel
- 🔄 Sistemas de agendamento circular

---

### 5️⃣ Pilha - LIFO (Last In, First Out) (pilha.c)

```c
typedef struct {
    int dados[TAM_MAX];
    int topo;  // Índice do topo
} pilha_array;
```

**Visualização:**

```
     [40] <- Topo
     [30]
     [20]
[10] <- Base
```

**Operações:**

- `push(x)` - Adiciona no topo
- `pop()` - Remove o topo
- `peek()` - Vê o topo sem remover

**Aplicações Clássicas:**

- 🔙 Desfazer (Undo/Redo)
- 📞 Pilha de chamadas de função
- 🔗 Validação de parênteses
- 🔢 Conversão de bases (decimal → binário)
- 📐 Avaliação de expressões matemáticas

**Exemplo - Parênteses Balanceados:**

```
"((a + b) * (c - d))"  → ✅ VÁLIDA
"((a + b) * c - d))"   → ❌ INVÁLIDA
```

---

### 6️⃣ Fila - FIFO (First In, First Out) (fila.c)

```c
typedef struct {
    int dados[TAM_MAX];
    int inicio;  // Índice do início
    int fim;     // Índice do fim
    int tamanho;
} fila_array;
```

**Visualização:**

```
Entrada → [1] [2] [3] [4] [5] → Saída
          ↑                      ↑
        Inicio                  Fim
```

**Operações:**

- `enqueue(x)` - Adiciona no final
- `dequeue()` - Remove do início
- `peek()` - Vê o primeiro

**Aplicações Clássicas:**

- 🏥 Fila de hospital
- 🏪 Fila de supermercado
- 📋 Impressora (fila de documentos)
- 🎮 Processamento em lote
- 🚗 Sistema de semáforos

**Exemplo - Fila de Caixa:**

```
Clientes: 100 → 200 → 300 → 400 → 500
          ↑ (sendo atendido)

Atendimento:
Cliente 100 atendido!  (sai da fila)
Cliente 200 sendo atendido...
```

---

## 🔄 Diferenças Principais

| Estrutura        | Acesso   | Inserção | Remoção | Uso          |
| ---------------- | -------- | -------- | ------- | ------------ |
| **Lista Linear** | O(n)     | O(1)\*   | O(n)    | Geral        |
| **Lista Dupla**  | O(n)     | O(1)\*   | O(1)\*  | Bidirecional |
| **Pilha**        | O(1)\*\* | O(1)     | O(1)    | LIFO         |
| **Fila**         | O(1)\*\* | O(1)     | O(1)    | FIFO         |

\*com apontador | **topo/início | \*** depende do contexto

---

## 💻 Como Compilar e Executar

### Compilar:

```bash
gcc -o nome_saida arquivo.c
```

### Executar:

```bash
./nome_saida          # Linux/Mac
.\nome_saida.exe      # Windows
```

### Exemplo Completo:

```bash
cd "estruturas de dados em c"
gcc -o meu_teste lista_ponteiros_completo.c
./meu_teste
```

---

## 🧪 Testando para Vazamento de Memória (Linux/Mac)

```bash
valgrind --leak-check=full ./meu_teste
```

---

## 📝 Roteiro de Estudo Recomendado

### Semana 1: Listas

1. ✅ Lista Linear (inicio)
2. ✅ Lista Linear (operações completas)
3. ✅ Lista Circular
4. ✅ Lista Duplamente Encadeada

### Semana 2: Pilha e Fila

1. ✅ Pilha com Array
2. ✅ Pilha com Lista
3. ✅ Aplicação: Validação de Parênteses
4. ✅ Fila com Array
5. ✅ Fila com Lista

### Semana 3: Exercícios

- 📝 Fazer exercícios propostos
- 🔧 Combinar estruturas
- 🎯 Problemas do mundo real

---

## 🎓 Conceitos Importantes

### Apontadores (Ponteiros)

```c
int x = 10;
int *p = &x;      // Apontador para x
printf("%d", *p);  // Dereferencing: imprime 10
```

### Alocação Dinâmica

```c
int *arr = (int *)malloc(sizeof(int) * 10);  // Aloca
free(arr);  // Libera
```

### Estruturas (struct)

```c
typedef struct no {
    int valor;
    struct no *proximo;
} no;  // Pode usar "no" ao invés de "struct no"
```

### Passagem por Referência

```c
void inserir(no **cabeca, int valor) {
    *cabeca = novo;  // Modifica a cabeça original
}
```

---

## 🚀 Próximos Passos

1. **Implementar Busca em Listas:**
   - Busca linear simples
   - Busca binária (em lista ordenada)

2. **Implementar Ordenação:**
   - Bubble sort
   - Insertion sort
   - Quick sort (com recursão)

3. **Estruturas Avançadas:**
   - Árvores (binária, AVL, vermelho-preto)
   - Grafos
   - Tabelas hash

4. **Algoritmos:**
   - Busca em profundidade (DFS)
   - Busca em largura (BFS)
   - Dijkstra (caminho mínimo)

---

## ❓ Dúvidas Comuns

**P: Por que usar `typedef`?**
R: Facilita usar `no` ao invés de `struct no`

**P: Quando usar pilha vs fila?**
R: Pilha = último chegou é o primeiro a sair | Fila = primeiro chegou é o primeiro a sair

**P: Como evitar vazamento de memória?**
R: Sempre usar `free()` para cada `malloc()` feito

**P: Posso usar array ao invés de lista encadeada?**
R: Sim, mas arrays:

- ✅ Acesso mais rápido (O(1))
- ❌ Tamanho fixo
- ❌ Inserção/remoção no meio é lento (O(n))

**P: Como testar meu código?**
R: Adicione `printf()` estrategicamente para debug

---

## 📚 Referências e Recursos

- **Livro:** "Estruturas de Dados" - Waldemar Celes
- **Online:** GeeksforGeeks - Data Structures in C
- **Prática:** LeetCode (problemas de estruturas de dados)

---

## ✅ Checklist de Aprendizado

- [ ] Entendo ponteiros e alocação dinâmica
- [ ] Sei implementar lista linear
- [ ] Sei implementar lista circular
- [ ] Sei implementar lista dupla
- [ ] Sei implementar pilha
- [ ] Sei implementar fila
- [ ] Consigo fazer exercício 1.1 (inverter lista)
- [ ] Consigo fazer exercício 2.1 (decimal para binário)
- [ ] Consigo fazer exercício 3.1 (fila de banco)
- [ ] Entendo quando usar cada estrutura

---

## 🎉 Bom Estudo!

Qualquer dúvida, revise os arquivos `.c` que têm exemplos comentados!

**Dica Final:** Comece pequeno, teste sempre, e vá incrementando a complexidade gradualmente! 💪
