# 📚 Wyden-C: Estruturas de Dados em C

[![C](https://img.shields.io/badge/Language-C-blue.svg)](<https://en.wikipedia.org/wiki/C_(programming_language)>)
[![Data Structures](https://img.shields.io/badge/Topic-Data%20Structures-green.svg)](https://en.wikipedia.org/wiki/Data_structure)
[![License](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)

> Repositório dedicado ao estudo e implementação de estruturas de dados em linguagem C. Desenvolvido durante o curso de Ciência da Computação.

## 📂 Estrutura do Projeto

```
wyden-C/
│
├── estruturas de dados em c/
│   ├── lista_ponteiros_completo.c      # Lista linear + circular
│   ├── lista_duplamente_encadeada.c    # Lista duplamente encadeada
│   ├── lista_dupla_circular.c          # Lista dupla circular
│   ├── pilha.c                         # Pilha (Stack) - 2 implementações
│   ├── fila.c                          # Fila (Queue) - 2 implementações
│   ├── exemplos_praticos.c             # Aplicações reais
│   ├── exercicio_template.c            # Template para exercícios
│   ├── exercicio_template_SOLUCOES.c   # Soluções dos exercícios
│   ├── EXERCICIOS_PROPOSTOS.c          # Lista de exercícios
│   ├── README.md                       # Guia rápido
│   └── GUIA_COMPLETO.md                # Documentação completa
│
├── .gitignore                          # Arquivos ignorados pelo Git
└── README.md                           # Este arquivo
```

## 🎯 Estruturas Implementadas

### ✅ Listas Encadeadas

- **Lista Linear**: `1 -> 2 -> 3 -> NULL`
- **Lista Duplamente Encadeada**: `NULL <- 1 <-> 2 <-> 3 -> NULL`
- **Lista Circular**: `1 -> 2 -> 3 -> 1 (volta ao início)`
- **Lista Dupla Circular**: Combinação de ambas

### ✅ Pilha (Stack - LIFO)

- Implementação com **array** (tamanho fixo)
- Implementação com **lista encadeada** (dinâmica)
- **Aplicação**: Validação de parênteses balanceados

### ✅ Fila (Queue - FIFO)

- Implementação com **array circular** (eficiente)
- Implementação com **lista encadeada** (flexível)
- **Aplicação**: Simulação de fila de atendimento bancário

### ✅ Aplicações Práticas

- 🏪 **Simulador de Estacionamento** (vagas, entrada/saída, histórico)
- 🔗 **Validador de Expressões** (parênteses, colchetes, chaves)

## 🚀 Como Usar

### Compilação e Execução

```bash
# Navegar para a pasta
cd "estruturas de dados em c"

# Compilar qualquer arquivo
gcc -o programa arquivo.c

# Executar
./programa          # Linux/Mac
.\programa.exe      # Windows
```

### Exemplos Rápidos

```bash
# Lista encadeada básica
gcc -o lista lista_ponteiros_completo.c && ./lista

# Pilha com validação de parênteses
gcc -o pilha pilha.c && ./pilha

# Fila com simulação de banco
gcc -o fila fila.c && ./fila

# Aplicações práticas
gcc -o apps exemplos_praticos.c && ./apps
```

## 📝 Exercícios Disponíveis

### Níveis de Dificuldade

- 🟢 **Básico**: Contar elementos, buscar valores
- 🟡 **Intermediário**: Inverter listas, ordenação
- 🔴 **Avançado**: Aplicações complexas, combinações

### Como Praticar

1. Copie o `exercicio_template.c`
2. Implemente as funções marcadas com `TODO`
3. Compare com `exercicio_template_SOLUCOES.c`
4. Teste com diferentes entradas

## 🛠️ Tecnologias Utilizadas

- **Linguagem**: C (ANSI C)
- **Compilador**: GCC
- **Sistema**: Windows/Linux/Mac
- **Controle de Versão**: Git
- **Plataforma**: GitHub

## 📚 Conceitos Aprendidos

- ✅ **Alocação dinâmica** (`malloc`, `free`)
- ✅ **Ponteiros** e manipulação de memória
- ✅ **Estruturas** (`struct`) e `typedef`
- ✅ **Listas encadeadas** (simples, dupla, circular)
- ✅ **Pilhas** e **Filas** (LIFO/FIFO)
- ✅ **Aplicações práticas** de estruturas de dados
- ✅ **Gestão de memória** (evitar vazamentos)

## 🎓 Roteiro de Estudos Recomendado

### Semana 1: Fundamentos

1. Lista encadeada linear
2. Operações básicas (inserir, remover, exibir)

### Semana 2: Estruturas Avançadas

1. Lista duplamente encadeada
2. Lista circular
3. Pilha e Fila

### Semana 3: Aplicações

1. Exercícios práticos
2. Aplicações do mundo real
3. Otimizações e melhorias

## 🤝 Como Contribuir

1. **Fork** o projeto
2. Crie uma **branch** para sua feature (`git checkout -b feature/nova-estrutura`)
3. **Commit** suas mudanças (`git commit -m 'Adiciona nova estrutura'`)
4. **Push** para a branch (`git push origin feature/nova-estrutura`)
5. Abra um **Pull Request**

### Sugestões de Contribuições

- ➕ Novas estruturas de dados (árvores, grafos)
- 🔧 Otimizações de performance
- 📝 Novos exercícios
- 🐛 Correções de bugs
- 📖 Melhorias na documentação

## 📄 Licença

Este projeto está sob a licença MIT. Veja o arquivo [LICENSE](LICENSE) para mais detalhes.

## 👨‍💻 Autor

**AGANEL DE LIMA SOUZA**

- 📧 Email: [agnaellima@gmail.com]
- 🔗 LinkedIn: [https://www.linkedin.com/in/agnael-lima-85255079/]
- 📚 Estudante de ENGENHARIA DE SOFTWERE


---

## 🙏 Agradecimentos

- Professor(a) do curso de Estruturas de Dados
- Comunidade de programação em C
- Plataformas de aprendizado online

---

⭐ **Se este repositório te ajudou, dê uma estrela!**

_"A melhor forma de aprender é ensinando aos outros."_
