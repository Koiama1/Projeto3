#ifndef PROJETO_H
#define PROJETO_H

struct Tarefa {
    int prioridade;
    char categoria[100];
    char descricao[300];
    char estado[20];
};

void limpa();
void ler(struct Tarefa *armazena);
void excluir_tarefa(struct Tarefa *tarefas, int *cont, int posicao);
void alterar_tarefa(struct Tarefa *tarefa, int opcao);
void filtrar_por_prioridade(struct Tarefa *tarefas, int cont);
void filtrar_por_estado(struct Tarefa *tarefas, int cont);
void filtrar_por_categoria(struct Tarefa *tarefas, int cont);
void filtrar_por_prioridade_categoria(struct Tarefa *tarefas, int cont);
void exportar_por_prioridade(struct Tarefa *tarefas, int cont);
void exportar_por_categoria(struct Tarefa *tarefas, int cont);
void exportar_por_prioridade_categoria(struct Tarefa *tarefas, int cont);

#endif // PROJ.H
