#include <stdio.h>
#include <string.h>

int main() {
    //---DECLARAÇÃO DE VARIÁVEIS---
    // Este bloco declara as variáveis que armazenarão os dados das duas cartas.
    // Usamos um array de caracteres para as strings e tipos de dados diferentes para cada tipo de informação.
    // Tamanho 4 na variavel codigo_da_carta para acomodar a string "A01" e o caractere nulo '\0'

    //Variáveis da carta 1
    char carta1[10] = "Carta 1"; 
    char estado1, codigo_da_carta1[4], nome_da_cidade1[50];
    int qtde_pontos_turisticos1;
    unsigned long int populacao1;
    float area1, pib1, pib_per_capita1, densidade_populacional1, super_poder1;

    //Variáveis da carta 2
    char carta2[10] = "Carta 2"; 
    char estado2, codigo_da_carta2[4], nome_da_cidade2[50];
    int qtde_pontos_turisticos2;
    unsigned long int populacao2;
    float area2, pib2, pib_per_capita2, densidade_populacional2, super_poder2;

    //Coleta do usuário as informações sobre as cartas
    //O espaço antes do "%c" é para evitar problemas com o enter do comando anterior
    //getchar limpa o buffer, para evitar problemas com "\n" (enter anterior)
    //printf("\n") está sendo usado apenas para melhorar a visualização

    //Carta 1
    printf("Digite a seguir os dados da carta 1\n");
    printf("Letra do seu estado (de 'A' a 'H'): ");
    scanf(" %c", &estado1);

    printf("Código da carta (letra do estado seguida de um número de 01 a 04. Ex.: A01, B02): ");
    scanf("%s", codigo_da_carta1);
    getchar();

    printf("Nome da cidade: ");
    fgets(nome_da_cidade1, sizeof(nome_da_cidade1), stdin); //Permite incluir nomes compostos
    nome_da_cidade1[strcspn(nome_da_cidade1, "\n")] = 0; //Remove a quebra de linha "\n" do final

    printf("Número de habitantes (Ex.: 300000 sem '.' e ','): ");
    scanf("%lu", &populacao1);
    getchar();

    printf("Área da cidade (em km²): ");
    scanf("%f", &area1);
    getchar();

    printf("O PIB da cidade em bilhões de reais: ");
    scanf("%f", &pib1);
    getchar();

    printf("Quantidade de pontos turísticos: ");
    scanf("%i", &qtde_pontos_turisticos1);
    getchar();

    pib_per_capita1 = (pib1 * 1000000000) / (float) populacao1;
    densidade_populacional1 = (float) populacao1 / area1;
    super_poder1 = (float) populacao1 + area1 + pib1 + (float) qtde_pontos_turisticos1 + pib_per_capita1 - densidade_populacional1;

    printf("\n"); // Cria uma linha em branco
    
    //Carta 2
    printf("Digite a seguir os dados da carta 2\n");
    printf("\nLetra do seu estado (de 'A' a 'H'): ");
    scanf(" %c", &estado2);

    printf("Código da carta (letra do estado seguida de um número de 01 a 04. Ex.: A01, B02): ");
    scanf("%s", codigo_da_carta2);
    getchar();

    printf("Nome da cidade: ");
    fgets(nome_da_cidade2, sizeof(nome_da_cidade2), stdin); //Permite incluir nomes compostos
    nome_da_cidade2[strcspn(nome_da_cidade2, "\n")] = 0; //Impede que o nome da cidade finalize com um espaço no final

    printf("Número de habitantes (Ex.: 300000 sem '.' e ','): ");
    scanf("%lu", &populacao2);
    getchar();

    printf("Área da cidade (em km²): ");
    scanf("%f", &area2);
    getchar();

    printf("O PIB da cidade em bilhões de reais: ");
    scanf("%f", &pib2);
    getchar();

    printf("Quantidade de pontos turísticos: ");
    scanf("%i", &qtde_pontos_turisticos2);
    getchar();

    printf("\n");

    pib_per_capita2 = (pib2 * 1000000000)/ (float) populacao2;
    densidade_populacional2 = (float) populacao2 / area2;
    super_poder2 = (float) populacao2 + area2 + pib2 + (float) qtde_pontos_turisticos2 + pib_per_capita2 - densidade_populacional2;

    //---EXIBIÇÃO DAS INFORMAÇÕES SOBRE AS CARTAS
    //Imprime na tela todas as informações de cada carta para o usuário.
    // O `%.2f` é usado para formatar os valores de ponto flutuante com duas casas decimais.
    
    //CARTA 1
    printf("Segue abaixo as informações da %s: \n", carta1);
    printf("\n");
    printf("Estado: %c \n", estado1);
    printf("Código: %s \n", codigo_da_carta1);
    printf("Nome da cidade: %s \n", nome_da_cidade1);
    printf("População: %lu \n", populacao1);
    printf("Área: %.2f km²\n", area1);
    printf("PIB: %.2f bilhões de reais\n", pib1);
    printf("Números de pontos turísticos: %i \n", qtde_pontos_turisticos1);
    printf("Densidade Populacional: %.2f hab/km² \n", densidade_populacional1);
    printf("PIB per Capita: %.2f reais \n", pib_per_capita1); 
    printf("\n");

    //CARTA 2
    printf("Segue abaixo as informações da %s: \n", carta2);
    printf("\n");
    printf("Estado: %c \n", estado2);
    printf("Código: %s \n", codigo_da_carta2);
    printf("Nome da cidade: %s \n", nome_da_cidade2);
    printf("População: %lu \n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %.2f bilhões de reais\n", pib2);
    printf("Números de pontos turísticos: %i \n", qtde_pontos_turisticos2);
    printf("Densidade Populacional: %.2f hab/km² \n", densidade_populacional2);
    printf("PIB per Capita: %.2f reais \n", pib_per_capita2);
    printf("\n");

    //---MENU E COMPARAÇÃO ENTRE AS CARTAS---
    int opcao1, opcao2; 
    float valor_atributo1_carta1, valor_atributo1_carta2, valor_atributo2_carta1, valor_atributo2_carta2;
    float soma_atributos_carta1 = 0, soma_atributos_carta2 = 0;
    char atributo1[35], atributo2[35];

    //Menu de interação com o usuário para a escolha do atributo
    // Observação: a densidade populacional é considerada um fator negativo.
    // Se o jogador escolher apenas densidade, vence quem tiver menor valor (por isso subtraímos).
    // Se o jogador escolher super poder, a densidade já é levada em conta negativamente no cálculo.

    printf("COMPARAÇAÕ ENTRE AS CARTAS\n");
    printf("\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Número de pontos turisticos\n");
    printf("5 - Densidade demográfica\n");
    printf("6 - Super Poder\n");
    printf("Escolha a seguir dois atributos para comparar.\n");
    printf("Atributo 1: ");
    scanf("%d", &opcao1);
    printf("Atributo 2: ");
    scanf("%d", &opcao2);
    printf("\n");

    //Condicional para impedir a escolha do mesmo atributo 
    if (opcao1 == opcao2){
        printf("Opção invalida, escolha opções diferentes.\n");
    }else if(opcao1 < 0 || opcao1 > 6){
        printf("Atributo 1 inválido! Escolha uma opção entre 1 e 5.\n"); 
    }else if(opcao2 < 0 || opcao2 > 6){
        printf("Atributo 2 inválido! Escolha uma opção entre 1 e 5.\n");
    }else{  
        //Atribuição de valores para variaveis globias de acordo com a opção escolhida
        switch (opcao1){
            case 1:
                valor_atributo1_carta1 = populacao1;
                valor_atributo1_carta2 = populacao2;
                soma_atributos_carta1 += (float)populacao1;
                soma_atributos_carta2 += (float)populacao2;
                strcpy(atributo1, "População");      
                break;
            case 2:
                valor_atributo1_carta1 = area1;
                valor_atributo1_carta2 = area2;
                soma_atributos_carta1 += area1;
                soma_atributos_carta2 += area2;
                strcpy(atributo1, "Área");      
                break;
            case 3:
                valor_atributo1_carta1 = pib1;
                valor_atributo1_carta2 = pib2;
                soma_atributos_carta1 += pib1;
                soma_atributos_carta2 += pib2;
                strcpy(atributo1, "PIB");      
                break;
            case 4:
                valor_atributo1_carta1 = qtde_pontos_turisticos1;
                valor_atributo1_carta2 = qtde_pontos_turisticos2;
                soma_atributos_carta1 += qtde_pontos_turisticos1;
                soma_atributos_carta2 += qtde_pontos_turisticos2;
                strcpy(atributo1, "Pontos Turísticos");      
                break;
            case 5:
                valor_atributo1_carta1 = densidade_populacional1;
                valor_atributo1_carta2 = densidade_populacional2;
                soma_atributos_carta1 -= densidade_populacional1;
                soma_atributos_carta2 -= densidade_populacional2;
                strcpy(atributo1, "Densidade Populacional");      
                break;
            case 6:
                valor_atributo1_carta1 = super_poder1;
                valor_atributo1_carta2 = super_poder2;
                soma_atributos_carta1 += super_poder1;
                soma_atributos_carta2 += super_poder2;
                strcpy(atributo1, "Super Poder");      
                break;
        }
        switch (opcao2){
            case 1:
                valor_atributo2_carta1 = populacao1;
                valor_atributo2_carta2 = populacao2;
                soma_atributos_carta1 += populacao1;
                soma_atributos_carta2 += populacao2;
                strcpy(atributo2, "População");      
                break;
            case 2:
                valor_atributo2_carta1 = area1;
                valor_atributo2_carta2 = area2;
                soma_atributos_carta1 += area1;
                soma_atributos_carta2 += area2;
                strcpy(atributo2, "Área");      
                break;
            case 3:
                valor_atributo2_carta1 = pib1;
                valor_atributo2_carta2 = pib2;
                soma_atributos_carta1 += pib1;
                soma_atributos_carta2 += pib2;
                strcpy(atributo2, "PIB");      
                break;
            case 4:
                valor_atributo2_carta1 = qtde_pontos_turisticos1;
                valor_atributo2_carta2 = qtde_pontos_turisticos2;
                soma_atributos_carta1 += qtde_pontos_turisticos1;
                soma_atributos_carta2 += qtde_pontos_turisticos2;
                strcpy(atributo2, "Pontos Turísticos");      
                break;
            case 5:
                valor_atributo2_carta1 = densidade_populacional1;
                valor_atributo2_carta2 = densidade_populacional2;
                soma_atributos_carta1 -= densidade_populacional1;
                soma_atributos_carta2 -= densidade_populacional2;
                strcpy(atributo2, "Densidade Populacional");      
                break;
            case 6:
                valor_atributo1_carta1 = super_poder1;
                valor_atributo1_carta2 = super_poder2;
                soma_atributos_carta1 += super_poder1;
                soma_atributos_carta2 += super_poder2;
                strcpy(atributo2, "Super Poder");      
                break;
        }

        //Visualização final de cada atributo e seu valor e a soma dos atributos

        printf("=================================================================\n");    
        printf("|              CONFRONTO DE CIDADES (SUPER TRUNFO)              |\n");
        printf("=================================================================\n");
        printf("\n");
        printf("+---------------------------------------------------------------+\n");
        printf("| Carta 1: %s\n", nome_da_cidade1);
        printf("+---------------------------------------------------------------+\n");
        printf("| ATRIBUTOS:                                                    |\n");
        printf("| ------------------------------------------------------------- |\n");
        printf("| 1. %s: %.2f\n", atributo1, valor_atributo1_carta1);
        printf("| 2. %s: %.2f\n", atributo2, valor_atributo2_carta1);
        printf("| ------------------------------------------------------------- |\n");
        printf("| SOMA DOS ATRIBUTOS: %.2f\n", soma_atributos_carta1);
        printf("+---------------------------------------------------------------+\n");
        printf("\n");
        printf("+---------------------------------------------------------------+\n");
        printf("| Carta 2: %s\n", nome_da_cidade2);
        printf("+---------------------------------------------------------------+\n");
        printf("| ATRIBUTOS:                                                    |\n");
        printf("| ------------------------------------------------------------- |\n");
        printf("| 1. %s: %.2f\n", atributo1, valor_atributo1_carta2);
        printf("| 2. %s: %.2f\n", atributo2, valor_atributo2_carta2);
        printf("| ------------------------------------------------------------- |\n");
        printf("| SOMA DOS ATRIBUTOS: %.2f\n", soma_atributos_carta2);
        printf("+---------------------------------------------------------------+\n");
        
        if (soma_atributos_carta1 == soma_atributos_carta2){
            printf("Empate entre as cidades de %s e %s!", nome_da_cidade1, nome_da_cidade2);
        }else {
            if(soma_atributos_carta1 > soma_atributos_carta2){
                printf("%s foi a vencedora!", nome_da_cidade1);
            }else{
                printf("%s foi a vencedora!", nome_da_cidade2);
            }
        }
    }
    return 0;
}