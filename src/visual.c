#include "../hdr/visual.h"

void menu()
{
    printf("\tCONTROLE DE TURMA\n");
    printf("\n[1] Incluir Aluno");
    printf("\n[2] Listar Alunos");
    printf("\n[3] Pesquisar Aluno por Nome");
    printf("\n[4] Alterar Aluno");
    printf("\n[5] Excluir Aluno");

    printf("\n[0] Sair\n");

    printf("\n-> ");
}

void menu_alterar()
{
        printf("\tALTERACAO DE DADOS DO ALUNO\n");
        printf("\n[1] Nome");
        printf("\n[2] Endereco");
        printf("\n[3] Idade");
        printf("\n[4] Matricula");
        printf("\n[5] Materias");
        printf("\n[0] Retonar ao Menu\n");
        printf("\n-> ");
}

void listar_materias()
{
    char temp[15];

    FILE *f = fopen("data//materias.txt", "r");

    while(!feof(f))
    {
        fscanf(f, "%s", temp);
        printf("%s\n", temp);
    }

    fclose(f);
}

void printar_materias(int *vmat)
{
    FILE *f = fopen("data//materias.txt", "r");

    int i = 0, j = 0;
    char s[15];

    while (vmat[i] != 0 && i < 5)
    {
        fseek(f, SEEK_SET, 0);

        while (!feof(f))
        {
            fscanf(f, "%d", &j);
            fscanf(f, "%*c%s", &s);

            if (j == vmat[i])
                printf("-> %s\n", s);
        }

        i++;
    }

    fclose(f);
}


void printar_node(node_Lista *node)
{
    printf("NOME:\t\t%s\n", node->aluno.nome);
    printf("ENDERECO: \t%s\n", node->aluno.endereco);
    printf("IDADE: \t\t%d\n", node->aluno.idade);
    printf("MATRICULA: \t%d\n", node->aluno.matricula);
    printf("MATERIAS: \n");
    printar_materias(node->aluno.materias);
    printf("- - -\n");
}

void visual(int cod)
{
    switch(cod)
    {
        case 1:
            printf("\tINSERCAO DE ALUNO\n\n");
            break;
        case 2:
            printf("Nome: ");
            fflush(stdin);
            break;
        case 3:
            printf("Endereco: ");
            fflush(stdin);
            break;
        case 4:
            printf("Idade: ");
            break;
        case 5:
            printf("Matricula: ");
            break;
        case 6:
            printf("Selecione da Lista Abaixo 5 Materias: [M M ... M] \n");
            listar_materias();
            printf("-> ");
            break;
        case 7:
            printf("Selecione o Aluno a ser Alterado ou -1 para Sair: ");
            break;
        case 8:
            printf("\tPESQUISA DE ALUNO\n\n");
            break;
        case 9:
            printf("\tLISTA DE ALUNOS\n\n");
            break;
    }
}
