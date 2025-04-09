#include <stdio.h>

#define TAMANHO_TABULEIRO 10 // Define o tamanho do tabuleiro (10x10)
#define TAMANHO_NAVIO 3      // Define o tamanho padrão de cada navio (3 casas)

// Valores para representação no tabuleiro
#define AGUA 0  // Valor para representar água no tabuleiro
#define NAVIO 3 // Valor para representar navio no tabuleiro

int main()
{
    // Inicializa o tabuleiro com AGUA (valor 0)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // ===================================================
    // Definição das coordenadas dos navios básicos:
    // ===================================================

    // Navio Horizontal:
    // Posicionado na linha 2 (índice 1), começando na coluna D (índice 3)
    int navio_horizontal_linha = 2;
    int navio_horizontal_coluna_inicio = 3;

    // Navio Vertical:
    // Posicionado na coluna G (índice 6), começando na linha 6 (índice 5)
    int navio_vertical_coluna = 6;
    int navio_vertical_linha_inicio = 5;

    // ===================================================
    // Validações de posicionamento dos navios
    // ===================================================

    // Verifica se o navio horizontal cabe no tabuleiro
    if (navio_horizontal_coluna_inicio < 0 ||
        navio_horizontal_coluna_inicio + TAMANHO_NAVIO > TAMANHO_TABULEIRO)
    {
        printf("Erro: Navio horizontal fora dos limites do tabuleiro!\n");
        return 1;
    }

    // Verifica se o navio vertical cabe no tabuleiro
    if (navio_vertical_linha_inicio < 0 ||
        navio_vertical_linha_inicio + TAMANHO_NAVIO > TAMANHO_TABULEIRO)
    {
        printf("Erro: Navio vertical fora dos limites do tabuleiro!\n");
        return 1;
    }

    // ===================================================
    // Posicionamento dos navios no tabuleiro
    // ===================================================

    // Posiciona o navio horizontal no tabuleiro
    for (int i = 0; i < TAMANHO_NAVIO; i++)
    {
        // Verifica se a posição já está ocupada por outro navio
        if (tabuleiro[navio_horizontal_linha][navio_horizontal_coluna_inicio + i] != AGUA)
        {
            printf("Erro: Sobreposição detectada no navio horizontal!\n");
            return 1;
        }
        tabuleiro[navio_horizontal_linha][navio_horizontal_coluna_inicio + i] = NAVIO;
    }

    // Posiciona o navio vertical no tabuleiro
    for (int i = 0; i < TAMANHO_NAVIO; i++)
    {
        // Verifica se a posição já está ocupada por outro navio
        if (tabuleiro[navio_vertical_linha_inicio + i][navio_vertical_coluna] != AGUA)
        {
            printf("Erro: Sobreposição detectada no navio vertical!\n");
            return 1;
        }
        tabuleiro[navio_vertical_linha_inicio + i][navio_vertical_coluna] = NAVIO;
    }

    // ===================================================
    // Exibe o tabuleiro com os navios
    // ===================================================
    printf("Tabuleiro Batalha Naval\n");
    printf("--------------------------\n");
    printf("    A B C D E F G H I J\n"); // Cabeçalho com letras das colunas
    for (int linha = 0; linha < TAMANHO_TABULEIRO; linha++)
    {
        // Imprime o número da linha (1 a 10)
        printf("%2d  ", linha + 1);

        // Imprime o conteúdo de cada célula na linha
        for (int coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++)
        {
            printf("%d ", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }

    return 0;
}