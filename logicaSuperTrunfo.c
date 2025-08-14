#include <stdio.h>
#include <string.h>
#include <ctype.h> // Para a função tolower()

// Definição da estrutura para a carta de cidade
struct Carta {
    char estado[50];
    char codigo[10];
    char cidade[50];
    long populacao;
    double area;
    double pib;
    int pontos_turisticos;
    double densidade_populacional;
};

// Função para limpar o buffer de entrada
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Função para exibir os dados de uma carta
void exibirCarta(struct Carta carta) {
    printf("---------------------------------------\n");
    printf("Carta: %s\n", carta.cidade);
    printf("Codigo: %s\n", carta.codigo);
    printf("Estado: %s\n", carta.estado);
    printf("Populacao: %ld\n", carta.populacao);
    printf("Area (km2): %.2f\n", carta.area);
    printf("PIB (milhoes): %.2f\n", carta.pib);
    printf("Pontos Turisticos: %d\n", carta.pontos_turisticos);
    printf("---------------------------------------\n");
}

// Função para o Nível Novato
void jogarNovato() {
    struct Carta carta1, carta2;
    int escolha_atributo;
    
    printf("\n--- Super Trunfo - Nivel Novato ---\n");
    printf("Regras: Maior valor vence, exceto em Densidade Populacional (menor vence).\n\n");
    
    // Cadastro da Primeira Carta
    printf("--- Cadastro da Primeira Carta ---\n");
    printf("Estado (sem espacos): ");
    scanf("%s", carta1.estado);
    printf("Codigo da Carta (sem espacos): ");
    scanf("%s", carta1.codigo);
    printf("Nome da Cidade (sem espacos): ");
    scanf("%s", carta1.cidade);
    printf("Populacao (apenas numeros): ");
    scanf("%ld", &carta1.populacao);
    printf("Area em km2 (apenas numeros): ");
    scanf("%lf", &carta1.area);
    printf("PIB em milhoes (apenas numeros): ");
    scanf("%lf", &carta1.pib);
    printf("Pontos Turisticos (apenas numeros): ");
    scanf("%d", &carta1.pontos_turisticos);
    limparBuffer(); 
    
    // Calcula a densidade populacional
    carta1.densidade_populacional = carta1.populacao / carta1.area;
    
    printf("\n--- Cadastro da Segunda Carta ---\n");
    printf("Estado (sem espacos): ");
    scanf("%s", carta2.estado);
    printf("Codigo da Carta (sem espacos): ");
    scanf("%s", carta2.codigo);
    printf("Nome da Cidade (sem espacos): ");
    scanf("%s", carta2.cidade);
    printf("Populacao (apenas numeros): ");
    scanf("%ld", &carta2.populacao);
    printf("Area em km2 (apenas numeros): ");
    scanf("%lf", &carta2.area);
    printf("PIB em milhoes (apenas numeros): ");
    scanf("%lf", &carta2.pib);
    printf("Pontos Turisticos (apenas numeros): ");
    scanf("%d", &carta2.pontos_turisticos);
    limparBuffer();
    
    carta2.densidade_populacional = carta2.populacao / carta2.area;

    printf("\n--- Cartas Cadastradas ---\n");
    exibirCarta(carta1);
    exibirCarta(carta2);

    // Menu de escolha do atributo
    printf("\n--- Escolha o atributo para a batalha! ---\n");
    printf("1 - Populacao\n");
    printf("2 - Area\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turisticos\n");
    printf("5 - Densidade Populacional (menor valor vence!)\n");
    printf("Sua escolha: ");
    scanf("%d", &escolha_atributo);
    limparBuffer();

    printf("\n--- Resultado da Comparacao ---\n");
    
    // Lógica de comparação com base na escolha do usuário
    switch (escolha_atributo) {
        case 1: // Populacao
            printf("Atributo: Populacao\n");
            if (carta1.populacao > carta2.populacao) {
                printf("Vencedora: %s\n", carta1.cidade);
            } else if (carta2.populacao > carta1.populacao) {
                printf("Vencedora: %s\n", carta2.cidade);
            } else {
                printf("Empate!\n");
            }
            break;
        case 2: // Area
            printf("Atributo: Area\n");
            if (carta1.area > carta2.area) {
                printf("Vencedora: %s\n", carta1.cidade);
            } else if (carta2.area > carta1.area) {
                printf("Vencedora: %s\n", carta2.cidade);
            } else {
                printf("Empate!\n");
            }
            break;
        case 3: // PIB
            printf("Atributo: PIB\n");
            if (carta1.pib > carta2.pib) {
                printf("Vencedora: %s\n", carta1.cidade);
            } else if (carta2.pib > carta1.pib) {
                printf("Vencedora: %s\n", carta2.cidade);
            } else {
                printf("Empate!\n");
            }
            break;
        case 4: // Pontos Turisticos
            printf("Atributo: Pontos Turisticos\n");
            if (carta1.pontos_turisticos > carta2.pontos_turisticos) {
                printf("Vencedora: %s\n", carta1.cidade);
            } else if (carta2.pontos_turisticos > carta1.pontos_turisticos) {
                printf("Vencedora: %s\n", carta2.cidade);
            } else {
                printf("Empate!\n");
            }
            break;
        case 5: // Densidade Populacional (menor valor vence!)
            printf("Atributo: Densidade Populacional\n");
            if (carta1.densidade_populacional < carta2.densidade_populacional) {
                printf("Vencedora: %s\n", carta1.cidade);
            } else if (carta2.densidade_populacional < carta1.densidade_populacional) {
                printf("Vencedora: %s\n", carta2.cidade);
            } else {
                printf("Empate!\n");
            }
            break;
        default:
            printf("Escolha invalida. O jogo foi encerrado.\n");
            break;
    }
}

int main() {
    int opcao;
    
    printf("=======================================\n");
    printf("=   Bem-vindo ao Super Trunfo - Paises  =\n");
    printf("=======================================\n");
    printf("1. Jogar Nivel Novato\n");
    printf("2. Sair\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);
    limparBuffer();
    
    if (opcao == 1) {
        jogarNovato();
    } else {
        printf("Obrigado por jogar!\n");
    }
    
    return 0;
}
