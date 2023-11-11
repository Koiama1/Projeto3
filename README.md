# Projeto3

O programa funciona do seguinte modo:

Ao ligar o programa será mostrado um menu com 12 opções:

 1 - Criar
 2 - Excluir
 3 - Alterar
 4 - Listar
 5 - Filtrar por Prioridade
 6 - Filtrar por Estado
 7 - Filtrar por Categoria
 8 - Filtrar por Prioridade e Categoria
 9 - exportar por prioridade
 10- exportar por categoria
 11 - exportar por prioridade e por categoria
 12 - Sair


Depois o usuario criara uma tarefa na opção 1, ao criar as tarefas que deseja podera usar qualquer função apresentada e ao fechar pela primeira vez o programa ao escolher a opção 12,
será criado um arquivo.txt com todos os dados salvos, desse modo ao ligar o programa novamente não precisará criar as tarefas novamente,

As tarefas são separadas com as seguintes opções:
Prioridade(por numeros)
Descricao
Categoria
e
Estado (Completo,Em andamento e Não iniciado digitando um numero correspondente ao estado(1,2,3))

Essas são as caracteristicas gerais



Agora essas são características mais detalhadas:

Opções 1 a 8: São operações relacionadas à criação, exclusão, alteração, listagem e filtragem de tarefas.
Opções 9 a 11: São operações de exportação de tarefas com base em prioridade, categoria ou ambos.
Opção 12: Fecha o programa, salvando as tarefas em um arquivo binário.

Opção 1 - Criar:

O usuário é solicitado a inserir informações para uma nova tarefa.
A função ler é chamada para armazenar essas informações em uma nova posição na matriz de tarefas (struct Tarefa t[100]).

Opção 2 - Excluir:

O usuário fornece o número da tarefa que deseja excluir.
A função excluir_tarefa é chamada para remover a tarefa da matriz.
Opção 3 - Alterar:

O usuário fornece o número da tarefa que deseja alterar.
Em seguida, escolhe qual campo da tarefa deseja alterar (prioridade, categoria, descrição ou estado).
A função alterar_tarefa é chamada para efetuar a alteração.

Opção 4 - Listar:

Todas as tarefas na matriz são impressas na tela, exibindo informações como prioridade, categoria, descrição e estado.
Opção 5 - Filtrar por Prioridade:

O usuário fornece a prioridade desejada.
A função filtrar_por_prioridade exibe na tela as tarefas que correspondem à prioridade fornecida.
Opção 6 - Filtrar por Estado:

O usuário escolhe um estado (Completo, Em andamento ou Não iniciado).
A função filtrar_por_estado exibe na tela as tarefas que correspondem ao estado escolhido.
Opção 7 - Filtrar por Categoria:

O usuário fornece a categoria desejada.
A função filtrar_por_categoria exibe na tela as tarefas que correspondem à categoria fornecida.
Opção 8 - Filtrar por Prioridade e Categoria:

O usuário fornece a prioridade e a categoria desejadas.
A função filtrar_por_prioridade_categoria exibe na tela as tarefas que correspondem à prioridade e categoria fornecidas.
Opção 9 - Exportar por Prioridade:

O usuário fornece a prioridade desejada.
A função exportar_por_prioridade cria um arquivo de exportação contendo as tarefas que correspondem à prioridade fornecida.
Opção 10 - Exportar por Categoria:

O usuário fornece a categoria desejada.
A função exportar_por_categoria cria um arquivo de exportação contendo as tarefas que correspondem à categoria fornecida.
Opção 11 - Exportar por Prioridade e Categoria:

O usuário fornece a prioridade e a categoria desejadas.
A função exportar_por_prioridade_categoria cria um arquivo de exportação contendo as tarefas que correspondem à prioridade e categoria fornecidas.
Opção 12 - Sair:

O programa fecha. Antes disso, ele salva as tarefas em um arquivo binário chamado "tarefas.txt".
