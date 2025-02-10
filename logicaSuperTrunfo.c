#include <stdio.h>
#include <string.h>

// Definição da estrutura para a carta de cidade
typedef struct {
    char estado;            // Letra do estado (A-H)
    int cidade;             // Número da cidade (1-4)
    char nome[50];          // Nome da cidade
    long populacao;         // População da cidade
    float area;             // Área da cidade em km²
    float pib;              // PIB da cidade em bilhões
    int pontos_turisticos;  // Número de pontos turísticos
} Carta;

// Função para cadastrar uma carta
void cadastrarCarta(Carta *carta) {
    printf("Digite o estado (A-H): ");
    scanf(" %c", &carta->estado);  // Espaco antes de %c para ignorar o newline
    printf("Digite o número da cidade (1-4): ");
    scanf("%d", &carta->cidade);
    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", carta->nome);  // Lê a linha inteira com espaços
    printf("Digite a população da cidade: ");
    scanf("%ld", &carta->populacao);
    printf("Digite a área da cidade (em km²): ");
    scanf("%f", &carta->area);
    printf("Digite o PIB da cidade (em bilhões): ");
    scanf("%f", &carta->pib);
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &carta->pontos_turisticos);
}

// Função para exibir os dados da carta
void exibirCarta(Carta carta) {
    printf("\nInformações da Carta %c%02d - %s:\n", carta.estado, carta.cidade, carta.nome);
    printf("População: %ld\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f bilhões\n", carta.pib);
    printf("Pontos turísticos: %d\n", carta.pontos_turisticos);
}

// Função para comparar duas cartas com base em um atributo
void compararCartas(Carta carta1, Carta carta2, int atributo) {
    int vencedor = 0;  // 0 para empate, 1 para carta1 vence, 2 para carta2 vence

    switch (atributo) {
        case 1: // Comparar população
            if (carta1.populacao > carta2.populacao) {
                vencedor = 1;
            } else if (carta1.populacao < carta2.populacao) {
                vencedor = 2;
            }
            break;
        case 2: // Comparar área
            if (carta1.area > carta2.area) {
                vencedor = 1;
            } else if (carta1.area < carta2.area) {
                vencedor = 2;
            }
            break;
        case 3: // Comparar PIB
            if (carta1.pib > carta2.pib) {
                vencedor = 1;
            } else if (carta1.pib < carta2.pib) {
                vencedor = 2;
            }
            break;
        case 4: // Comparar pontos turísticos
            if (carta1.pontos_turisticos > carta2.pontos_turisticos) {
                vencedor = 1;
            } else if (carta1.pontos_turisticos < carta2.pontos_turisticos) {
                vencedor = 2;
            }
            break;
        case 5: // Comparar densidade populacional (menor vence)
            float densidade1 = (float)carta1.populacao / carta1.area;
            float densidade2 = (float)carta2.populacao / carta2.area;
            if (densidade1 < densidade2) {
                vencedor = 1;
            } else if (densidade1 > densidade2) {
                vencedor = 2;
            }
            break;
        default:
            printf("Atributo inválido!\n");
            return;
    }

    // Exibir o vencedor
    if (vencedor == 0) {
        printf("\nEmpate entre as cartas!\n");
    } else if (vencedor == 1) {
        printf("\nA carta %c%02d - %s venceu!\n", carta1.estado, carta1.cidade, carta1.nome);
    } else {
        printf("\nA carta %c%02d - %s venceu!\n", carta2.estado, carta2.cidade, carta2.nome);
    }
}

int main() {
    Carta carta1, carta2;
    int atributo;

    // Cadastro das cartas
    printf("Cadastro da primeira carta:\n");
    cadastrarCarta(&carta1);
    exibirCarta(carta1);

    printf("\nCadastro da segunda carta:\n");
    cadastrarCarta(&carta2);
    exibirCarta(carta2);

    // Escolher o atributo para comparação
    printf("\nEscolha o atributo para comparação:\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Pontos turísticos\n");
    printf("5. Densidade populacional (menor vence)\n");
    printf("Digite o número do atributo: ");
    scanf("%d", &atributo);

    // Comparação das cartas
    compararCartas(carta1, carta2, atributo);

    return 0;
}