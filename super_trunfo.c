#include <stdio.h>
#include <string.h>

// Define estrutura para a carta do país
typedef struct {
    char nome[30];
    int populacao;               // em milhões
    float area;                  // em km²
    float densidade;             // hab/km²
    int pib;                     // em bilhões
} Carta;

void exibirCarta(Carta c) {
    printf("País: %s\n", c.nome);
    printf("1. População (milhões): %d\n", c.populacao);
    printf("2. Área (km²): %.2f\n", c.area);
    printf("3. Densidade Demográfica (hab/km²): %.2f\n", c.densidade);
    printf("4. PIB (bilhões USD): %d\n", c.pib);
}

int escolherAtributo(int atributoSelecionado) {
    int opcao;
    printf("\nEscolha um atributo:\n");
    if (atributoSelecionado != 1) printf("1. População\n");
    if (atributoSelecionado != 2) printf("2. Área\n");
    if (atributoSelecionado != 3) printf("3. Densidade Demográfica\n");
    if (atributoSelecionado != 4) printf("4. PIB\n");
    printf("Opção: ");
    scanf("%d", &opcao);

    if (opcao < 1 || opcao > 4 || opcao == atributoSelecionado) {
        printf("Opção inválida. Tente novamente.\n");
        return escolherAtributo(atributoSelecionado);
    }

    return opcao;
}

float obterValorAtributo(Carta c, int atributo) {
    switch (atributo) {
        case 1: return (float)c.populacao;
        case 2: return c.area;
        case 3: return c.densidade;
        case 4: return (float)c.pib;
        default: return 0;
    }
}

const char* nomeAtributo(int atributo) {
    switch (atributo) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "Densidade Demográfica";
        case 4: return "PIB";
        default: return "Desconhecido";
    }
}

int escolherCarta(Carta cartas[], int qtd, int escolhida) {
    int opcao;
    printf("\nEscolha uma carta:\n");
    for (int i = 0; i < qtd; i++) {
        if (i != escolhida)
            printf("%d. %s\n", i + 1, cartas[i].nome);
    }
    printf("Opção: ");
    scanf("%d", &opcao);
    if (opcao < 1 || opcao > qtd || opcao - 1 == escolhida) {
        printf("Escolha inválida. Tente novamente.\n");
        return escolherCarta(cartas, qtd, escolhida);
    }
    return opcao - 1;
}

int main() {
    // Cartas cadastradas
    Carta cartas[3] = {
        {"Estados Unidos", 10, 500.0, 10.0, 5},
        {"Espanha", 5, 400.0, 10.0, 6},
        {"Brasil", 15, 900.0, 50.0, 11}
    };

    int carta1_idx, carta2_idx;
    int atributo1, atributo2;
    float valor1_c1, valor2_c1, valor1_c2, valor2_c2;
    float soma1, soma2;

    printf("=== SUPER TRUNFO: COMPARAÇÃO MULTI-ATRIBUTOS ===\n");

    // Escolha das cartas
    printf("\nEscolha a primeira carta:\n");
    carta1_idx = escolherCarta(cartas, 3, -1);
    printf("\nEscolha a segunda carta:\n");
    carta2_idx = escolherCarta(cartas, 3, carta1_idx);

    Carta c1 = cartas[carta1_idx];
    Carta c2 = cartas[carta2_idx];

    // Exibe as cartas escolhidas
    printf("\n--- Carta 1 ---\n");
    exibirCarta(c1);

    printf("\n--- Carta 2 ---\n");
    exibirCarta(c2);

    // Escolha dos atributos
    printf("\nEscolha o primeiro atributo para comparação:\n");
    atributo1 = escolherAtributo(0);

    printf("\nEscolha o segundo atributo (diferente do primeiro):\n");
    atributo2 = escolherAtributo(atributo1);

    // Obtem os valores dos atributos para ambas as cartas
    valor1_c1 = obterValorAtributo(c1, atributo1);
    valor1_c2 = obterValorAtributo(c2, atributo1);
    valor2_c1 = obterValorAtributo(c1, atributo2);
    valor2_c2 = obterValorAtributo(c2, atributo2);

    // Exibe comparação
    printf("\n=== COMPARAÇÃO ===\n");

    printf("\nAtributo 1: %s\n", nomeAtributo(atributo1));
    printf("%s: %.2f\n", c1.nome, valor1_c1);
    printf("%s: %.2f\n", c2.nome, valor1_c2);

    printf("\nAtributo 2: %s\n", nomeAtributo(atributo2));
    printf("%s: %.2f\n", c1.nome, valor2_c1);
    printf("%s: %.2f\n", c2.nome, valor2_c2);

    // Normaliza os valores (densidade é invertida)
    float v1_c1 = (atributo1 == 3) ? (10000 - valor1_c1) : valor1_c1;
    float v1_c2 = (atributo1 == 3) ? (10000 - valor1_c2) : valor1_c2;

    float v2_c1 = (atributo2 == 3) ? (10000 - valor2_c1) : valor2_c1;
    float v2_c2 = (atributo2 == 3) ? (10000 - valor2_c2) : valor2_c2;

    soma1 = v1_c1 + v2_c1;
    soma2 = v1_c2 + v2_c2;

    printf("\nSoma dos atributos:\n");
    printf("%s: %.2f\n", c1.nome, soma1);
    printf("%s: %.2f\n", c2.nome, soma2);

    printf("\n=== RESULTADO FINAL ===\n");
    if (soma1 > soma2) {
        printf("Vitória do %s!\n", c1.nome);
    } else if (soma2 > soma1) {
        printf("Vitória do %s!\n", c2.nome);
    } else {
        printf("Empate!\n");
    }

    return 0;
}
