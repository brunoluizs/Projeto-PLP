#include "../hdr/list.h"

node_Lista* alocar_node()
{
    node_Lista *node;

    node = (node_Lista*) malloc (sizeof(node_Lista));
    node->prox = NULL;
    node->ante = NULL;

    return node;
}

void iniciar_Lista(node_Lista **head, node_Lista **tail)
{
    (*head) = alocar_node();
    (*tail) = alocar_node();

    (*head)->prox = *tail;
    (*head)->ante = NULL;
    (*head)->aluno.visivel = FALSE;

    (*tail)->ante = *head;
    (*tail)->prox = NULL;
    (*tail)->aluno.visivel = FALSE;

}


void encerrar_Lista(node_Lista *tail)
{
    node_Lista *cursor;

    do {
         cursor = tail->ante;

         tail->ante = cursor->ante;
         free(cursor);

    } while (cursor != NULL);

    free(tail);
}

void inserir_node(node_Lista *tail, struct Aluno info)
{
    node_Lista *novo = alocar_node();

    novo->aluno = info;
    novo->aluno.visivel = TRUE;

    novo->ante = tail->ante;
    novo->prox = tail;

    tail->ante->prox = novo;
    tail->ante = novo;
}

void abracadabra(node_Lista *node)
{
    if (node != NULL)
        node->aluno.visivel = FALSE;
}

void listar_Turma(node_Lista *head)
{
    node_Lista *cursor = head->prox;

    while(cursor->prox != NULL)
    {
        if (cursor->aluno.visivel == TRUE)
            printar_node(cursor);

        cursor = cursor->prox;
    }
}

node_Lista *buscar_Aluno(node_Lista *head, char *nome, int tag)
{
    node_Lista *cursor = head->prox;
    node_Lista *vet[5];
    int i = 0;

    while(cursor->prox != NULL && i < 5)
    {
        if (strncmp(nome, cursor->aluno.nome, strlen(nome)) == 0 && cursor->aluno.visivel == TRUE)
        {
            printf("\t[%d]\n", i);
            printar_node(cursor);
            vet[i] = cursor;
            i++;
        }

        cursor = cursor->prox;
    }

    if (tag == 1){ /* Com retorno */
        if (i == 0)
        {
            printf("Nao foram encontrados resultados.\n");
            system("pause");
            return NULL;
        }

        visual(7);
        scanf("%d", &i);

        if (i == -1)
            return NULL;

        return vet[i];
    }

    if (tag == 2) /* Sem retorno */
        return NULL;
}
