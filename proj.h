#ifndef PROJETO_H
#define PROJETO_H

//Antigo membros do grupo do projeto 1:
//João Pedro Lopes - RA: 24.123.071-3
//João Pedro Peterutto - RA: 24.123.045-7

//Criador desse projeto 3:
//Gabriel Koiama - RA: 24.123.051-5

struct Tarefa {
    int prioridade;
    char categoria[100];
    char descricao[300];
};

void limpa();
void ler(struct Tarefa *armazena);
void excluir_tarefa(struct Tarefa *tarefas, int *cont, int posicao);
void alterar_tarefa(struct Tarefa *tarefa, int opcao);

#endif // PROJ.H
