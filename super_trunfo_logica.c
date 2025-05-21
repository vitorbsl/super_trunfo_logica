#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    unsigned long int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidade;
    float pibPerCapita;
} Carta;

void calcularIndicadores(Carta *carta) {
    carta->densidade = carta->populacao / carta->area;
    carta->pibPerCapita = carta->pib / carta->populacao;
}

void exibirMenuAtributos(int ignorar) {
    printf("Escolha um atributo para comparar:\n");
    if (ignorar != 1) printf("1. Populacao\n");
    if (ignorar != 2) printf("2. Area\n");
    if (ignorar != 3) printf("3. PIB\n");
    if (ignorar != 4) printf("4. Pontos Turisticos\n");
    if (ignorar != 5) printf("5. Densidade Demografica\n");
    if (ignorar != 6) printf("6. PIB per Capita\n");
}

float obterValorPorAtributo(Carta c, int escolha) {
    switch (escolha) {
        case 1: return (float)c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return (float)c.pontosTuristicos;
        case 5: return c.densidade;
        case 6: return c.pibPerCapita;
        default: return -1;
    }
}

int main() {
    Carta carta1 = {"Brasil", 211000000, 8515767.0, 2200000000000.0, 50};
    Carta carta2 = {"Argentina", 45000000, 2780400.0, 500000000000.0, 20};

    calcularIndicadores(&carta1);
    calcularIndicadores(&carta2);

    int escolha1 = 0, escolha2 = 0;
    float valor1_c1, valor1_c2, valor2_c1, valor2_c2, soma1, soma2;

    // Menu para o primeiro atributo
    exibirMenuAtributos(0);
    printf("Escolha o primeiro atributo: ");
    scanf("%d", &escolha1);

    // Menu para o segundo atributo (exclui o anterior)
    exibirMenuAtributos(escolha1);
    printf("Escolha o segundo atributo: ");
    scanf("%d", &escolha2);

    // Pega valores dos atributos escolhidos
    valor1_c1 = obterValorPorAtributo(carta1, escolha1);
    valor1_c2 = obterValorPorAtributo(carta2, escolha1);
    valor2_c1 = obterValorPorAtributo(carta1, escolha2);
    valor2_c2 = obterValorPorAtributo(carta2, escolha2);

    soma1 = valor1_c1 + valor2_c1;
    soma2 = valor1_c2 + valor2_c2;

    printf("\nComparando %s vs %s:\n", carta1.nome, carta2.nome);
    printf("Atributo 1: %d - %s\n", escolha1,
           (escolha1 == 5) ? "Densidade (menor vence)" : "Maior valor vence");
    printf("  %s: %.2f | %s: %.2f\n", carta1.nome, valor1_c1, carta2.nome, valor1_c2);

    printf("Atributo 2: %d - %s\n", escolha2,
           (escolha2 == 5) ? "Densidade (menor vence)" : "Maior valor vence");
    printf("  %s: %.2f | %s: %.2f\n", carta1.nome, valor2_c1, carta2.nome, valor2_c2);

    // Resultado dos atributos individualmente
    int resultado1 = (escolha1 == 5) ? (valor1_c1 < valor1_c2) : (valor1_c1 > valor1_c2);
    int resultado2 = (escolha2 == 5) ? (valor2_c1 < valor2_c2) : (valor2_c1 > valor2_c2);

    printf("\nResultado:\n");
    printf("  %s venceu no atributo 1: %d\n", resultado1 ? "Carta 1" : "Carta 2", resultado1);
    printf("  %s venceu no atributo 2: %d\n", resultado2 ? "Carta 1" : "Carta 2", resultado2);

    printf("\nSoma dos atributos:\n");
    printf("  %s: %.2f\n", carta1.nome, soma1);
    printf("  %s: %.2f\n", carta2.nome, soma2);

    printf("\nResultado Final: ");
    if (soma1 > soma2) {
        printf("%s venceu!\n", carta1.nome);
    } else if (soma2 > soma1) {
        printf("%s venceu!\n", carta2.nome);
    } else {
        printf("Empate!\n");
    }

    return 0;
}
