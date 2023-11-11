#include "proj.h"
#include <stdio.h>


void limpa() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}
//Está função cria uma tarefa e pede para voce escrever os dados dela
void ler(struct Tarefa *armazena) {
    printf("Prioridade: ");
    scanf("%d", &armazena->prioridade);
    limpa();
    printf("Descricao: ");
    scanf("%299[^\n]", armazena->descricao);
    limpa();
    printf("Categoria: ");
    scanf("%99[^\n]", armazena->categoria);
    

    
    printf("Estado (1 - Completo, 2 - Em andamento, 3 - Não iniciado): ");
    int escolha_estado;
    scanf("%d", &escolha_estado);
    limpa();

    switch (escolha_estado) {
        case 1:
            strcpy(armazena->estado, "Completo");
            break;
      
        case 2:
            strcpy(armazena->estado, "Em andamento");
            break;
      
        case 3:
            strcpy(armazena->estado, "Não iniciado");
            break;
      
        default:
            printf("Opção inválida para o estado!\n");
            break;
    }
}
//função para excluir uma tarefa em especifico
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
//função para alterar uma tarefa em especifico
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
//filtra uma lista com a especificação de prioridade
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
            printf("Descricao: %s\n", tarefas[i].descricao);
            printf("Estado: %s\n\n", tarefas[i].estado);
        }
    }
}
//filtra uma lista com a especificação de estado
void filtrar_por_estado(struct Tarefa *tarefas, int cont) {
  int escolha_estado;
  printf("Digite o número correspondente ao estado para filtrar (1 - Completo, 2 - Em andamento, 3 - Não iniciado): ");
  scanf("%d", &escolha_estado);
  limpa();

  char estado_filtro[20];

  switch (escolha_estado) {
    case 1:
      strcpy(estado_filtro, "Completo");
      break;
        
    case 2:
      strcpy(estado_filtro, "Em andamento");
      break;
        
    case 3:
      strcpy(estado_filtro, "Não iniciado");
      break;
        
    default:
      printf("Opção inválida para o estado!\n");
      return;
      }

  printf("Tarefas com estado %s:\n", estado_filtro);
    for (int i = 0; i < cont; i++) {
      if (strcmp(tarefas[i].estado, estado_filtro) == 0) {
        printf("Tarefa %d\n", i + 1);
        printf("Prioridade: %d\n", tarefas[i].prioridade);
        printf("Categoria: %s\n", tarefas[i].categoria);
        printf("Descricao: %s\n", tarefas[i].descricao);
        printf("Estado: %s\n\n", tarefas[i].estado);
          }
      }
  }
//filtra uma lista com a especificação de categoria
void filtrar_por_categoria(struct Tarefa *tarefas, int cont) {
    char categoria_filtro[100];
    printf("Digite a categoria para filtrar: ");
    fgets(categoria_filtro, sizeof(categoria_filtro), stdin);
    categoria_filtro[strcspn(categoria_filtro, "\n")] = '\0';

    printf("Tarefas na categoria %s:\n", categoria_filtro);
    for (int i = 0; i < cont; i++) {
        if (strcmp(tarefas[i].categoria, categoria_filtro) == 0) {
            printf("Tarefa %d\n", i + 1);
            printf("Prioridade: %d\n", tarefas[i].prioridade);
            printf("Categoria: %s\n", tarefas[i].categoria);
            printf("Descricao: %s\n", tarefas[i].descricao);
            printf("Estado: %s\n\n", tarefas[i].estado);
        }
    }
}
//filtra uma lista com as especificações de prioridade e categoria
void filtrar_por_prioridade_categoria(struct Tarefa *tarefas, int cont) {
    int prioridade_filtro;
    char categoria_filtro[100];

    printf("Digite a prioridade para filtrar: ");
    scanf("%d", &prioridade_filtro);
    limpa();

    printf("Digite a categoria para filtrar: ");
    fgets(categoria_filtro, sizeof(categoria_filtro), stdin);
    categoria_filtro[strcspn(categoria_filtro, "\n")] = '\0';

    printf("Tarefas com prioridade %d e categoria %s:\n", prioridade_filtro, categoria_filtro);
    for (int i = 0; i < cont; i++) {
        if (tarefas[i].prioridade == prioridade_filtro && strcmp(tarefas[i].categoria, categoria_filtro) == 0) {
            printf("Tarefa %d\n", i + 1);
            printf("Prioridade: %d\n", tarefas[i].prioridade);
            printf("Categoria: %s\n", tarefas[i].categoria);
            printf("Descricao: %s\n", tarefas[i].descricao);
            printf("Estado: %s\n\n", tarefas[i].estado);
        }
    }
}
//exporta um arquivo filtrando por prioridade
void exportar_por_prioridade(struct Tarefa *tarefas, int cont) {
    int prioridade_filtro;
    printf("Digite a prioridade para exportar: ");
    scanf("%d", &prioridade_filtro);
    limpa();

    char nome_arquivo[100];
    printf("Digite o nome do arquivo de exportação: ");
    fgets(nome_arquivo, sizeof(nome_arquivo), stdin);
    nome_arquivo[strcspn(nome_arquivo, "\n")] = '\0';

    FILE *arquivo_exportacao = fopen(nome_arquivo, "w");
    if (arquivo_exportacao == NULL) {
        printf("Erro ao criar o arquivo de exportação!\n");
        return;
    }

    fprintf(arquivo_exportacao, "Prioridade\tCategoria\tEstado\tDescrição\n");
    for (int i = 0; i < cont; i++) {
        if (tarefas[i].prioridade == prioridade_filtro) {
            fprintf(arquivo_exportacao, "%d\t%s\t%s\t%s\n", tarefas[i].prioridade, tarefas[i].categoria, tarefas[i].estado, tarefas[i].descricao);
        }
    }

    fclose(arquivo_exportacao);
    printf("Exportação concluída!\n");
}
//exporta um arquivo filtrando por categoria
void exportar_por_categoria(struct Tarefa *tarefas, int cont) {
    char categoria_filtro[100];
    printf("Digite a categoria para exportar: ");
    fgets(categoria_filtro, sizeof(categoria_filtro), stdin);
    categoria_filtro[strcspn(categoria_filtro, "\n")] = '\0';

    char nome_arquivo[100];
    printf("Digite o nome do arquivo de exportação: ");
    fgets(nome_arquivo, sizeof(nome_arquivo), stdin);
    nome_arquivo[strcspn(nome_arquivo, "\n")] = '\0';

    FILE *arquivo_exportacao = fopen(nome_arquivo, "w");
    if (arquivo_exportacao == NULL) {
        printf("Erro ao criar o arquivo de exportação!\n");
        return;
    }

    fprintf(arquivo_exportacao, "Prioridade\tCategoria\tEstado\tDescrição\n");
    for (int i = 0; i < cont; i++) {
        if (strcmp(tarefas[i].categoria, categoria_filtro) == 0) {
            fprintf(arquivo_exportacao, "%d\t%s\t%s\t%s\n", tarefas[i].prioridade, tarefas[i].categoria, tarefas[i].estado, tarefas[i].descricao);
        }
    }

    fclose(arquivo_exportacao);
    printf("Exportação concluída!\n");
}
//Exporta um arquivo com um filtro de prioridade e categoria
void exportar_por_prioridade_categoria(struct Tarefa *tarefas, int cont) {
    int prioridade_filtro;
    char categoria_filtro[100];

    printf("Digite a prioridade para exportar: ");
    scanf("%d", &prioridade_filtro);
    limpa();

    printf("Digite a categoria para exportar: ");
    fgets(categoria_filtro, sizeof(categoria_filtro), stdin);
    categoria_filtro[strcspn(categoria_filtro, "\n")] = '\0';

    char nome_arquivo[100];
    printf("Digite o nome do arquivo de exportação: ");
    fgets(nome_arquivo, sizeof(nome_arquivo), stdin);
    nome_arquivo[strcspn(nome_arquivo, "\n")] = '\0';

    FILE *arquivo_exportacao = fopen(nome_arquivo, "w");
    if (arquivo_exportacao == NULL) {
        printf("Erro ao criar o arquivo de exportação!\n");
        return;
    }

    fprintf(arquivo_exportacao, "Prioridade\tCategoria\tEstado\tDescrição\n");
    for (int i = 0; i < cont; i++) {
        if (tarefas[i].prioridade == prioridade_filtro && strcmp(tarefas[i].categoria, categoria_filtro) == 0) {
            fprintf(arquivo_exportacao, "%d\t%s\t%s\t%s\n", tarefas[i].prioridade, tarefas[i].categoria, tarefas[i].estado, tarefas[i].descricao);
        }
    }

    fclose(arquivo_exportacao);
    printf("Exportação concluída!\n");
}
