
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Definição da struct Item
typedef struct {
    char nome[30];
    char tipo[20];   // Ex: arma, munição, cura
    int quantidade;
} Item;

// Capacidade máxima da mochila
#define MAX_ITENS 10

// Vetor global para armazenar os itens
Item mochila[MAX_ITENS];
int totalItens = 0; // contador de itens na mochila

// Função para cadastrar um novo item
void inserirItem() {
    if (totalItens >= MAX_ITENS) {
        printf("\n⚠️ Mochila cheia! Não é possível adicionar mais itens.\n");
        return;
    }

    Item novo;
    printf("\nDigite o nome do item: ");
    scanf(" %[^\n]", novo.nome);  // lê até o enter
    printf("Digite o tipo do item (arma, munição, cura...): ");
    scanf(" %[^\n]", novo.tipo);
    printf("Digite a quantidade: ");
    scanf("%d", &novo.quantidade);

    mochila[totalItens] = novo;
    totalItens++;

    printf("\n Item adicionado com sucesso!\n");
}

// Função para remover um item pelo nome
void removerItem() {
    if (totalItens == 0) {
        printf("\n Mochila vazia! Nenhum item para remover.\n");
        return;
    }

    char nome[30];
    printf("\nDigite o nome do item que deseja remover: ");
    scanf(" %[^\n]", nome);

    int encontrado = -1;
    for (int i = 0; i < totalItens; i++) {
        if (strcmp(mochila[i].nome, nome) == 0) {
            encontrado = i;
            break;
        }
    }

    if (encontrado == -1) {
        printf("\n Item não encontrado!\n");
        return;
    }

    // Desloca os itens para "tapar o buraco"
    for (int i = encontrado; i < totalItens - 1; i++) {
        mochila[i] = mochila[i + 1];
    }
    totalItens--;

    printf("\n Item removido com sucesso!\n");
}

// Função para listar todos os itens
void listarItens() {
    if (totalItens == 0) {
        printf("\n  Mochila está vazia.\n");
        return;
    }

    printf("\n Itens na mochila:\n");
    for (int i = 0; i < totalItens; i++) {
        printf("%d. Nome: %s | Tipo: %s | Quantidade: %d\n",
               i + 1, mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
    }
}

// Função para buscar item pelo nome
void buscarItem() {
    if (totalItens == 0) {
        printf("\n  Mochila vazia! Nenhum item para buscar.\n");
        return;
    }

    char nome[30];
    printf("\nDigite o nome do item que deseja buscar: ");
    scanf(" %[^\n]", nome);

    for (int i = 0; i < totalItens; i++) {
        if (strcmp(mochila[i].nome, nome) == 0) {
            printf("\n🔎 Item encontrado!\n");
            printf("Nome: %s | Tipo: %s | Quantidade: %d\n",
                   mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
            return;
        }
    }

    printf("\n  Item não encontrado!\n");
}

// Função principal com menu
int main() {
    int opcao;

    do {
        printf("\n======  Sistema de Inventário ======\n");
        printf("1. Inserir item\n");
        printf("2. Remover item\n");
        printf("3. Listar itens\n");
        printf("4. Buscar item\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: inserirItem(); break;
            case 2: removerItem(); break;
            case 3: listarItens(); break;
            case 4: buscarItem(); break;
            case 0: printf("\n  Saindo do inventário. Até a próxima!\n"); break;
            default: printf("\n  Opção inválida!\n");
        }

    } while (opcao != 0);

    return 0;
}
