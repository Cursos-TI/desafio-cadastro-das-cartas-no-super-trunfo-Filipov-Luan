#include <stdio.h>
#include <string.h>

// Estrutura para armazenar os dados de uma carta
typedef struct {
    char estado[3];
    char codigo[10];
    char nome_cidade[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
} Carta;

// Função para calcular densidade populacional e PIB per capita
void calcular_dados(Carta *carta) {
    carta->densidade_populacional = carta->populacao / carta->area;
    carta->pib_per_capita = carta->pib / carta->populacao;
}

// Função para exibir os dados de uma carta
void exibir_carta(Carta carta) {
    printf("Estado: %s\n", carta.estado);
    printf("Código: %s\n", carta.codigo);
    printf("Cidade: %s\n", carta.nome_cidade);
    printf("População: %d\n", carta.populacao);
    printf("Área: %.2f\n", carta.area);
    printf("PIB: %.2f\n", carta.pib);
    printf("Pontos Turísticos: %d\n", carta.pontos_turisticos);
    printf("Densidade Populacional: %.2f\n", carta.densidade_populacional);
    printf("PIB per capita: %.2f\n", carta.pib_per_capita);
    printf("-----------------------------\n");
}

int main() {
    // Cadastro das cartas (pré-definidas)
    Carta carta1 = {"SP", "C001", "São Paulo", 12300000, 1521.11, 700000000000.0, 10};
    Carta carta2 = {"RJ", "C002", "Rio de Janeiro", 6000000, 1182.30, 360000000000.0, 8};

    // Calcula os dados derivados
    calcular_dados(&carta1);
    calcular_dados(&carta2);

    // Exibe os dados das cartas
    printf("Carta 1:\n");
    exibir_carta(carta1);
    printf("Carta 2:\n");
    exibir_carta(carta2);

    // Escolha do atributo para comparação (População)
    printf("Comparação de cartas (Atributo: População):\n\n");
    printf("Carta 1 - %s (%s): %d\n", carta1.nome_cidade, carta1.estado, carta1.populacao);
    printf("Carta 2 - %s (%s): %d\n", carta2.nome_cidade, carta2.estado, carta2.populacao);

    // Lógica de comparação
    if (carta1.populacao > carta2.populacao) {
        printf("\nResultado: Carta 1 (%s) venceu!\n", carta1.nome_cidade);
    } else if (carta2.populacao > carta1.populacao) {
        printf("\nResultado: Carta 2 (%s) venceu!\n", carta2.nome_cidade);
    } else {
        printf("\nResultado: Empate!\n");
    }

    return 0;
}