#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tipo_aluno 1
#define tipo_professor 2

struct professor
{
    int codigo;
    char nome[50];
    float salario;
};
typedef struct professor Professor;

struct aluno
{
    int matricula;
    char nome[50];
};
typedef struct aluno Aluno;

struct lista_het
{
    int tipo;
    void *info;
    struct lista_het *prox;
};
typedef struct lista_het Lista_het;

Lista_het *lista_cria()
{
    return NULL;
}
// Considere uma lista de alunos e uma lista de professores.
// 1) Faça uma função que insira elementos nesta lista, dadas as seguintes definições de structs:
Lista_het *lista_insere_alunos(Lista_het *l, int matricula, char nome[50])
{
    Aluno *info;
    Lista_het *p;
    info = (Aluno *)malloc(sizeof(Aluno));

    strcpy(info->nome, nome);
    info->matricula = matricula;

    p = (Lista_het *)malloc(sizeof(Lista_het));

    p->tipo = tipo_aluno;
    p->info = info;
    p->prox = l;

    return p;
}

Lista_het *lista_insere_professor(Lista_het *l, int codigo, char nome[50], float salario)
{
    Professor *info;
    Lista_het *p;
    info = (Professor *)malloc(sizeof(Professor));

    strcpy(info->nome, nome);
    info->codigo = codigo;
    info->salario = salario;

    p = (Lista_het *)malloc(sizeof(Lista_het));

    p->tipo = tipo_professor;
    p->info = info;
    p->prox = l;

    return p;
}

// 2) Faça uma função que imprima os elementos desta lista.
void lista_imprime_het(Lista_het *l)
{
    Lista_het *p;
    if (l == NULL)
    {
        printf("LISTA VAZIA!\n");
    }
    for (p = l; p != NULL; p = p->prox)
    {
        if (p->tipo == tipo_aluno)
        {
            Aluno *aluno;
            aluno = (Aluno *)p->info;
            printf("ALUNO:%s\n", aluno->nome);
            printf("MATRICULA:%d\n\n", aluno->matricula);
        }
        else if (p->tipo == tipo_professor)
        {
            Professor *prof;
            prof = (Professor *)p->info;

            printf("PROFESSOR:%s\n", prof->nome);
            printf("CODIGO:%d\n", prof->codigo);
            printf("SALARIO:%f\n\n", prof->salario);
        }
        else
        {
            printf("ESSE TIPO DE ESTRUTURA NAO EXISTE!\n");
        }
    }
}

int main()
{
    Lista_het *escola = lista_cria();
    escola = lista_insere_alunos(escola, 202311173, "LEANDRO OLIVEIRA DO NASCIMENTO");
    escola = lista_insere_alunos(escola, 1, "KISE THE LEGEND");

    escola = lista_insere_professor(escola, 23, "GERALDO DA SILVA", 10301);
    escola = lista_insere_professor(escola, 2, "DEISE", 11001);
    lista_imprime_het(escola);
    system("pause");
}