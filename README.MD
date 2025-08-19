# 🚢 Batalha Naval — Nível Mestre

Boa noite, comandante! 😎 A maré subiu e a estratégia está a outro nível! Agora o tabuleiro ganhou **habilidades especiais com áreas de efeito distintas** para apimentar o jogo.

## ✅ O que foi entregue

* **Tabuleiro 10x10** (matriz) inicializado com `0` (água).

* **Quatro navios tamanho 3** (2 lineares, 2 diagonais), com validação de limites e proibição de sobreposição.

* **Três matrizes de habilidade** (Cone, Cruz, Octaedro) com tamanho fixo (`5x5`) e valores `0` (não afetado) e `1` (afetado).

    * A **matriz Cone** representa uma área com ponto de origem no topo, expandindo-se para a base, conforme o exemplo **(3x5)**.

    * A **matriz Cruz** representa uma área em forma de cruz, com o ponto de origem no centro, conforme o exemplo **(3x5)**.

    * A **matriz Octaedro** representa a vista frontal de um octaedro (losango), com o ponto de origem no centro, conforme o exemplo **(3x5)**.

* **Definição de pontos de origem** para cada habilidade no tabuleiro.

* **Lógica** para **sobrepor** as matrizes de habilidade no tabuleiro principal, centrando-as nos pontos de origem e respeitando os limites.

* **Exibição completa do tabuleiro** com navios e áreas de efeito das habilidades, utilizando diferentes caracteres para representar:

    * `0` = água

    * `3` = navio

    * `4` = área de efeito (Cone)

    * `7` = área de efeito (Cruz)

    * `8` = área de efeito (Octaedro)

* **Utilização obrigatória de loops aninhados e condicionais** para a construção das matrizes de habilidade e para a sobreposição no tabuleiro.

## 🧠 Lógica de posicionamento e Habilidades Especiais

* **Navios Lineares**: checamos se `col + tamanho - 1 < 10` (horizontal) ou `lin + tamanho - 1 < 10` (vertical) e se todas as casas são `0` antes de gravar `3`.

* **Navios Diagonais**: verificamos passo a passo:

    * ↘: `(lin + k, col + k)`

    * ↙: `(lin + k, col - k)`

    * Em ambos os casos, validamos **limites** e **ausência de sobreposição**.

* **Habilidades Especiais**:

    * As formas são geradas dinamicamente dentro de suas respectivas matrizes 5x5, copiando padrões explícitos de **3x5** (baseados nos exemplos), usando loops aninhados e condicionais (`abs()` para o Octaedro).

    * A sobreposição do tabuleiro é feita calculando o deslocamento (`offset`) a partir do centro da habilidade para garantir que a área de efeito seja centralizada e não ultrapasse os limites do tabuleiro.

    * **Cone (4):** Ponto inicial (topo) e expansão para baixo, formando um triângulo.

    * **Cruz (7):** Linha e coluna centrais são marcadas.

    * **Octaedro (8):** Forma de losango, marcada pela distância de Manhattan ao centro.

## 🗺️ Coordenadas usadas (exemplos)

* Navio A (horizontal): `(1,2) → (1,4)`

* Navio B (vertical): `(5,7) → (7,7)`

* Navio C (diagonal ↘): `(3,3) → (5,5)`

* Navio D (diagonal ↙): `(7,5) → (9,3)`

* Habilidade Cone: Centrado em `(2,2)`

* Habilidade Cruz: Centrado em `(6,4)`

* Habilidade Octaedro: Centrado em `(8,8)`

## 🧾 Saída (exemplo)

     0  1  2  3  4  5  6  7  8  9
 0   0  0  0  0  0  0  0  0  0  0
 1   0  0  3  3  3  0  0  0  0  0
 2   0  0  4  0  0  0  0  0  0  0
 3   0  4  4  3  4  0  0  0  0  0
 4   4  4  4  4  3  0  0  0  0  0
 5   0  0  0  0  0  3  0  0  0  0
 6   0  0  0  0  7  0  0  3  0  0
 7   0  0  7  7  7  7  7  3  8  0
 8   0  0  0  0  7  3  0  8  8  8
 9   0  0  0  0  0  0  0  0  8  0

> Nota: O exemplo acima é apenas ilustrativo — a disposição final depende das coordenadas que definimos no código.

## 🔧 Como compilar e rodar

```bash
gcc batalha_naval_mestre.c -o batalha_naval_mestre
./batalha_naval_mestre

# 📦 Estrutura do código

inicializar_tabuleiro → preenche o tabuleiro com 0 (água).

verifica_linear / posicionar_linear → validam e posicionam navios lineares.

verifica_diagonal / posicionar_diagonal → validam e posicionam navios diagonais.

gerar_cone, gerar_cruz, gerar_octaedro → constroem as matrizes das habilidades.

aplicar_habilidade → sobrepõe uma habilidade no tabuleiro principal.

imprimir_tabuleiro → mostra o tabuleiro final com cabeçalhos e legenda.