#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Definição da estrutura para a carta de cidade
typedef struct {
    char estado[50];
    char codigo[10];
    char cidade[50];
    long populacao;
    double area;
    double pib;
    int pontos_turisticos;
    double densidade_populacional;
} Carta;

// --- Funções Auxiliares (Comuns a todos os níveis) ---

// Função para limpar o buffer de entrada
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Função para exibir os dados de uma carta
void exibirCarta(Carta carta) {
    printf("---------------------------------------\n");
    printf("Carta: %s\n", carta.cidade);
    printf("Codigo: %s\n", carta.codigo);
    printf("Estado: %s\n", carta.estado);
    printf("Populacao: %ld\n", carta.populacao);
    printf("Area (km2): %.2f\n", carta.area);
    printf("PIB (milhoes): %.2f\n", carta.pib);
    printf("Pontos Turisticos: %d\n", carta.pontos_turisticos);
    if (carta.area > 0) {
        printf("Densidade Populacional: %.2f hab/km2\n", carta.densidade_populacional);
    }
    printf("---------------------------------------\n");
}

// Função para cadastrar uma carta
void cadastrarCarta(Carta *carta) {
    printf("Estado (sem espacos): ");
    scanf("%s", carta->estado);
    printf("Codigo da Carta (sem espacos): ");
    scanf("%s", carta->codigo);
    printf("Nome da Cidade (sem espacos): ");
    scanf("%s", carta->cidade);
    printf("Populacao (apenas numeros): ");
    scanf("%ld", &carta->populacao);
    printf("Area em km2 (apenas numeros): ");
    scanf("%lf", &carta->area);
    printf("PIB em milhoes (apenas numeros): ");
    scanf("%lf", &carta->pib);
    printf("Pontos Turisticos (apenas numeros): ");
    scanf("%d", &carta->pontos_turisticos);
    limparBuffer(); 
    
    // Calcula a densidade populacional
    if (carta->area > 0) {
        carta->densidade_populacional = carta->populacao / carta->area;
    } else {
        carta->densidade_populacional = 0;
    }
}

// --- Nível Novato (if-else simples) ---
void jogarNovato() {
    Carta carta1, carta2;
    
    printf("\n--- Super Trunfo - Nivel Novato ---\n");
    printf("Regra: Maior Populacao Vence!\n\n");
    
    // Cadastro
    printf("--- Cadastro da Primeira Carta ---\n");
    cadastrarCarta(&carta1);
    
    printf("\n--- Cadastro da Segunda Carta ---\n");
    cadastrarCarta(&carta2);
    
    // Exibição
    printf("\n--- Cartas Cadastradas ---\n");
    exibirCarta(carta1);
    exibirCarta(carta2);
    
    // Comparação (fixa)
    printf("\n--- Resultado da Comparacao ---\n");
    if (carta1.populacao > carta2.populacao) {
        printf("A carta vencedora e: %s\n", carta1.cidade);
    } else if (carta2.populacao > carta1.populacao) {
        printf("A carta vencedora e: %s\n", carta2.cidade);
    } else {
        printf("As cartas empataram!\n");
    }
}

// --- Nível Aventureiro (switch-case e lógica de densidade) ---
void jogarAventureiro() {
    Carta carta1, carta2;
    int escolha;
    
    printf("\n--- Super Trunfo - Nivel Aventureiro ---\n");
    printf("Regras: Maior valor vence, exceto em Densidade Populacional (menor vence).\n\n");
    
    // Cadastro
    printf("--- Cadastro da Primeira Carta ---\n");
    cadastrarCarta(&carta1);
    
    printf("\n--- Cadastro da Segunda Carta ---\n");
    cadastrarCarta(&carta2);
    
    // Menu
    printf("\n--- Escolha o atributo para a batalha! ---\n");
    printf("1 - Populacao\n");
    printf("2 - Area\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turisticos\n");
    printf("5 - Densidade Populacional\n");
    printf("Sua escolha: ");
    scanf("%d", &escolha);
    limparBuffer();

    printf("\n--- Resultado da Comparacao ---\n");
    
    switch (escolha) {
        case 1:
            printf("Atributo: Populacao\n");
            if (carta1.populacao > carta2.populacao) printf("Vencedora: %s\n", carta1.cidade);
            else if (carta2.populacao > carta1.populacao) printf("Vencedora: %s\n", carta2.cidade);
            else printf("Empate!\n");
            break;
        case 2:
            printf("Atributo: Area\n");
            if (carta1.area > carta2.area) printf("Vencedora: %s\n", carta1.cidade);
            else if (carta2.area > carta1.area) printf("Vencedora: %s\n", carta2.cidade);
            else printf("Empate!\n");
            break;
        case 3:
            printf("Atributo: PIB\n");
            if (carta1.pib > carta2.pib) printf("Vencedora: %s\n", carta1.cidade);
            else if (carta2.pib > carta1.pib) printf("Vencedora: %s\n", carta2.cidade);
            else printf("Empate!\n");
            break;
        case 4:
            printf("Atributo: Pontos Turisticos\n");
            if (carta1.pontos_turisticos > carta2.pontos_turisticos) printf("Vencedora: %s\n", carta1.cidade);
            else if (carta2.pontos_turisticos > carta1.pontos_turisticos) printf("Vencedora: %s\n", carta2.cidade);
            else printf("Empate!\n");
            break;
        case 5:
            printf("Atributo: Densidade Populacional\n");
            if (carta1.densidade_populacional < carta2.densidade_populacional) printf("Vencedora: %s\n", carta1.cidade);
            else if (carta2.densidade_populacional < carta1.densidade_populacional) printf("Vencedora: %s\n", carta2.cidade);
            else printf("Empate!\n");
            break;
        default:
            printf("Escolha invalida!\n");
            break;
    }
}

// --- Nível Mestre (Comparação de dois atributos com ternários) ---
// Função para comparar valores, considerando a regra da densidade
int comparar(int atributo, Carta c1, Carta c2) {
    if (atributo == 5) { // Densidade Populacional (menor vence)
        return (c1.densidade_populacional < c2.densidade_populacional) ? 1 : (c2.densidade_populacional < c1.densidade_populacional) ? 2 : 0;
    } else { // Maior valor vence
        switch(atributo) {
            case 1: return (c1.populacao > c2.populacao) ? 1 : (c2.populacao > c1.populacao) ? 2 : 0;
            case 2: return (c1.area > c2.area) ? 1 : (c2.area > c1.area) ? 2 : 0;
            case 3: return (c1.pib > c2.pib) ? 1 : (c2.pib > c1.pib) ? 2 : 0;
            case 4: return (c1.pontos_turisticos > c2.pontos_turisticos) ? 1 : (c2.pontos_turisticos > c1.pontos_turisticos) ? 2 : 0;
            default: return 0;
        }
    }
}

void jogarMestre() {
    Carta carta1, carta2;
    int escolha1, escolha2;
    
    printf("\n--- Super Trunfo - Nivel Mestre ---\n");
    printf("Regra: Maior valor vence, exceto Densidade Populacional.\n");
    printf("Comparacao de 2 atributos! O 1o. tem maior peso.\n\n");
    
    // Cadastro
    printf("--- Cadastro da Primeira Carta ---\n");
    cadastrarCarta(&carta1);
    
    printf("\n--- Cadastro da Segunda Carta ---\n");
    cadastrarCarta(&carta2);
    
    // Menus dinâmicos
    printf("\n--- Escolha 2 atributos para a batalha! ---\n");
    printf("1 - Populacao | 2 - Area | 3 - PIB | 4 - Pontos Turisticos | 5 - Densidade Populacional\n");
    printf("Escolha o 1o. atributo (maior peso): ");
    scanf("%d", &escolha1);
    limparBuffer();
    
    printf("Escolha o 2o. atributo (desempate): ");
    scanf("%d", &escolha2);
    limparBuffer();
    
    printf("\n--- Resultado da Comparacao ---\n");
    
    int resultado1 = comparar(escolha1, carta1, carta2);
    
    if (resultado1 != 0) {
        if (resultado1 == 1) printf("Vencedora: %s (pelo 1o. atributo)\n", carta1.cidade);
        else printf("Vencedora: %s (pelo 1o. atributo)\n", carta2.cidade);
    } else {
        printf("Empate no 1o. atributo. Comparando o 2o. atributo...\n");
        int resultado2 = comparar(escolha2, carta1, carta2);
        if (resultado2 != 0) {
            if (resultado2 == 1) printf("Vencedora: %s (pelo 2o. atributo)\n", carta1.cidade);
            else printf("Vencedora: %s (pelo 2o. atributo)\n", carta2.cidade);
        } else {
            printf("Empate geral!\n");
        }
    }
}

// --- Menu Principal (main) ---
int main() {
    int nivel;

    printf("===================================================\n");
    printf("=   Bem-vindo ao Desafio Super Trunfo - Paises  =\n");
    printf("===================================================\n");
    
    do {
        printf("\nEscolha o nivel do desafio:\n");
        printf("1 - Novato (comparacao fixa)\n");
        printf("2 - Aventureiro (menu e switch-case)\n");
        printf("3 - Mestre (comparacao avancada)\n");
        printf("4 - Sair\n");
        printf("Sua escolha: ");
        scanf("%d", &nivel);
        limparBuffer();

        switch (nivel) {
            case 1:
                jogarNovato();
                break;
            case 2:
                jogarAventureiro();
                break;
            case 3:
                jogarMestre();
                break;
            case 4:
                printf("Obrigado por jogar!\n");
                return 0;
            default:
                printf("Opcao invalida. Por favor, tente novamente.\n");
                break;
        }
    } while (nivel != 4);

    return 0;
}