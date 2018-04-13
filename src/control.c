#include "../hdr/control.h"

void file_to_list(node_Lista *tail)
{
    FILE *input = fopen("data//dados.txt", "r");
    struct Aluno temp;
    int i;


    if (input == NULL)
    {
        return;
    }

    else
    {
        do{
            fscanf(input, " %[^\n]s", temp.nome);

            fscanf(input, " %[^\n]s", temp.endereco);

            fscanf(input, "%d", &temp.idade);

            fscanf(input, "%d", &temp.matricula);

            for(i = 0; i < 5; i++)
                fscanf(input, "%d", &temp.materias[i]);

            fscanf(input, "%hd", &temp.visivel);

            inserir_node(tail, temp);

        } while (!feof(input));
    }
}

void list_to_file(node_Lista *head)
{
    FILE *output = fopen("data//dados.txt", "w");
    node_Lista *cursor = head->prox;
    int i;

    while(cursor->prox != NULL)
    {
        fprintf(output, "%s\n", cursor->aluno.nome);

        fprintf(output, "%s\n", cursor->aluno.endereco);

        fprintf(output, "%d\n", cursor->aluno.idade);

        fprintf(output, "%d\n", cursor->aluno.matricula);

        for(i = 0; i < 5; i++)
            fprintf(output, "%d ", cursor->aluno.materias[i]);

        fprintf(output, "\n%d", cursor->aluno.visivel);

        cursor = cursor->prox;

        if (cursor->prox != NULL)
            fprintf(output, "\n");
    }

    fclose(output);
}

void run(node_Lista *head, node_Lista *tail)
{
    int op, i, altop;

    do {
        system("cls");

        menu();

        scanf("%d", &op);

        switch(op)
        {
            case 1:
            {
                struct Aluno temp;

                visual(1);
                visual(2);
                scanf("%[^\n]s", temp.nome);

                visual(3);
                scanf("%[^\n]s", temp.endereco);

                visual(4);
                scanf("%d", &temp.idade);

                visual(5);
                scanf("%d", &temp.matricula);

                visual(6);
                for (i = 0; i < 5; i++)
                    scanf("%d", &temp.materias[i]);

                inserir_node(tail, temp);

                list_to_file(head);
                break;
            }
            case 2:
            {
                visual(9);
                listar_Turma(head);
                break;
            }
            case 3:
            {
                char nome[30];

                visual(8);
                visual(2);
                scanf("%[^\n]s", nome);

                buscar_Aluno(head, nome, 2);
                break;
            }
            case 4:
            {
                char nome[30];
                node_Lista *cursor;

                visual(8);
                visual(2);
                scanf("%[^\n]s", nome);

                cursor = buscar_Aluno(head, nome, 1);

                menu_alterar();

                scanf("%d", &altop);

                switch(altop)
                {
                    case 1:
                        visual(2);
                        scanf("%[^\n]s", cursor->aluno.nome);
                        break;
                    case 2:
                        visual(3);
                        scanf("%[^\n]s", cursor->aluno.endereco);
                        break;
                    case 3:
                        visual(4);
                        scanf("%d", &cursor->aluno.idade);
                        break;
                    case 4:
                        visual(5);
                        scanf("%d", &cursor->aluno.matricula);
                        break;
                    case 5:
                        visual(6);
                        for (i = 0; i < 5; i++)
                            scanf("%d", &cursor->aluno.materias[i]);
                        break;
                }

                list_to_file(head);
                break;
            }
            case 5:
            {
                char nome[30];
                node_Lista *cursor;

                visual(8);
                visual(2);
                scanf("%[^\n]s", nome);

                cursor = buscar_Aluno(head, nome, 1);

                abracadabra(cursor);

                list_to_file(head);
                break;
            }
        }

        system("pause");

    } while (op != 0);
}
