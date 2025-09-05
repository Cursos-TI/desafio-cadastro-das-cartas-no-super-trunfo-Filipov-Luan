#include <stdio.h>
#include <string.h>
#include <math.h>
#include <float.h>

typedef struct {
    char estado[3];         // Ex: "SP"
    char codigo[4];         // Ex: "A01"
    char nome[64];          // Ex: "Santo André"
    unsigned long int populacao; // unsigned long int (requisito)
    double area;            // km^2
    double pib;             // unidade que você usar (ex.: R$)
    int pontos_turisticos;

    // Derivados
    double densidade;       // pop / area
    double pib_per_capita;  // pib / pop
    float super_poder;      // soma numérica com inverso da densidade
} Carta;

void ler_carta(Carta *c, int idx) {
    printf("\n--- Entrada da Carta %d ---\n", idx);
    printf("Estado (2 letras): ");
    scanf(" %2s", c->estado);

    printf("Codigo (ate 3 chars): ");
    scanf(" %3s", c->codigo);

    printf("Nome (linha completa): ");
    scanf(" %63[^\n]", c->nome);

    printf("Populacao (unsigned long): ");
    scanf("%lu", &c->populacao);

    printf("Area (km2): ");
    scanf("%lf", &c->area);

    printf("PIB: ");
    scanf("%lf", &c->pib);

    printf("Numero de pontos turisticos: ");
    scanf("%d", &c->pontos_turisticos);
}

void calcular_derivados_e_super(Carta *c) {
    // Densidade
    if (c->area > 0.0) {
        c->densidade = (double)c->populacao / c->area;
    } else {
        // Área zero -> densidade tende ao infinito (não desejamos NaN)
        c->densidade = INFINITY;
    }

    // PIB per capita
    if (c->populacao > 0UL) {
        c->pib_per_capita = c->pib / (double)c->populacao;
    } else {
        c->pib_per_capita = 0.0; // evita divisão por zero
    }

    // Inverso da densidade: quanto menor a densidade, maior o poder
    // Casos especiais:
    // - pop=0 e area>0 -> densidade=0 -> inverso muito alto (capado para não virar inf)
    // - area=0 e pop>0 -> densidade=inf -> inverso ~ 0
    double inv_densidade;
    if (c->populacao == 0UL && c->area > 0.0) {
        inv_densidade = DBL_MAX / 4.0; // valor grande finito
    } else if (!isfinite(c->densidade)) {
        inv_densidade = 0.0; // densidade infinita -> inverso ~ 0
    } else if (c->densidade > 0.0) {
        inv_densidade = 1.0 / c->densidade;
    } else {
        inv_densidade = 0.0;
    }

    // Super Poder (soma de todos os numericos + inverso da densidade)
    // Fazemos a soma em double e convertemos para float ao final (mais seguro).
    double soma = 0.0;
    soma += (double)c->populacao;
    soma += c->area;
    soma += c->pib;
    soma += (double)c->pontos_turisticos;
    soma += c->pib_per_capita;
    soma += inv_densidade;

    c->super_poder = (float)soma;
}

void exibir_carta(const Carta *c, int idx) {
    printf("\n--- Carta %d ---\n", idx);
    printf("Estado: %s\n", c->estado);
    printf("Codigo: %s\n", c->codigo);
    printf("Nome: %s\n", c->nome);
    printf("Populacao: %lu\n", c->populacao);
    printf("Area: %.2f\n", c->area);
    printf("PIB: %.2f\n", c->pib);
    printf("Pontos turisticos: %d\n", c->pontos_turisticos);
    printf("Densidade populacional: %.6f\n", c->densidade);
    printf("PIB per capita: %.6f\n", c->pib_per_capita);
    printf("Super Poder: %.6f\n", c->super_poder);
}

void comparar_e_exibir(const Carta *c1, const Carta *c2) {
    printf("\nComparacao de Cartas:\n");

    int vence;

    // Populacao (maior vence)
    vence = (c1->populacao > c2->populacao);
    printf("Populacao: %s ( %d )\n", vence ? "Carta 1 venceu" : "Carta 2 venceu", vence);

    // Area (maior vence)
    vence = (c1->area > c2->area);
    printf("Area: %s ( %d )\n", vence ? "Carta 1 venceu" : "Carta 2 venceu", vence);

    // PIB (maior vence)
    vence = (c1->pib > c2->pib);
    printf("PIB: %s ( %d )\n", vence ? "Carta 1 venceu" : "Carta 2 venceu", vence);

    // Pontos turisticos (maior vence)
    vence = (c1->pontos_turisticos > c2->pontos_turisticos);
    printf("Pontos Turisticos: %s ( %d )\n", vence ? "Carta 1 venceu" : "Carta 2 venceu", vence);

    // Densidade populacional (menor vence)
    vence = (c1->densidade < c2->densidade);
    printf("Densidade Populacional: %s ( %d )\n", vence ? "Carta 1 venceu" : "Carta 2 venceu", vence);

    // PIB per capita (maior vence)
    vence = (c1->pib_per_capita > c2->pib_per_capita);
    printf("PIB per Capita: %s ( %d )\n", vence ? "Carta 1 venceu" : "Carta 2 venceu", vence);

    // Super Poder (maior vence)
    vence = (c1->super_poder > c2->super_poder);
    printf("Super Poder: %s ( %d )\n", vence ? "Carta 1 venceu" : "Carta 2 venceu", vence);
}

int main(void) {
    Carta c1 = {0}, c2 = {0};

    // Leitura das duas cartas
    ler_carta(&c1, 1);
    ler_carta(&c2, 2);

    // Calculos derivados e Super Poder
    calcular_derivados_e_super(&c1);
    calcular_derivados_e_super(&c2);

    // Exibir as cartas (inclui densidade, PIB per capita e super poder)
    exibir_carta(&c1, 1);
    exibir_carta(&c2, 2);

    // Comparar e exibir resultados
    comparar_e_exibir(&c1, &c2);

    return 0;
}
