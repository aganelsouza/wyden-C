# Bibliotecas e Arquivos de Cabeçalho em C

## 1. O que é um Arquivo de Cabeçalho?

Um arquivo de cabeçalho (header file) é um arquivo de texto com extensão `.h` que contém **declarações** de funções, tipos de dados, constantes e macros. Ele funciona como uma "interface" entre diferentes partes do programa, permitindo que o compilador saiba quais funções e tipos estão disponíveis.

### Estrutura Básica

```c
// arquivo.h
#ifndef ARQUIVO_H
#define ARQUIVO_H

// Declarações de funções
int somar(int a, int b);
void exibir_mensagem(char *msg);

#endif
```

---

## 2. Tipos de Bibliotecas

### 2.1 Bibliotecas Padrão (Standard Library)

Incluídas no compilador C. Você não precisa criar, apenas usar com `#include`.

#### `<stdio.h>` - Entrada/Saída Padrão

```c
#include <stdio.h>

printf("Olá\n");           // Exibir
scanf("%d", &variavel);    // Ler
```

**Funções principais:**

- `printf()` - Escrever formatado
- `scanf()` - Ler formatado
- `gets()` / `fgets()` - Ler string
- `puts()` / `fputs()` - Escrever string
- `getchar()` / `putchar()` - Caractere
- `fopen()`, `fclose()`, `fread()` - Arquivos

#### `<stdlib.h>` - Utilidades Padrão

```c
#include <stdlib.h>

int *ptr = malloc(10 * sizeof(int));  // Alocação dinâmica
free(ptr);                             // Liberar memória
```

**Funções principais:**

- `malloc()` - Alocação de memória
- `calloc()` - Alocação inicializada com zero
- `realloc()` - Redimensionar blocos
- `free()` - Liberar memória
- `atoi()`, `atof()` - Conversão string
- `rand()`, `srand()` - Números aleatórios
- `exit()` - Encerrar programa
- `system()` - Executar comando do sistema

#### `<string.h>` - Manipulação de Strings

```c
#include <string.h>

strcpy(dest, origen);          // Copiar string
strlen(str);                   // Tamanho da string
strcmp(str1, str2);            // Comparar strings
strcat(str1, str2);            // Concatenar
strchr(str, 'a');              // Encontrar caractere
```

**Funções principais:**

- `strlen()` - Comprimento
- `strcpy()` / `strncpy()` - Copiar
- `strcat()` / `strncat()` - Concatenar
- `strcmp()` / `strncmp()` - Comparar
- `strchr()` / `strstr()` - Procurar
- `sprintf()` - String formatada

#### `<math.h>` - Operações Matemáticas

```c
#include <math.h>

sqrt(16);      // Raiz quadrada = 4
pow(2, 3);     // Potência = 8
sin(M_PI);     // Seno = 0
cos(0);        // Cosseno = 1
abs(-5);       // Valor absoluto = 5
ceil(3.2);     // Arredondar acima = 4
floor(3.9);    // Arredondar abaixo = 3
```

**Funções principais:**

- `sqrt(x)` - Raiz quadrada
- `pow(x, y)` - Potência
- `sin()`, `cos()`, `tan()` - Trigonometria
- `exp()`, `log()` - Exponencial/Logaritmo
- `abs()` - Valor absoluto
- `ceil()`, `floor()` - Arredondamento
- `M_PI`, `M_E` - Constantes

#### `<time.h>` - Data e Hora

```c
#include <time.h>

time_t agora = time(NULL);
struct tm *tempo = localtime(&agora);
printf("%d:%d:%d\n", tempo->tm_hour, tempo->tm_min, tempo->tm_sec);
```

**Funções principais:**

- `time()` - Tempo atual
- `localtime()` - Tempo local
- `gmtime()` - Tempo GMT
- `strftime()` - Formatar tempo
- `clock()` - Tempo de processador

#### `<ctype.h>` - Classificação de Caracteres

```c
#include <ctype.h>

isdigit('5');      // true
isalpha('a');      // true
isspace(' ');      // true
isupper('A');      // true
tolower('A');      // 'a'
toupper('a');      // 'A'
```

#### `<limits.h>` - Limites de Tipos

```c
#include <limits.h>

INT_MAX         // Máximo inteiro
INT_MIN         // Mínimo inteiro
CHAR_MAX        // Máximo char
FLOAT_MAX       // Máximo float
```

#### `<assert.h>` - Asserções

```c
#include <assert.h>

assert(x > 0);  // Se false, programa aborta
```

#### `<stdbool.h>` - Tipo Booleano

```c
#include <stdbool.h>

bool resultado = true;
bool ativo = false;
```

---

## 3. Criando Suas Próprias Bibliotecas

### 3.1 Estrutura de um Header Personalizado

**minha_biblioteca.h**

```c
#ifndef MINHA_BIBLIOTECA_H
#define MINHA_BIBLIOTECA_H

// Constantes
#define MAXIMO 100
#define PI 3.14159

// Tipos estruturados
typedef struct {
    char nome[50];
    int idade;
    float altura;
} Pessoa;

// Declarações de funções
int somar(int a, int b);
int subtrair(int a, int b);
void imprimir_pessoa(Pessoa p);

#endif
```

**minha_biblioteca.c**

```c
#include "minha_biblioteca.h"
#include <stdio.h>

// Implementação das funções
int somar(int a, int b) {
    return a + b;
}

int subtrair(int a, int b) {
    return a - b;
}

void imprimir_pessoa(Pessoa p) {
    printf("Nome: %s\n", p.nome);
    printf("Idade: %d\n", p.idade);
    printf("Altura: %.2f\n", p.altura);
}
```

**programa.c** (usando a biblioteca)

```c
#include <stdio.h>
#include "minha_biblioteca.h"

int main() {
    int resultado = somar(5, 3);
    printf("5 + 3 = %d\n", resultado);

    Pessoa joao;
    strcpy(joao.nome, "João");
    joao.idade = 25;
    joao.altura = 1.80;

    imprimir_pessoa(joao);

    return 0;
}
```

### 3.2 Guard de Inclusão (Include Guards)

Previne que um arquivo seja incluído múltiplas vezes:

```c
#ifndef MINHA_BIBLIOTECA_H
#define MINHA_BIBLIOTECA_H

// Conteúdo do header

#endif
```

**Alternativa moderna (C99+):**

```c
#pragma once

// Conteúdo do header
```

---

## 4. Diferença entre #include com < > e " "

### `#include <header.h>` (Colchetes)

- Procura em **diretórios do sistema**
- Usado para **bibliotecas padrão**
- Busca em locais predefinidos do compilador

```c
#include <stdio.h>      // Biblioteca padrão
#include <stdlib.h>     // Biblioteca padrão
#include <math.h>       // Biblioteca padrão
```

### `#include "header.h"` (Aspas)

- Procura no **diretório atual** primeiro
- Depois procura nos diretórios do sistema
- Usado para **headers próprios**

```c
#include "minha_biblioteca.h"    // Header pessoal
#include "utils.h"                // Header pessoal
```

---

## 5. Estrutura de Projeto

### Layout Recomendado

```
projeto/
│
├── include/              # Headers (.h)
│   ├── minha_lib.h
│   └── utils.h
│
├── src/                  # Implementações (.c)
│   ├── minha_lib.c
│   ├── utils.c
│   └── main.c
│
└── Makefile              # Compilação automática
```

### Compilação

```bash
gcc -I./include -o programa src/main.c src/minha_lib.c src/utils.c
```

---

## 6. Funções vs Headers

### Função

- Implementação de uma ação
- Definida uma única vez
- Pode ser chamada múltiplas vezes

```c
// minha_lib.c
int dobrar(int x) {
    return x * 2;
}
```

### Header

- Declaração da função (interface)
- Permite que outras arquivos usem a função

```c
// minha_lib.h
int dobrar(int x);  // Apenas declaração
```

---

## 7. Exemplo Completo: Biblioteca de Calculadora

**calculadora.h**

```c
#ifndef CALCULADORA_H
#define CALCULADORA_H

// Operações básicas
int adicionar(int a, int b);
int subtrair(int a, int b);
int multiplicar(int a, int b);
float dividir(int a, int b);

// Operações avançadas
int potencia(int base, int expoente);
int modulo(int a, int b);

#endif
```

**calculadora.c**

```c
#include "calculadora.h"

int adicionar(int a, int b) {
    return a + b;
}

int subtrair(int a, int b) {
    return a - b;
}

int multiplicar(int a, int b) {
    return a * b;
}

float dividir(int a, int b) {
    if (b == 0) return 0;
    return (float)a / b;
}

int potencia(int base, int expoente) {
    int resultado = 1;
    for (int i = 0; i < expoente; i++) {
        resultado *= base;
    }
    return resultado;
}

int modulo(int a, int b) {
    return a % b;
}
```

---

## 8. Boas Práticas

### ✅ Faça:

- Use guards de inclusão ou `#pragma once`
- Reúna declarações relacionadas no mesmo header
- Nomeie headers descritivamente
- Comente as funções no header
- Separe interface (`.h`) de implementação (`.c`)

### ❌ Evite:

- Incluir headers desnecessários
- Colocar implementação completa no arquivo `.h`
- Usar nomes genéricos como `lib.h`
- Circular includes (A.h inclui B.h que inclui A.h)
- Incluir arquivos `.c`

---

## 9. Circular Includes

**Problema:**

```c
// a.h
#include "b.h"
typedef struct { int x; } A;

// b.h
#include "a.h"
typedef struct { A a; } B;
```

**Solução: Forward Declaration**

```c
// a.h
typedef struct B B;  // Declaração antecipada
typedef struct { int x; } A;

// b.h
#include "a.h"
typedef struct { A a; } B;
```

---

## 10. Resumo das Principais Bibliotecas

| Header        | Função                      |
| ------------- | --------------------------- |
| `<stdio.h>`   | Entrada/saída               |
| `<stdlib.h>`  | Alocação, conversão         |
| `<string.h>`  | Manipulação de strings      |
| `<math.h>`    | Operações matemáticas       |
| `<ctype.h>`   | Classificação de caracteres |
| `<time.h>`    | Data e hora                 |
| `<stdint.h>`  | Tipos inteiros específicos  |
| `<limits.h>`  | Limites de tipos            |
| `<stdbool.h>` | Tipo booleano               |
| `<assert.h>`  | Asserções                   |

---

## 11. Exemplo de Uso Integrado

```c
#include <stdio.h>           // E/S
#include <stdlib.h>          // Utilitários
#include <string.h>          // Strings
#include <math.h>            // Matemática
#include "calculadora.h"     // Pessoal

int main() {
    // Usando header pessoal
    int soma = adicionar(10, 5);
    printf("10 + 5 = %d\n", soma);

    // Usando biblioteca padrão
    char resultado[50];
    sprintf(resultado, "Resultado: %d", soma);
    printf("%s\n", resultado);

    // Usando math.h
    double raiz = sqrt(16);
    printf("Raiz de 16: %.2f\n", raiz);

    return 0;
}
```

---

## Conclusão

- **Headers** são interfaces entre código
- **Bibliotecas padrão** já vêm com o compilador
- **Headers pessoais** organizam seu projeto
- **Separe interface de implementação**
- **Use guards para evitar duplicação**
