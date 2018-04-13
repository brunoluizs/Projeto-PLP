#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

#include "visual.h"

node_Lista* alocar_node();

void iniciar_Lista(node_Lista**, node_Lista**);

void encerrar_Lista(node_Lista*);

void inserir_node(node_Lista*, struct Aluno);

void abracadabra(node_Lista*);

void listar_Turma(node_Lista*);

#endif // LIST_H
