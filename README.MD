
# 🚢 Batalha Naval - Desafio Nível Novato

Fala, comandante! 😎
Seja bem-vindo ao primeiro passo da nossa gloriosa jornada na Batalha Naval. Aqui, o objetivo era simples:
colocar dois navios no tabuleiro sem afundar o próprio barco.

## 📜 Descrição
- Criamos um tabuleiro 10x10  na moralzinha, inicializando tudo com `0` (água).
- Dois navios de tamanho **3** foram posicionados: um horizontal e outro vertical.
- Os navios são representados pelo número `3` (porque 3 é o número da sorte do marujo 😏).
- Nada de sobreposição! Cada um no seu quadrado, como bons marinheiros.

## 🎯 Objetivo
- Mostrar o tabuleiro no console, com navios e água bem organizados.
- Usar loops aninhados para percorrer e exibir o tabuleiro.
- Garantir que os navios não saiam navegando fora do mapa.

## 📌 Regras
- Tamanho do tabuleiro: 10x10
- Tamanho do navio: 3 posições
- Coordenadas definidas direto no código (nada de input do usuário nesse nível).

## 💻 Execução
1. Compila o programa:
   ```bash
   gcc batalha_naval.c -o batalha_naval
   ```
2. Executa:
   ```bash
   ./batalha_naval
   ```

## 🏆 Resultado esperado

 0 1 2 3 4 5 6 7 8 9
0  0 0 0 0 0 0 0 0 0 0
1  0 0 0 0 0 0 0 0 0 0
2  0 0 0 0 3 3 3 0 0 0
3  0 0 0 0 0 0 0 0 0 0
4  0 0 0 0 0 0 0 0 0 0
5  0 3 0 0 0 0 0 0 0 0
6  0 3 0 0 0 0 0 0 0 0
7  0 3 0 0 0 0 0 0 0 0
8  0 0 0 0 0 0 0 0 0 0
9  0 0 0 0 0 0 0 0 0 0


## 🏁 Observações
Esse foi só o aquecimento.
