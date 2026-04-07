// ============================================================================
// GUIA PRÁTICO DE USO - EXEMPLOS INTERATIVOS
// ============================================================================

/*
ESTE ARQUIVO MOSTRA COMO USAR O PROGRAMA lista_operacoes_praticas.c

PASSO A PASSO DE UM EXEMPLO COMPLETO:
========================================

1. INICIALIZAR:
   - Capacidade máxima: 5 (você pode criar lista com 5 elementos)

2. INSERIR ALGUNS ELEMENTOS:
   - Inserir no final: 10, 20, 30
   - Inserir no início: 5
   - Lista fica: [5, 10, 20, 30]

3. LISTAR ELEMENTOS:
   - Mostra: Posição [0] = 5
            Posição [1] = 10
            Posição [2] = 20
            Posição [3] = 30

4. CONTAR ELEMENTOS:
   - Total: 4/5

5. INSERIR EM POSIÇÃO ESPECÍFICA (posição 2):
   - Valor: 15
   - Lista fica: [5, 10, 15, 20, 30]

6. REMOVER DO FINAL:
   - Remove: 30
   - Lista fica: [5, 10, 15, 20]

7. REMOVER DO INÍCIO:
   - Remove: 5
   - Lista fica: [10, 15, 20]

8. REMOVER DE POSIÇÃO (posição 1):
   - Remove: 15
   - Lista fica: [10, 20]

9. BUSCAR ELEMENTO (procurar 20):
   - Encontrado na posição 1

10. REMOVER POR VALOR (remover 10):
    - Remove: 10
    - Lista fica: [20]


CONCEITOS IMPORTANTES QUE VOCÊ VAI APRENDER:
=============================================

1️⃣ DESLOCAMENTO PARA INSERIR NO INÍCIO:
   Antes:  [10, 20, 30]
   Inserir 5:
   - Move 30 → 31: [10, 20, 30, ?]
   - Move 20 → 30: [10, 20, ?, ?]
   - Move 10 → 20: [10, ?, ?, ?]
   - Coloca 5 → 0: [5, 10, 20, 30]

2️⃣ DESLOCAMENTO PARA REMOVER DO INÍCIO:
   Antes:  [5, 10, 20, 30]
   Remover primeiro:
   - Move 10 → 0: [10, 10, 20, 30]
   - Move 20 → 1: [10, 20, 20, 30]
   - Move 30 → 2: [10, 20, 30, 30]
   - Diminui quantidade para 3: [10, 20, 30]

3️⃣ INSERIR EM POSIÇÃO ESPECÍFICA:
   Antes:  [10, 20, 30]  (quantidade = 3)
   Inserir 15 na posição 1:
   - Move 30 → 31: [10, 20, 30, ?]
   - Move 20 → 30: [10, 20, ?, ?]
   - Coloca 15 → 1: [10, 15, 20, ?]
   - Aumenta quantidade para 4: [10, 15, 20, 30]

4️⃣ QUANTIDADE vs TAMANHO:
   - tamanho = capacidade máxima (5 no exemplo)
   - quantidade = elementos que estão realmente na lista
   - Se quantidade == tamanho, não pode inserir mais!


TESTE NA PRÁTICA:
=================

Execute: lista_operacoes_praticas.exe

Entrada de exemplo:
5                    (capacidade)
3                    (inserir no final)
10
3                    (inserir no final)
20
3                    (inserir no final)
30
1                    (listar)
2                    (contar)
5                    (inserir em posição)
15
1                    (listar)
8                    (remover posição)
1
1                    (listar)
10                   (buscar)
20
0                    (sair)

*/
