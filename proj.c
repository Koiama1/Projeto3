#include "proj.h"
#include <stdio.h>
//Antigo membros do grupo do projeto 1:
//João Pedro Lopes - RA: 24.123.071-3
//João Pedro Peterutto - RA: 24.123.045-7

//Criador desse projeto 3:
//Gabriel Koiama - RA: 24.123.051-5

void limpa() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

void ler(struct Tarefa *armazena) {
    printf("Prioridade: ");
    scanf("%d", &armazena->prioridade);
    limpa();
    printf("Descricao: ");
    scanf("%299[^\n]", armazena->descricao);
    limpa();
    printf("Categoria: ");
    scanf("%99[^\n]", armazena->categoria);
    limpa();
}

void excluir_tarefa(struct Tarefa *tarefas, int *cont, int posicao) {
    if (posicao >= 1 && posicao <= *cont) {
        for (int i = posicao - 1; i < *cont - 1; i++) {
            tarefas[i] = tarefas[i + 1];
        }
        (*cont)--;
        printf("Tarefa deletada\n\n");
    } else {
        printf("Posição inválida!\n\n");
    }
}

void alterar_tarefa(struct Tarefa *tarefa, int opcao) {
    switch (opcao) {
        case 1:
            printf("Nova Prioridade: ");
            scanf("%d", &tarefa->prioridade);
            limpa();
            break;
        case 2:
            printf("Nova Categoria: ");
            scanf("%99[^\n]", tarefa->categoria);
            limpa();
            break;
        case 3:
            printf("Nova Descrição: ");
            scanf("%299[^\n]", tarefa->descricao);
            limpa();
            break;
        default:
            printf("Opção inválida!\n\n");
    }
}
