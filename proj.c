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
    printf("Estado (completo, em andamento ou não iniciado): ");
    scanf("%19s", armazena->estado);
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
        case 4:
            printf("Novo Estado (completo, em andamento ou não iniciado): ");
            scanf("%19s", tarefa->estado);
            limpa();
            break;
        default:
            printf("Opção inválida!\n\n");
    }
}



void filtrar_por_prioridade(struct Tarefa *tarefas, int cont) {
    int prioridade_filtro;
    printf("Digite a prioridade para filtrar: ");
    scanf("%d", &prioridade_filtro);
    limpa();

    printf("Tarefas com prioridade %d:\n", prioridade_filtro);
    for (int i = 0; i < cont; i++) {
        if (tarefas[i].prioridade == prioridade_filtro) {
            printf("Tarefa %d\n", i + 1);
            printf("Prioridade: %d\n", tarefas[i].prioridade);
            printf("Categoria: %s\n", tarefas[i].categoria);
            printf("Descricao: %s\n\n", tarefas[i].descricao);
        }
    }
}

void filtrar_por_estado(struct Tarefa *tarefas, int cont) {
    char estado_filtro[20];
    printf("Digite o estado para filtrar: ");
    fgets(estado_filtro, sizeof(estado_filtro), stdin);
    limpa();

    printf("Tarefas com estado %s:\n", estado_filtro);
    for (int i = 0; i < cont; i++) {
        if (strcmp(tarefas[i].estado, estado_filtro) == 0) {
            printf("Tarefa %d\n", i + 1);
            printf("Prioridade: %d\n", tarefas[i].prioridade);
            printf("Categoria: %s\n", tarefas[i].categoria);
            printf("Descricao: %s\n\n", tarefas[i].descricao);
        }
    }
}

void filtrar_por_categoria(struct Tarefa *tarefas, int cont) {
    char categoria_filtro[100];
    printf("Digite a categoria para filtrar: ");
    fgets(categoria_filtro, sizeof(categoria_filtro), stdin);
    limpa();

    printf("Tarefas na categoria %s:\n", categoria_filtro);
    for (int i = 0; i < cont; i++) {
        if (strcmp(tarefas[i].categoria, categoria_filtro) == 0) {
            printf("Tarefa %d\n", i + 1);
            printf("Prioridade: %d\n", tarefas[i].prioridade);
            printf("Categoria: %s\n", tarefas[i].categoria);
            printf("Descricao: %s\n\n", tarefas[i].descricao);
        }
    }
}

void filtrar_por_prioridade_categoria(struct Tarefa *tarefas, int cont) {
    int prioridade_filtro;
    char categoria_filtro[100];
    printf("Digite a prioridade para filtrar: ");
    scanf("%d", &prioridade_filtro);
    limpa();

    printf("Digite a categoria para filtrar: ");
    fgets(categoria_filtro, sizeof(categoria_filtro), stdin);
    limpa();

    printf("Tarefas com prioridade %d e categoria %s:\n", prioridade_filtro, categoria_filtro);
    for (int i = 0; i < cont; i++) {
        if (tarefas[i].prioridade == prioridade_filtro && strcmp(tarefas[i].categoria, categoria_filtro) == 0) {
            printf("Tarefa %d\n", i + 1);
            printf("Prioridade: %d\n", tarefas[i].prioridade);
            printf("Categoria: %s\n", tarefas[i].categoria);
            printf("Descricao: %s\n\n", tarefas[i].descricao);
        }
    }
}
