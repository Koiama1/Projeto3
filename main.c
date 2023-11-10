#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "proj.h"



int main() {
  
    struct Tarefa t[100];
    FILE *arquivo_binario = fopen("tarefas.txt", "rb");
    int cont = 0;
  
    if (arquivo_binario) {
        while (fread(&t[cont], sizeof(struct Tarefa), 1, arquivo_binario) == 1) {
            cont++;
        }
        fclose(arquivo_binario);
    }

    int posicao = 0;

    while (1) {
        printf(" 1 - Criar\n");
        printf(" 2 - Excluir\n");
        printf(" 3 - Alterar\n");
        printf(" 4 - Listar\n");
        printf(" 5 - Filtrar por Prioridade\n");
        printf(" 6 - Filtrar por Estado\n");
        printf(" 7 - Filtrar por Categoria\n");
        printf(" 8 - Filtrar por Prioridade e Categoria\n");
        printf(" 9 - exportar por prioridade\n");
        printf(" 10- exportar por categoria\n");
        printf(" 11 - exportar por prioridade e por categoria\n");
        printf(" 12 - Sair\n");
        printf("Digite o numero da opcao que deseja usar: ");

        char *p, s_opcao[100];
        char *p_posicao, s_posicao[100];
        int opcao;
        fgets(s_opcao, sizeof(s_opcao), stdin);
        opcao = strtol(s_opcao, &p, 10);

        if (opcao == 1) {
            ler(&t[cont]);
            printf("Tarefa criada!\n\n");
            cont++;
          
        } else if (opcao == 2) {
            printf("Digite o numero da tarefa que deseja excluir: ");
            fgets(s_posicao, sizeof(s_posicao), stdin);
            posicao = strtol(s_posicao, &p_posicao, 10);
          
            if (p_posicao == s_posicao || *p_posicao != '\n') {
                printf("Valor invalido!\n\n");
              
            } else {
                excluir_tarefa(t, &cont, posicao);
            }
          
        } else if (opcao == 3) {
            printf("Digite o numero da tarefa que deseja alterar: ");
            fgets(s_posicao, sizeof(s_posicao), stdin);
            posicao = strtol(s_posicao, &p_posicao, 10);

            if (posicao < 1 || posicao > cont) {
                printf("Posição inválida!\n\n");
              
            } else {
                printf("Escolha o campo que deseja alterar:\n");
                printf(" 1 - Prioridade\n");
                printf(" 2 - Categoria\n");
                printf(" 3 - Descrição\n");
                printf(" 4 - Estado\n");

                char *p_opcao_campo, s_opcao_campo[100];
                int opcao_campo;
                fgets(s_opcao_campo, sizeof(s_opcao_campo), stdin);
                opcao_campo = strtol(s_opcao_campo, &p_opcao_campo, 10);

                if (opcao_campo < 1 || opcao_campo > 4 || *p_opcao_campo != '\n') {
                    printf("Opção de campo inválida!\n\n");
                  
                } else {
                    alterar_tarefa(&t[posicao - 1], opcao_campo);
                    printf("Tarefa alterada!\n\n");
                }
            }
        } else if (opcao == 4) {
            printf("Lista:\n\n");
          
            for (int x = 0; x < cont; x++) {
                printf("Tarefa %d\n", x + 1);
                printf("Prioridade: %d\n", t[x].prioridade);
                printf("Categoria: %s\n", t[x].categoria);
                printf("Descricao: %s\n", t[x].descricao);
                printf("Estado: %s\n\n", t[x].estado);
            }
        } else if (opcao == 5) {
            filtrar_por_prioridade(t, cont);
          
        } else if (opcao == 6) {
            filtrar_por_estado(t, cont);
          
        } else if (opcao == 7) {
            filtrar_por_categoria(t, cont);
          
        } else if (opcao == 8) {
            filtrar_por_prioridade_categoria(t, cont);
          
        } else if (opcao == 9) {
            exportar_por_prioridade(t, cont);
            
            }
          else if (opcao == 10) {
            exportar_por_categoria(t, cont);
            
        } else if (opcao == 11) {
            exportar_por_prioridade_categoria(t, cont);
            
        } else if (opcao == 12) {
            arquivo_binario = fopen("tarefas.txt", "wb");
            if (arquivo_binario) {
                fwrite(t, sizeof(struct Tarefa), cont, arquivo_binario);
                fclose(arquivo_binario);
          }
          
            printf("Saindo\n");
            break;
        } else {
            printf("Valor invalido!\n\n");
        }
    }

    return 0;
}
