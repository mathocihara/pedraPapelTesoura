#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct cadastro {
    char nome[100];
    int idade;
};
    struct cadastro jogador;

// função login
void login(struct cadastro *p ){

    printf("Qual seu nome: ");
    scanf(" %[^\n]", p->nome);
    printf("Qual sua idade: ");
    scanf("%d", &p->idade);

}

// Função para mostrar o desenho do arquivo

void mostrarDesenho(const char* nome)
{
    char caminho[400];

    // Caminho da pasta das imagens
sprintf(caminho, "imagens\\%s.txt", nome);


    FILE* f = fopen(caminho, "r");
    if (!f) {
        printf("Erro ao abrir arquivo: %s\n", caminho);
        return;
    }

    char linha[300];
    while (fgets(linha, sizeof(linha), f)) {
        printf("%s", linha);
    }

    fclose(f);
}

// Função para gerar jogada aleatória do computador(falta break)
const char* jogadaComputador() {
    int r = rand() % 3;
    switch (r) {
        case 0: return "pedra";
        case 1: return "papel";
        case 2: return "tesoura";
        default: return "pedra"; // fallback seguro
    }
}

// Função para decidir o vencedor
const char* vencedor(const char* jogador, const char* computador) {
    if (strcmp(jogador, computador) == 0) return "Empate";
    if ((strcmp(jogador, "pedra") == 0 && strcmp(computador, "tesoura") == 0) ||
        (strcmp(jogador, "papel") == 0 && strcmp(computador, "pedra") == 0) ||
        (strcmp(jogador, "tesoura") == 0 && strcmp(computador, "papel") == 0)) {
        return "Jogador venceu";
    }
    return "Computador venceu";
}

// Função recursiva para jogar novamente
void jogar(int* totalPartidas, char*** historico, int* pontosJogador, int* pontosComputador, int* empates) {
    char escolha[20];
    printf("\nDigite sua jogada (pedra/papel/tesoura): ");
    scanf("%s", escolha);

    // Validar entrada do jogador
    while (strcmp(escolha, "pedra") != 0 && strcmp(escolha, "papel") != 0 && strcmp(escolha, "tesoura") != 0) {
        printf("Opção inválida! Digite novamente (pedra/papel/tesoura): ");
        scanf("%s", escolha);
    }

    const char* comp = jogadaComputador();
    const char* resultado = vencedor(escolha, comp);

    // Mostrar jogadas
    printf("\n %s escolheu: %s\n", jogador.nome, escolha);
    mostrarDesenho(escolha);

    printf("\nComputador escolheu: %s\n", comp);
    mostrarDesenho(comp);

    printf("\nResultado: %s\n", resultado);

    // Atualiza placar
    if (strcmp(resultado, "Jogador venceu") == 0) (*pontosJogador)++;
    else if (strcmp(resultado, "Computador venceu") == 0) (*pontosComputador)++;
    else (*empates)++;

    // Mostra placar
    printf("\nPlacar:\n %s: %d | Computador: %d | Empates: %d\n", jogador.nome, *pontosJogador, *pontosComputador, *empates);

    // Armazena histórico
    (*totalPartidas)++;
    *historico = realloc(*historico, (*totalPartidas) * sizeof(char*));
    (*historico)[*totalPartidas - 1] = malloc(100 * sizeof(char));
    sprintf((*historico)[*totalPartidas - 1], "%s: %s | Computador: %s | %s", jogador.nome, escolha, comp, resultado);

    // Pergunta se deseja continuar
char resposta[10];

while (1) {
    printf("\nDeseja jogar novamente, %s? (sim/nao): ", jogador.nome);
    scanf("%s", resposta);

    if (strcmp(resposta, "sim") == 0) {
        jogar(totalPartidas, historico, pontosJogador, pontosComputador, empates);
        break;
    }
    else if (strcmp(resposta, "nao") == 0 || strcmp(resposta, "não") == 0) {
        printf("\nEncerrando o jogo...\n");
        return; // sai da função e volta ao main
    }
    else {
        printf("Resposta inválida! Tente novamente.\n");
    }
}
}

// Função para salvar histórico e placar em arquivo
void salvarArquivo(int totalPartidas, char** historico, int pontosJogador, int pontosComputador, int empates) {
    FILE* f = fopen("historico.txt", "w");
    if (!f) {
        printf("Erro ao abrir arquivo!\n");
        return;
    }

    for (int i = 0; i < totalPartidas; i++) {
        fprintf(f, "%s\n", historico[i]);
    }

    fprintf(f, "\nPlacar final:\n %s: %d\nComputador: %d\nEmpates: %d\n", jogador.nome, pontosJogador, pontosComputador, empates);
    fclose(f);

    printf("\nHistórico e placar salvos em 'historico.txt'.\n");
}


int main() {


    login(&jogador);
    srand(time(NULL));

    int totalPartidas = 0;
    char** historico = NULL;
    int pontosJogador = 0, pontosComputador = 0, empates = 0;

    printf("=== Jogo Pedra, Papel e Tesoura ===\n");

    jogar(&totalPartidas, &historico, &pontosJogador, &pontosComputador, &empates);

    salvarArquivo(totalPartidas, historico, pontosJogador, pontosComputador, empates);

    // Liberar memória
    for (int i = 0; i < totalPartidas; i++) {
        free(historico[i]);
    }
    free(historico);

    printf("\nObrigado por jogar %s!\n", jogador.nome);
    return 0;
}
