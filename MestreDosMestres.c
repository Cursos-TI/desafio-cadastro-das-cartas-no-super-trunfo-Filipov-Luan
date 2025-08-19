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

// Função para exibir o menu de atributos
void exibir_menu(int atributo_bloqueado) {
    printf("Escolha um atributo para comparar:\n");
    if (atributo_bloqueado != 1) printf("1 - População\n");
    if (atributo_bloqueado != 2) printf("2 - Área\n");
    if (atributo_bloqueado != 3) printf("3 - PIB\n");
    if (atributo_bloqueado != 4) printf("4 - Pontos Turísticos\n");
    if (atributo_bloqueado != 5) printf("5 - Densidade Demográfica\n");
}

// Função para obter o valor do atributo escolhido
float obter_valor_atributo(Carta carta, int atributo) {
    switch (atributo) {
        case 1: return (float)carta.populacao;
        case 2: return carta.area;
        case 3: return carta.pib;
        case 4: return (float)carta.pontos_turisticos;
        case 5: return carta.densidade_demografica;
        default: return 0;
    }
}

// Função para obter o nome do atributo
const char* nome_atributo(int atributo) {
    switch (atributo) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Pontos Turísticos";
        case 5: return "Densidade Demográfica";
        default: return "Desconhecido";
    }
}

int main() {
    // Cartas pré-definidas
    Carta carta1 = {"Brasil", 214000000, 8515767.0, 1868000000000.0, 12, 0};
    Carta carta2 = {"Argentina", 45376763, 2780400.0, 491500000000.0, 7, 0};

    // Calcula densidade demográfica
    calcular_densidade(&carta1);
    calcular_densidade(&carta2);

    int atributo1 = 0, atributo2 = 0;
    int valido = 0;

    // Escolha do primeiro atributo
    do {
        printf("\n=== SUPER TRUNFO - ESCOLHA DE ATRIBUTOS ===\n");
        exibir_menu(0);
        printf("Digite o número do primeiro atributo: ");
        scanf("%d", &atributo1);
        if (atributo1 >= 1 && atributo1 <= 5) {
            valido = 1;
        } else {
            printf("Opção inválida! Tente novamente.\n");
            valido = 0;
        }
    } while (!valido);

    // Escolha do segundo atributo (não pode ser igual ao primeiro)
    valido = 0;
    do {
        printf("\nAgora escolha o segundo atributo (diferente do primeiro):\n");
        exibir_menu(atributo1);
        printf("Digite o número do segundo atributo: ");
        scanf("%d", &atributo2);
        if (atributo2 >= 1 && atributo2 <= 5 && atributo2 != atributo1) {
            valido = 1;
        } else {
            printf("Opção inválida ou repetida! Tente novamente.\n");
            valido = 0;
        }
    } while (!valido);

    // Obter valores dos atributos para cada carta
    float valor1_c1 = obter_valor_atributo(carta1, atributo1);
    float valor1_c2 = obter_valor_atributo(carta2, atributo1);
    float valor2_c1 = obter_valor_atributo(carta1, atributo2);
    float valor2_c2 = obter_valor_atributo(carta2, atributo2);

    // Comparação do primeiro atributo
    int vencedor1 = 0; // 1 = carta1, 2 = carta2, 0 = empate
    if (atributo1 == 5) { // Densidade Demográfica: menor vence
        vencedor1 = (valor1_c1 < valor1_c2) ? 1 : (valor1_c2 < valor1_c1) ? 2 : 0;
    } else {
        vencedor1 = (valor1_c1 > valor1_c2) ? 1 : (valor1_c2 > valor1_c1) ? 2 : 0;
    }

    // Comparação do segundo atributo
    int vencedor2 = 0;
    if (atributo2 == 5) { // Densidade Demográfica: menor vence
        vencedor2 = (valor2_c1 < valor2_c2) ? 1 : (valor2_c2 < valor2_c1) ? 2 : 0;
    } else {
        vencedor2 = (valor2_c1 > valor2_c2) ? 1 : (valor2_c2 > valor2_c1) ? 2 : 0;
    }

    // Soma dos atributos
    float soma_c1 = valor1_c1 + valor2_c1;
    float soma_c2 = valor1_c2 + valor2_c2;

    // Determinação do vencedor final
    int vencedor_final = (soma_c1 > soma_c2) ? 1 : (soma_c2 > soma_c1) ? 2 : 0;

    // Exibição dos resultados
    printf("\n=== RESULTADO DA COMPARAÇÃO ===\n");
    printf("País 1: %s\n", carta1.nome_pais);
    printf("País 2: %s\n", carta2.nome_pais);
    printf("\nAtributos escolhidos:\n");
    printf("1) %s\n", nome_atributo(atributo1));
    printf("2) %s\n", nome_atributo(atributo2));
    printf("\nValores dos atributos:\n");
    printf("%s:\n", carta1.nome_pais);
    printf("  %s: %.2f\n", nome_atributo(atributo1), valor1_c1);
    printf("  %s: %.2f\n", nome_atributo(atributo2), valor2_c1);
    printf("  Soma: %.2f\n", soma_c1);
    printf("%s:\n", carta2.nome_pais);
    printf("  %s: %.2f\n", nome_atributo(atributo1), valor1_c2);
    printf("  %s: %.2f\n", nome_atributo(atributo2), valor2_c2);
    printf("  Soma: %.2f\n", soma_c2);

    printf("\nResultado final: ");
    if (vencedor_final == 1) {
        printf("%s venceu!\n", carta1.nome_pais);
    } else if (vencedor_final == 2) {
        printf("%s venceu!\n", carta2.nome_pais);
    } else {
        printf("Empate!\n");
    }

    return 0;
}