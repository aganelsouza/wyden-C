# Tempo de Vida e Escopo de Variáveis em C

## Introdução

O **escopo** define onde uma variável pode ser acessada no código, enquanto o **tempo de vida** (lifetime) define por quanto tempo a variável existe na memória durante a execução do programa. Esses dois conceitos são fundamentais para escrever código seguro e eficiente em C.

---

## 1. Classes de Armazenamento

A classe de armazenamento determina o tempo de vida e o escopo de uma variável. Em C, existem 4 classes de armazenamento:

### 1.1 `auto` (Automático)

- **Padrão** para variáveis locais
- **Escopo**: Local ao bloco onde foi declarada
- **Tempo de vida**: Desde a declaração até o final do bloco
- **Memória**: Stack (pilha)
- **Valor inicial**: Indeterminado (lixo de memória)

```c
#include <stdio.h>

void exemplo_auto() {
    auto int x = 10;  // 'auto' é implícito, pode ser omitido
    printf("x = %d\n", x);

    {
        auto int y = 20;  // Novo escopo
        printf("y = %d\n", y);
    }

    // printf("y = %d\n", y);  // ERRO: y não existe aqui
}

int main() {
    exemplo_auto();
    return 0;
}
```

### 1.2 `static` (Estático)

- **Escopo**: Local ao bloco (variável estática local) ou global (variável estática global)
- **Tempo de vida**: Permanente, do início ao fim do programa
- **Memória**: Data segment (segmento de dados)
- **Valor inicial**: Zero (0, 0.0, '\0', etc)
- **Características**: Retém seu valor entre chamadas da função

```c
#include <stdio.h>

void contador() {
    static int chamadas = 0;  // Inicializada apenas uma vez
    chamadas++;
    printf("Função chamada %d vezes\n", chamadas);
}

int main() {
    contador();  // Imprime: 1
    contador();  // Imprime: 2
    contador();  // Imprime: 3
    return 0;
}
```

**Variável estática global:**

```c
static int variavel_privada = 100;  // Acessível apenas neste arquivo

void funcao() {
    printf("%d\n", variavel_privada);
}
```

### 1.3 `register` (Registrador)

- **Escopo**: Local ao bloco
- **Tempo de vida**: Até o final do bloco
- **Memória**: Registrador da CPU (sugestão ao compilador)
- **Valor inicial**: Indeterminado
- **Nota**: O compilador pode ignorar essa sugestão

```c
#include <stdio.h>

int exemplo_register() {
    register int i;  // Sugestão: armazenar em registrador para velocidade

    for (i = 0; i < 1000000; i++) {
        // Loop rápido
    }

    return i;
}

int main() {
    printf("Resultado: %d\n", exemplo_register());
    return 0;
}
```

**⚠️ Nota importante**: Com otimizações modernas do compilador, `register` raramente é necessário.

### 1.4 `extern` (Externo)

- **Escopo**: Global, acessível em múltiplos arquivos
- **Tempo de vida**: Do início ao fim do programa
- **Memória**: Data segment
- **Valor inicial**: Zero (para variáveis externas)
- **Uso**: Declaração em outro arquivo de uma variável definida em outro arquivo

**arquivo1.c**

```c
int contador_global = 0;  // Definição
```

**arquivo2.c**

```c
extern int contador_global;  // Declaração (usa a variável de arquivo1.c)

void incrementa() {
    contador_global++;
}
```

---

## 2. Escopo das Variáveis

### 2.1 Escopo Global

Uma variável global é acessível em qualquer função do programa.

```c
#include <stdio.h>

// Escopo global - acessível em qualquer lugar
int variavel_global = 100;

void funcao1() {
    printf("Na funcao1: %d\n", variavel_global);
}

void funcao2() {
    printf("Na funcao2: %d\n", variavel_global);
}

int main() {
    printf("Na main: %d\n", variavel_global);
    funcao1();
    funcao2();

    variavel_global = 200;  // Modificar variável global

    funcao1();  // Imprime novo valor
    return 0;
}
```

**Características:**

- Inicializada automaticamente com zero
- Permanece em memória durante toda execução
- Pode ser acessada e modificada de qualquer função
- Use com cuidado (dificulta leitura e testes)

### 2.2 Escopo Local (ou de Bloco)

Uma variável local é acessível apenas dentro do bloco onde foi declarada.

```c
#include <stdio.h>

void exemplo_escopo_local() {
    int x = 10;  // Escopo: função inteira

    printf("x antes do bloco: %d\n", x);

    {
        int x = 20;  // Novo x com escopo local ao bloco
        printf("x dentro do bloco: %d\n", x);  // Imprime 20
    }

    printf("x após o bloco: %d\n", x);  // Imprime 10 (volta ao x anterior)
}

int main() {
    exemplo_escopo_local();
    return 0;
}
```

**Shadow (Sombreamento):**

```c
int x = 5;  // Global

void funcao() {
    int x = 10;  // Local (esconde a global)
    printf("%d\n", x);  // Imprime 10
}

int main() {
    funcao();  // Imprime 10
    printf("%d\n", x);  // Imprime 5 (global)
    return 0;
}
```

### 2.3 Escopo de Bloco

Qualquer bloco `{ }` cria um novo escopo.

```c
#include <stdio.h>

int main() {
    int a = 1;
    printf("a = %d\n", a);

    {
        int b = 2;
        printf("b = %d\n", b);

        {
            int c = 3;
            printf("c = %d\n", c);
        }

        // printf("c = %d\n", c);  // ERRO: c fora de escopo
    }

    // printf("b = %d\n", b);  // ERRO: b fora de escopo

    return 0;
}
```

### 2.4 Escopo de Função

As funções têm escopo global (seu nome é visível globalmente).

```c
#include <stdio.h>

// Declaração antecipada (forward declaration)
void funcao_a();
void funcao_b();

int main() {
    funcao_a();  // Pode chamar mesmo antes de definir
    funcao_b();
    return 0;
}

void funcao_a() {
    printf("Função A\n");
    funcao_b();  // Podem chamar uma à outra
}

void funcao_b() {
    printf("Função B\n");
}
```

---

## 3. Tempo de Vida das Variáveis

### 3.1 Tempo de Vida Estático

**Variáveis**: `static`, `extern`, globais
**Duração**: Desde o carregamento do programa até o encerramento
**Valor inicial**: Zero

```c
#include <stdio.h>

int global = 0;              // Tempo de vida: programa inteiro
static int global_privado;   // Tempo de vida: programa inteiro

int main() {
    printf("global: %d\n", global);           // 0
    printf("global_privado: %d\n", global_privado);  // 0
    return 0;
}
```

### 3.2 Tempo de Vida Automático

**Variáveis**: `auto` (padrão para locais)
**Duração**: Desde a declaração até o final do bloco
**Valor inicial**: Indeterminado

```c
#include <stdio.h>

void exemplo_tempo_vida() {
    {
        int x = 10;  // x criada aqui
        printf("x = %d\n", x);
    }  // x destruída aqui, memória liberada

    {
        int x = 20;  // Novo x em nova locação de memória
        printf("x = %d\n", x);
    }  // x destruída aqui
}

int main() {
    exemplo_tempo_vida();
    return 0;
}
```

### 3.3 Tempo de Vida de Variável Estática Local

**Características especiais:**

- Criada na primeira vez que a função é chamada
- Mantém seu valor entre chamadas
- Destruída quando o programa termina

```c
#include <stdio.h>

void funcao() {
    static int contador = 0;  // Criada apenas uma vez
    contador++;
    printf("Contador: %d\n", contador);
}

int main() {
    funcao();  // Contador: 1
    funcao();  // Contador: 2
    funcao();  // Contador: 3
    funcao();  // Contador: 4
    return 0;
}
```

---

## 4. Comparação: escopo vs Tempo de Vida

| Característica      | Escopo                     | Tempo de Vida                          |
| ------------------- | -------------------------- | -------------------------------------- |
| **Define**          | Onde variável é acessível  | Por quanto tempo existe                |
| **Relacionado a**   | Espaço (linhas do código)  | Tempo (execução)                       |
| **Determinado por** | `{ }` blocos, global/local | Classe de armazenamento                |
| **Exemplo**         | Variável visível na função | Variável existe enquanto programa roda |

**Exemplo ilustrativo:**

```c
void funcao() {
    // Escopo: função inteira
    // Tempo de vida: enquanto função está sendo executada
    int local = 10;
}

static int global = 0;  // Escopo: global
                        // Tempo de vida: programa inteiro
```

---

## 5. Diagrama de Escopo e Tempo de Vida

```
GLOBAL (acessível de qualquer lugar)
┌─────────────────────────────────────┐
│ int global = 0;                     │  Tempo de vida: Programa inteiro
│                                     │
│ void funcao() {                     │
│   // LOCAL (apenas nesta função)    │
│   {                                 │
│     int x = 10;                     │  Tempo de vida: Enquanto no bloco
│     // ACESSÍVEL AQUI               │
│   }                                 │
│   // NÃO ACESSÍVEL AQUI             │
│ }                                   │
│                                     │
│ int main() {                        │
│   funcao();                         │
│   return 0;                         │
│ }                                   │
└─────────────────────────────────────┘
```

---

## 6. Exemplo Prático Completo

```c
#include <stdio.h>

// ESCOPO GLOBAL, TEMPO ESTÁTICO
int contador_global = 0;

// ESCOPO GLOBAL (privado), TEMPO ESTÁTICO
static int contador_privado = 0;

void exibir_status() {
    // ESCOPO LOCAL, TEMPO AUTOMÁTICO
    printf("Função chamada\n");

    // ESCOPO LOCAL, TEMPO ESTÁTICO
    static int chamadas = 0;
    chamadas++;

    printf("  Chamadas dessa função: %d\n", chamadas);
    printf("  Contador global: %d\n", contador_global);
}

void incrementar() {
    // ESCOPO LOCAL, TEMPO AUTOMÁTICO
    {
        int x = 100;  // Acessível apenas aqui
        contador_global += x;
    }

    contador_privado++;
}

int main() {
    printf("=== ANTES ===\n");
    printf("contador_global: %d\n", contador_global);
    exibir_status();

    printf("\n=== INCREMENTANDO ===\n");
    incrementar();
    exibir_status();

    incrementar();
    exibir_status();

    printf("\n=== FINAL ===\n");
    printf("contador_global: %d\n", contador_global);

    return 0;
}
```

---

## 7. Boas Práticas

### ✅ Faça:

- **Minimize variáveis globais** - Use escopo local sempre que possível
- **Use `static` para privacidade** - Variáveis estáticas globais são privadas ao arquivo
- **Declare próximo ao uso** - Declare variáveis perto de onde serão usadas
- **Inicialize sempre** - Não confie em valores padrão indeterminados

```c
// BOM: Escopo local, inicializado
void funcao() {
    int x = 0;
    // usar x
}
```

### ❌ Evite:

- **Globais desnecessárias** - Difíceis de rastrear e debugar
- **Shadowing** - Reutilizar nomes em escopos aninhados
- **Dependência de ordem** - Confiar em inicialização de globais

```c
// RUIM: Escopo global, não inicializado
int x;  // Qual é o valor inicial?
void funcao() {
    x = 10;
}
```

---

## 8. Tabela de Resumo das Classes de Armazenamento

| Classe            | Escopo           | Tempo de Vida         | Memória         | Inicialização |
| ----------------- | ---------------- | --------------------- | --------------- | ------------- |
| `auto`            | Local            | Automático            | Stack           | Indeterminada |
| `static` (local)  | Local (bloco)    | Estático (permanente) | Data segment    | Zero (0)      |
| `static` (global) | Global (privado) | Estático (permanente) | Data segment    | Zero (0)      |
| `extern`          | Global           | Estático (permanente) | Data segment    | Zero (0)      |
| `register`        | Local            | Automático            | Registrador CPU | Indeterminada |

---

## 9. Exemplos de Erros Comuns

### Erro 1: Acessar variável fora do escopo

```c
void funcao() {
    int x = 10;
}

int main() {
    printf("%d\n", x);  // ERRO! x não existe em main
    return 0;
}
```

### Erro 2: Usar variável não inicializada

```c
void funcao() {
    int x;  // Contém lixo na memória
    printf("%d\n", x);  // Valor indeterminado!
}
```

### Erro 3: Sombreamento inadvertido

```c
int valor = 100;  // Global

void funcao() {
    int valor = 50;  // LOCAL (esconde global)
    printf("%d\n", valor);  // Imprime 50
}

int main() {
    funcao();
    printf("%d\n", valor);  // Imprime 100
    return 0;
}
```

### Erro 4: Modificar estáticas por acidente

```c
void incrementar() {
    static int contador = 0;
    contador++;
}

void resetar() {
    static int contador = 0;  // NOVO contador! Não é o mesmo da outra função
}

// Solução: usar funções bem definidas
```

---

## 10. Dicas de Debugging

### Para entender tempo de vida:

```c
#include <stdio.h>

void demonstrar() {
    int x = 10;
    printf("Endereço de x: %p\n", (void*)&x);
}

int main() {
    demonstrar();  // x em um endereço
    demonstrar();  // x em OUTRO endereço (nova alocação)
    return 0;
}
```

### Para entender escopo:

```c
void funcao() {
    printf("Você está em funcao\n");
    // Variáveis dessa função
}

// variáveis de funcao NÃO existem aqui
```

---

## Conclusão

- **Escopo** = "Onde posso usar essa variável?"
- **Tempo de Vida** = "Por quanto tempo essa variável existe?"

Compreender esses conceitos é essencial para:

- ✅ Evitar conflitos de nomes
- ✅ Gerenciar memória eficientemente
- ✅ Escrever código seguro e mantível
- ✅ Debugar problemas mais facilmente
