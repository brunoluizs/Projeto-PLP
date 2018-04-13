#define TRUE 1
#define FALSE 0

struct Aluno
{
    char nome[30];
    char endereco[30];
    int idade;
    int matricula;
    int materias[5];
    short int visivel;
};

typedef struct node_Lista
{
    struct Aluno aluno;
    struct node_Lista *prox;
    struct node_Lista *ante;
}node_Lista;
