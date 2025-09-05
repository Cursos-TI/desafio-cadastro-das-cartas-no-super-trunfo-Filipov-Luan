#include <stdio.h>
#include <string.h>

// Estrutura para armazenar os dados de uma carta
typedef struct {
    char nome_pais[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_demografica;
} Carta;

// Função para calcular densidade demográfica
void calcular_densidade(Carta *carta) {
    carta->densidade_demografica = carta->populacao / carta->area;
}

// Função para exibir os dados de uma carta
void exibir_carta(Carta carta) {
    printf("País: %s\n", carta.nome_pais);
    printf("População: %d\n", carta.populacao);
    printf("Área: %.2f\n", carta.area);
    printf("PIB: %.2f\n", carta.pib);
    printf("Pontos Turísticos: %d\n", carta.pontos_turisticos);
    printf("Densidade Demográfica: %.2f\n", carta.densidade_demografica);
    printf("-----------------------------\n");
}

int main() {
    // Cartas pré-definidas
    Carta carta1 = {"Brasil", 214000000, 8515767.0, 1868000000000.0, 12, 0};
    Carta carta2 = {"Argentina", 45376763, 2780400.0, 491500000000.0, 7, 0};

    // Calcula densidade demográfica
    calcular_densidade(&carta1);
    calcular_densidade(&carta2);

    int opcao;
    int continuar = 1;

    while (continuar) {
        printf("\n=== SUPER TRUNFO - MENU DE COMPARAÇÃO ===\n");
        printf("Escolha o atributo para comparar:\n");
        printf("1 - População\n");
        printf("2 - Área\n");
        printf("3 - PIB\n");
        printf("4 - Pontos Turísticos\n");
        printf("5 - Densidade Demográfica\n");
        printf("0 - Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        printf("\nComparando: %s x %s\n", carta1.nome_pais, carta2.nome_pais);

        switch (opcao) {
            case 1:
                printf("Atributo: População\n");
                printf("%s: %d\n", carta1.nome_pais, carta1.populacao);
                printf("%s: %d\n", carta2.nome_pais, carta2.populacao);
                if (carta1.populacao > carta2.populacao) {
                    printf("Resultado: %s venceu!\n", carta1.nome_pais);
                } else if (carta2.populacao > carta1.populacao) {
                    printf("Resultado: %s venceu!\n", carta2.nome_pais);
                } else {
                    printf("Resultado: Empate!\n");
                }
                break;
            case 2:
                printf("Atributo: Área\n");
                printf("%s: %.2f\n", carta1.nome_pais, carta1.area);
                printf("%s: %.2f\n", carta2.nome_pais, carta2.area);
                if (carta1.area > carta2.area) {
                    printf("Resultado: %s venceu!\n", carta1.nome_pais);
                } else if (carta2.area > carta1.area) {
                    printf("Resultado: %s venceu!\n", carta2.nome_pais);
                } else {
                    printf("Resultado: Empate!\n");
                }
                break;
            case 3:
                printf("Atributo: PIB\n");
                printf("%s: %.2f\n", carta1.nome_pais, carta1.pib);
                printf("%s: %.2f\n", carta2.nome_pais, carta2.pib);
                if (carta1.pib > carta2.pib) {
                    printf("Resultado: %s venceu!\n", carta1.nome_pais);
                } else if (carta2.pib > carta1.pib) {
                    printf("Resultado: %s venceu!\n", carta2.nome_pais);
                } else {
                    printf("Resultado: Empate!\n");
                }
                break;
            case 4:
                printf("Atributo: Pontos Turísticos\n");
                printf("%s: %d\n", carta1.nome_pais, carta1.pontos_turisticos);
                printf("%s: %d\n", carta2.nome_pais, carta2.pontos_turisticos);
                if (carta1.pontos_turisticos > carta2.pontos_turisticos) {
                    printf("Resultado: %s venceu!\n", carta1.nome_pais);
                } else if (carta2.pontos_turisticos > carta1.pontos_turisticos) {
                    printf("Resultado: %s venceu!\n", carta2.nome_pais);
                } else {
                    printf("Resultado: Empate!\n");
                }
                break;
            case 5:
                printf("Atributo: Densidade Demográfica\n");
                printf("%s: %.2f\n", carta1.nome_pais, carta1.densidade_demografica);
                printf("%s: %.2f\n", carta2.nome_pais, carta2.densidade_demografica);
                // Regra invertida: vence o menor valor
                if (carta1.densidade_demografica < carta2.densidade_demografica) {
                    printf("Resultado: %s venceu!\n", carta1.nome_pais);
                } else if (carta2.densidade_demografica < carta1.densidade_demografica) {
                    printf("Resultado: %s venceu!\n", carta2.nome_pais);
                } else {
                    printf("Resultado: Empate!\n");
                }
                break;
            case 0:
                printf("Saindo do jogo. Até logo!\n");
                continuar = 0;
                break;
            default:
                printf("Opção inválida! Por favor, escolha uma opção do menu.\n");
        }
    }

    return 0;
}