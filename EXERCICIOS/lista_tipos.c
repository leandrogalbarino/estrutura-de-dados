#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct aluno
{
    int matricula;
    char nome[50];
};
typedef struct aluno Aluno;

struct lista
{
    Aluno info;
    struct lista *prox;
};
typedef struct lista Lista;

Lista *lista_cria()
{
    return NULL;
}

// 1) Faça uma função que insira elementos nesta lista
// 1) Faça uma função que insira elementos nesta lista, dadas as seguintes definições de structs:
Lista *lista_insere(Lista *l, int matricula, char nome[50])
{
    Lista *novo;
    novo = (Lista *)malloc(sizeof(Lista));
    if (novo == NULL)
    {
        printf("FALHA AO ALOCAR!!");
        exit(1);
    }

    novo->info.matricula = matricula;
    strcpy(novo->info.nome, nome);
    novo->prox = l;

    return novo;
}

// 2) Faça uma função que imprima os elementos desta lista.
// 2) Faça uma função que imprima os elementos desta lista.

void lista_imprime(Lista *l)
{
    Lista *p;
    int alunos = 0;
    if (l == NULL)
    {
        printf("NAO TEM NENHUM ALUNO CADASTRADO!!\n\n");
        return;
    }
    for (p = l; p != NULL; p = p->prox)
    {
        alunos++;
        printf("ALUNO NUMERO: %d\n", alunos);
        printf("NOME:%s\n", p->info.nome);
        printf("MATRICULA:%d\n\n", p->info.matricula);
    }
}

int main()
{
    Lista *alunos = lista_cria();
    alunos = lista_insere(alunos, 9534, "RODRIGO");
    alunos = lista_insere(alunos, 111, "GERALDO");
    alunos = lista_insere(alunos, 2222, "JOAO");
    alunos = lista_insere(alunos, 38734, "VITINHO");
    lista_imprime(alunos);
    system("pause");
}