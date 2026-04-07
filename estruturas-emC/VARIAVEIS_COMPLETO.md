# Guia Completo sobre Variáveis em C

## 1. O que é uma Variável?

Uma variável é um espaço na memória do computador que armazena um valor e possui um nome para referenciá-lo. Toda variável tem:

- **Nome**: identificador único
- **Tipo**: define o tipo de dado que armazena
- **Valor**: o conteúdo armazenado
- **Endereço**: localização na memória

## 2. Declaração de Variáveis

### Sintaxe Básica

```c
tipo nome_da_variavel;
tipo nome1, nome2, nome3;  // Múltiplas variáveis do mesmo tipo
```

### Exemplo

```c
int idade;           // Declara uma variável inteira
float altura;        // Declara uma variável real
char letra;          // Declara um caractere
```

## 3. Tipos de Dados Primitivos

### 3.1 Tipo Inteiro (int)

```c
int numero = 42;           // Inteiro comum (tipicamente 4 bytes)
short numero_curto = 100;  // Inteiro curto (2 bytes)
long numero_longo = 1000;  // Inteiro longo (4 ou 8 bytes)
```

- **Intervalo padrão**: -2.147.483.648 a 2.147.483.647
- **Tamanho**: 4 bytes (em sistemas de 32/64 bits)

### 3.2 Tipo Ponto Flutuante (float e double)

```c
float preco = 19.99f;           // 4 bytes
double temperatura = 36.5;      // 8 bytes (mais precisão)
long double valor = 999.999999; // 10-16 bytes
```

- **float**: ~6-7 dígitos de precisão
- **double**: ~15-16 dígitos de precisão

### 3.3 Tipo Caractere (char)

```c
char letra = 'A';       // Um caractere
char numero = '5';      // Número como caractere (ASCII)
char especial = '\n';   // Caractere especial
```

- **Tamanho**: 1 byte
- **Intervalo**: 0 a 255 (ou -128 a 127 se com sinal)

### 3.4 Tipo Booleano (bool)

```c
#include <stdbool.h>

bool condicao = true;   // true ou false
bool resultado = false;
```

### Tabela de Tipos e Tamanhos

```c
#include <stdio.h>

int main() {
    printf("int: %lu bytes\n", sizeof(int));
    printf("short: %lu bytes\n", sizeof(short));
    printf("long: %lu bytes\n", sizeof(long));
    printf("float: %lu bytes\n", sizeof(float));
    printf("double: %lu bytes\n", sizeof(double));
    printf("char: %lu bytes\n", sizeof(char));
    return 0;
}
```

## 4. Inicialização de Variáveis

### 4.1 Sem Inicialização

```c
int x;  // Contém lixo de memória (valor indeterminado)
```

### 4.2 Com Inicialização

```c
int x = 10;
float pi = 3.14f;
char inicial = 'J';
```

### 4.3 Inicialização Múltipla

```c
int a = 1, b = 2, c = 3;
float x = 1.5f, y = 2.5f;
```

### 4.4 Inicialização com Const

```c
const int MAXIMO = 100;      // Constante (não pode mudar)
const float PI = 3.14159f;
```

## 5. Modificadores de Tipo

### 5.1 signed e unsigned

```c
signed int numero = -50;      // Com sinal (padrão)
unsigned int quantidade = 100; // Sem sinal (apenas positivos)

// Intervalo sem sinal: 0 a 4.294.967.295
// Intervalo com sinal: -2.147.483.648 a 2.147.483.647
```

### Exemplo Prático

```c
#include <stdio.h>

int main() {
    signed int s = -50;
    unsigned int u = 50;

    printf("Signed: %d\n", s);
    printf("Unsigned: %u\n", u);

    return 0;
}
```

## 6. Escopo de Variáveis

### 6.1 Escopo Global

```c
#include <stdio.h>

int global = 10;  // Acessível em toda o programa

void funcao1() {
    printf("Global: %d\n", global);
}

int main() {
    printf("Global: %d\n", global);
    funcao1();
    return 0;
}
```

### 6.2 Escopo Local

```c
#include <stdio.h>

int main() {
    int local = 20;  // Acessível apenas dentro de main

    {
        int bloco = 30;  // Acessível apenas dentro deste bloco
        printf("Local: %d\n", local);
        printf("Bloco: %d\n", bloco);
    }

    // printf("Bloco: %d\n", bloco);  // ERRO: bloco não existe aqui

    return 0;
}
```

### 6.3 Escopo Estático (static)

```c
void contador() {
    static int x = 0;  // Inicializa uma única vez
    x++;
    printf("Contador: %d\n", x);  // 1, 2, 3, ... (mantém valor)
}

int main() {
    contador();  // Imprime 1
    contador();  // Imprime 2
    contador();  // Imprime 3
    return 0;
}
```

### 6.4 Extern (Variável Externa)

**arquivo1.c**

```c
int variavel_externa = 100;  // Definida aqui
```

**arquivo2.c**

```c
extern int variavel_externa;  // Declarada em outro arquivo

void usa_externa() {
    printf("%d\n", variavel_externa);
}
```

## 7. Operadores com Variáveis

### 7.1 Operadores Aritméticos

```c
int a = 10, b = 3;

int soma = a + b;        // 13
int diferenca = a - b;   // 7
int produto = a * b;     // 30
int quociente = a / b;   // 3 (divisão inteira)
int resto = a % b;       // 1 (módulo)
```

### 7.2 Operadores de Atribuição

```c
int x = 10;

x += 5;   // x = x + 5  → 15
x -= 3;   // x = x - 3  → 12
x *= 2;   // x = x * 2  → 24
x /= 4;   // x = x / 4  → 6
x %= 4;   // x = x % 4  → 2
```

### 7.3 Operadores de Incremento/Decremento

```c
int x = 5;

x++;   // x = 6 (pós-incremento)
++x;   // x = 7 (pré-incremento)
x--;   // x = 6 (pós-decremento)
--x;   // x = 5 (pré-decremento)
```

### Diferença Pré e Pós-incremento

```c
int x = 5;
int y;

y = x++;  // y = 5, depois x = 6
y = ++x;  // x = 7, depois y = 7
```

## 8. Entrada e Saída (I/O)

### 8.1 Leitura de Variáveis (scanf)

```c
#include <stdio.h>

int main() {
    int idade;
    float altura;
    char inicial;

    printf("Digite sua idade: ");
    scanf("%d", &idade);

    printf("Digite sua altura: ");
    scanf("%f", &altura);

    printf("Digite a inicial do seu nome: ");
    scanf(" %c", &inicial);  // Note o espaço antes de %c

    printf("Idade: %d, Altura: %.2f, Inicial: %c\n", idade, altura, inicial);

    return 0;
}
```

### 8.2 Formatadores printf

```c
int inteiro = 42;
float decimal = 3.14159f;
char letra = 'A';

printf("Inteiro: %d\n", inteiro);           // 42
printf("Inteiro (octal): %o\n", inteiro);   // 52
printf("Inteiro (hex): %x\n", inteiro);     // 2a
printf("Decimal: %f\n", decimal);           // 3.141590
printf("Decimal (2 casas): %.2f\n", decimal); // 3.14
printf("Caractere: %c\n", letra);           // A
printf("String: %s\n", "Olá");              // Olá
printf("Tamanho: %lu bytes\n", sizeof(int)); // Tamanho em bytes
```

## 9. Endereço de Memória e Operador &

### 9.1 Obtendo o Endereço

```c
#include <stdio.h>

int main() {
    int x = 10;

    printf("Valor de x: %d\n", x);
    printf("Endereço de x: %p\n", (void*)&x);
    printf("Tamanho de x: %lu bytes\n", sizeof(x));

    return 0;
}

// Saída possível:
// Valor de x: 10
// Endereço de x: 0x7fff5fbff8ac
// Tamanho de x: 4 bytes
```

## 10. Conversão de Tipos (Type Casting)

### 10.1 Conversão Implícita

```c
int inteiro = 5;
double resultado = inteiro;  // Automaticamente convertido para 5.0
```

### 10.2 Conversão Explícita

```c
double valor = 3.7;
int inteiro = (int)valor;    // Convertido para 3

float divisao = (float)10 / 3;  // 3.333... (sem casting seria 3)
```

### 10.3 Exemplos Práticos

```c
#include <stdio.h>

int main() {
    // Conversão de char para int
    char letra = 'A';
    int codigo = (int)letra;
    printf("Código ASCII de '%c': %d\n", letra, codigo);  // 65

    // Conversão de int para float
    int a = 10;
    int b = 3;
    float resultado1 = a / b;           // 3.0 (ambos inteiros)
    float resultado2 = (float)a / b;    // 3.333... (com conversão)

    printf("%.2f\n", resultado1);  // 3.00
    printf("%.2f\n", resultado2);  // 3.33

    return 0;
}
```

## 11. Variáveis Especiais

### 11.1 Volatile (volátil)

```c
volatile int sensor = 0;  // Valor pode mudar sem aviso (ex: entrada de hardware)
```

### 11.2 Restrict (restrito a ponteiros)

```c
void funcao(int * restrict p1, int * restrict p2) {
    // p1 e p2 apontam para áreas diferentes de memória
}
```

## 12. Exemplo Completo Prático

```c
#include <stdio.h>
#include <stdbool.h>

int main() {
    // Declaração e inicialização
    int idade = 25;
    float altura = 1.75f;
    char nome_inicial = 'J';
    bool ativo = true;

    // Entrada de dados
    printf("=== CADASTRO PESSOAL ===\n");
    printf("Digite sua idade: ");
    scanf("%d", &idade);

    printf("Digite sua altura (em metros): ");
    scanf("%f", &altura);

    printf("Digite a inicial do seu nome: ");
    scanf(" %c", &nome_inicial);

    // Processamento
    int ano_nascimento = 2025 - idade;
    float peso_ideal = 22 * altura * altura;  // BMI = 22

    // Saída de dados
    printf("\n=== DADOS CADASTRADOS ===\n");
    printf("Idade: %d anos\n", idade);
    printf("Altura: %.2f metros\n", altura);
    printf("Inicial: %c\n", nome_inicial);
    printf("Nascimento aproximado: %d\n", ano_nascimento);
    printf("Peso ideal (BMI 22): %.2f kg\n", peso_ideal);
    printf("Status: %s\n", ativo ? "Ativo" : "Inativo");

    printf("\nEndereço de idade: %p\n", (void*)&idade);
    printf("Tamanho de idade: %lu bytes\n", sizeof(idade));

    return 0;
}
```

## 13. Boas Práticas

### 13.1 Nomes Descritivos

```c
// ❌ EVITAR
int x, y, z;

// ✅ PREFERIR
int idade, altura, peso;
int quantidade_alunos;
int contador_iteracoes;
```

### 13.2 Inicializar Sempre

```c
// ❌ EVITAR
int valor;  // Contém lixo

// ✅ PREFERIR
int valor = 0;
```

### 13.3 Usar const para Constantes

```c
// ❌ EVITAR
int maximo = 100;

// ✅ PREFERIR
const int MAXIMO = 100;
```

### 13.4 Comentar Variáveis Complexas

```c
// Armazena o estado da conexão: 0=desconectado, 1=conectado, 2=erro
int estado_conexao = 0;

// Verificar se o usuário é administrador
bool is_admin = false;
```

## 14. Tabela de Formatadores scanf/printf

| Formatador | Tipo               | Exemplo  |
| ---------- | ------------------ | -------- |
| `%d`       | int                | -42      |
| `%u`       | unsigned int       | 42       |
| `%ld`      | long               | 1000     |
| `%f`       | float              | 3.14     |
| `%lf`      | double             | 3.141592 |
| `%.2f`     | float (2 casas)    | 3.14     |
| `%c`       | char               | 'A'      |
| `%s`       | string             | "Texto"  |
| `%x`       | hexadecimal        | 2a       |
| `%o`       | octal              | 52       |
| `%p`       | ponteiro           | 0x7fff5  |
| `%e`       | notação científica | 3.14e+00 |

## 15. Resumo Rápido

- **Variável** = local na memória com nome, tipo e valor
- **Tipos primitivos** = int, float, double, char, bool
- **Modificadores** = signed, unsigned, short, long, static, const, volatile
- **Escopo** = global, local, static, extern
- **Inicialização** = importante sempre inicializar
- **scanf** = lê dados (use &)
- **printf** = exibe dados (sem &)
- **sizeof()** = retorna tamanho em bytes
- **&** = operador de endereço
- **Cast** = conversão de tipo: `(tipo)variavel`

## 16. Exercícios Práticos

### Exercício 1: Calculadora Básica

```c
#include <stdio.h>

int main() {
    int a, b;

    printf("Digite dois números: ");
    scanf("%d %d", &a, &b);

    printf("Soma: %d\n", a + b);
    printf("Diferença: %d\n", a - b);
    printf("Produto: %d\n", a * b);
    printf("Divisão: %.2f\n", (float)a / b);

    return 0;
}
```

### Exercício 2: Converter Temperatura

```c
#include <stdio.h>

int main() {
    float celsius;

    printf("Digite a temperatura em Celsius: ");
    scanf("%f", &celsius);

    float fahrenheit = (celsius * 9/5) + 32;
    float kelvin = celsius + 273.15f;

    printf("Fahrenheit: %.2f\n", fahrenheit);
    printf("Kelvin: %.2f\n", kelvin);

    return 0;
}
```

### Exercício 3: Calcular Área

```c
#include <stdio.h>
#define PI 3.14159

int main() {
    float raio;

    printf("Digite o raio do círculo: ");
    scanf("%f", &raio);

    float area = PI * raio * raio;
    float perimetro = 2 * PI * raio;

    printf("Área: %.2f\n", area);
    printf("Perímetro: %.2f\n", perimetro);

    return 0;
}
```

---

**Conclusão**: Variáveis são os blocos fundamentais da programação em C. Compreender tipos, escopos, inicialização e manipulação de variáveis é essencial para dominar a linguagem.
