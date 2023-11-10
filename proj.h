#ifndef PROJETO_H
#define PROJETO_H

//João Pedro Lopes - RA: 24.123.071-3
//João Pedro Peterutto - RA: 24.123.045-7
//Gabriel Koiama - RA: 24.123.051-5

struct Tarefa {
    int prioridade;
    char categoria[100];
    char descricao[300];
};
//Espaço responsável por definir a estrutura da tarefa

void limpa();
//cabeçalho da função responsável por limpar as informações salvas na variável para poder armazenar novas informações
void ler(struct Tarefa *armazena);
//cabeçalho da função que lê as informações dadas pelo usuário e armazena no arquivo
void excluir_tarefa(struct Tarefa *tarefas, int *cont, int posicao);
//cabeçalho da função que vai excluir as tarefas


//A PARTIR DAQUI É O PROJETO 3:


#endif//PROJ.H
