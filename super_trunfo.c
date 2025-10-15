#include <stdio.h>
#include <string.h>

// Define estrutura para a carta do país
typedef struct {
    char nome[30];
    int populacao;        // em milhões
    float area;           // em km²
    float densidade;      // hab/km²
    int pib;              // em bilhões USD
} Carta;

// Exibe os dados de uma carta
void exibirCarta(const Carta *c) {
    printf("País: %s\n", c->nome);
    printf("1. População (milhões): %d\n", c->populacao);
    printf("2. Área (km²): %.0f\n", c->area);
    printf("3. Densidade Demográfica (hab/km²): %.0f\n", c->densidade);
    printf("4. PIB (bilhões USD): %d\n", c->pib);
}

// Menu de escolha de atributo, evitando repetir o já escolhido
int escolherAtributo(int jaEscolhido) {
    int opcao;
    printf("\nEscolha um atributo:\n");
    if (jaEscolhido != 1) printf("1. População\n");
    if (jaEscolhido != 2) printf("2. Área\n");
    if (jaEscolhido != 3) printf("3. Densidade Demográfica\n");
    if (jaEscolhido != 4) printf("4. PIB\n");
    printf("Opção: ");
    scanf("%d", &opcao);
    if (opcao < 1 || opcao > 4 || opcao == jaEscolhido) {
        printf("Opção inválida. Tente novamente.\n");
        return escolherAtributo(jaEscolhido);
    }
    return opcao;
}

// Retorna o valor numérico do atributo selecionado
float obterValor(const Carta *c, int atributo) {
    switch (atributo) {
        case 1: return c->populacao;
        case 2: return c->area;
        case 3: return c->densidade;
        case 4: return c->pib;
        default: return 0;
    }
}

// Nome amigável do atributo
const char* nomeAtributo(int atributo) {
    switch (atributo) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "Densidade Demográfica";
        case 4: return "PIB";
        default: return "Desconhecido";
    }
}

// Compara dois valores de atributo segundo regra (densidade invertida)
int vence(float a, float b, int atributo) {
    if (atributo == 3)  // densidade: menor é melhor
        return (a < b);
    else                // demais: maior é melhor
        return (a > b);
}

// Menu de escolha de carta, evitando repetir a já escolhida
int escolherCarta(const Carta cartas[], int n, int jaEscolhida) {
    int opcao;
    printf("\nEscolha uma carta:\n");
    for (int i = 0; i < n; i++) {
        if (i != jaEscolhida) {
            printf("%d. %s\n", i + 1, cartas[i].nome);
        }
    }
    printf("Opção: ");
    scanf("%d", &opcao);
    if (opcao < 1 || opcao > n || opcao - 1 == jaEscolhida) {
        printf("Escolha inválida. Tente novamente.\n");
        return escolherCarta(cartas, n, jaEscolhida);
    }
    return opcao - 1;
}

int main() {
    // Cartas com dados reais
    Carta cartas[3] = {
        {"Estados Unidos", 342, 9834000.0f, 36.0f,  28700},
        {"Espanha",         47,  505000.0f, 94.0f,   1700},
        {"Brasil",         213, 8516000.0f, 25.0f,   2200}
    };

    printf("=== SUPER TRUNFO: COMPARAÇÃO MULTI-ATRIBUTOS ===\n");

    // Escolha de cartas
    int idx1 = escolherCarta(cartas, 3, -1);
    int idx2 = escolherCarta(cartas, 3, idx1);

    Carta *c1 = &cartas[idx1];
    Carta *c2 = &cartas[idx2];

    // Exibe cartas
    printf("\n--- Carta 1 ---\n");  exibirCarta(c1);
    printf("\n--- Carta 2 ---\n");  exibirCarta(c2);

    // Escolha de atributos
    int attr1 = escolherAtributo(0);
    int attr2 = escolherAtributo(attr1);

    // Obtém valores
    float v1a = obterValor(c1, attr1);
    float v2a = obterValor(c2, attr1);
    float v1b = obterValor(c1, attr2);
    float v2b = obterValor(c2, attr2);

    // Exibe comparação
    printf("\n=== COMPARAÇÃO ===\n");
    printf("%s:\n  %s = %.0f\n  %s = %.0f\n",
           nomeAtributo(attr1), c1->nome, v1a, c2->nome, v2a);
    printf("%s:\n  %s = %.0f\n  %s = %.0f\n",
           nomeAtributo(attr2), c1->nome, v1b, c2->nome, v2b);

    // Usa operador ternário para atribuir pontos
    int p1 = vence(v1a, v2a, attr1) ? 1 : 0;
    int p2 = vence(v1b, v2b, attr2) ? 1 : 0;
    int pontos1 = p1 + p2;
    int pontos2 = (2 - pontos1);

    // Exibe soma de pontos
    printf("\nSoma de pontos:\n  %s: %d\n  %s: %d\n",
           c1->nome, pontos1, c2->nome, pontos2);

    // Resultado final
    printf("\n=== RESULTADO FINAL ===\n");
    if (pontos1 > pontos2)
        printf("Vitória do %s!\n", c1->nome);
    else if (pontos2 > pontos1)
        printf("Vitória do %s!\n", c2->nome);
    else
        printf("Empate!\n");

    return 0;
}
