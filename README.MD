
# 🚢 Batalha Naval — Nível Aventureiro

Boa noite, comandante! 😎 Bora elevar a maré. Agora o tabuleiro ganhou **navios na diagonal** além dos horizontais/verticais.

## ✅ O que foi entregue
- **Tabuleiro 10x10** (matriz) inicializado com `0` (água).
- **Quatro navios tamanho 3**:
  - 2 lineares (horizontal e vertical)
  - 2 diagonais: ↘ (linha e coluna aumentam) e ↙ (linha aumenta, coluna diminui)
- **Validação** de limites e **proibição de sobreposição**.
- **Impressão** do tabuleiro formatado com cabeçalho de linhas/colunas.

## 🧠 Lógica de posicionamento
- **Lineares**: checamos se `col + tamanho - 1 < 10` (horizontal) ou `lin + tamanho - 1 < 10` (vertical) e se todas as casas são `0` antes de gravar `3`.
- **Diagonais**: verificamos passo a passo:
  - ↘: `(lin + k, col + k)`
  - ↙: `(lin + k, col - k)`
  - Em ambos os casos, validamos **limites** e **ausência de sobreposição**.

## 🗺️ Coordenadas usadas (tamanho 3)
- Navio A (horizontal): `(1,2) → (1,4)`
- Navio B (vertical): `(5,7) → (7,7)`
- Navio C (diagonal ↘): `(3,3) → (5,5)`
- Navio D (diagonal ↙): `(7,5) → (9,3)`

> Todas estas posições **não se cruzam** e ficam dentro do tabuleiro 0–9.

## 🧾 Saída (exemplo)
```
=== Batalha Naval - Nivel Aventureiro ===
Legenda: 0=agua, 3=navio (tamanho 3)

     0  1  2  3  4  5  6  7  8  9
 0   0  0  0  0  0  0  0  0  0  0
 1   0  0  3  3  3  0  0  0  0  0
 2   0  0  0  0  0  0  0  0  0  0
 3   0  0  0  3  0  0  0  0  0  0
 4   0  0  0  0  3  0  0  0  0  0
 5   0  0  0  0  0  3  0  3  0  0
 6   0  0  0  0  0  0  0  3  0  0
 7   0  0  0  0  0  3  0  3  0  0
 8   0  0  0  0  3  0  0  0  0  0
 9   0  0  0  3  0  0  0  0  0  0
```

> Nota: O exemplo acima é apenas ilustrativo — a disposição final depende das coordenadas que definimos no código (as listadas acima).

## 🔧 Como compilar e rodar
```bash
gcc batalha_naval_aventureiro.c -o batalha_naval_aventureiro
./batalha_naval_aventureiro
```

## 📦 Estrutura do código
- `inicializar_tabuleiro`: zera a matriz.
- `verifica_linear` / `posicionar_linear`: valida e posiciona horizontais/verticais.
- `verifica_diagonal` / `posicionar_diagonal`: valida e posiciona diagonais ↘ e ↙.
- `imprimir_tabuleiro`: imprime cabeçalho + matriz 10x10.

