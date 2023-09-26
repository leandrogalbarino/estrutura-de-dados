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
    Aluno *info;
    struct lista *prox;
};
typedef struct lista Lista;

Lista *lista_cria()
{
    return NULL;
}

Lista *lista_insere(Lista *l, int matricula, char nome[50])
{
    Lista *novo;
    novo = (Lista *)malloc(sizeof(Lista));
    if (novo == NULL)
    {
        printf("ERRO AO ALOCAR");
        exit(1);
    }
    novo->info = (Aluno *)malloc(sizeof(Aluno));
    if (novo->info == NULL)
    {
        printf("ERRO AO ALOCAR");
        exit(1);
    }

    novo->info->matricula = matricula;
    strcpy(novo->info->nome, nome);
    novo->prox = l;

    return novo;
}

void lista_imprime(Lista *l)
{
    Lista *p;
    int aluno = 0;

    if (l == NULL)
    {
        printf("LISTA VAZIA!!\n\n");
        return;
    }
    for (p = l; p != NULL; p = p->prox)
    {
        aluno++;
        printf("ALUNO NUMERO :%d\n", aluno);
        printf("NOME:%s\n", p->info->nome);
        printf("MATRICULA:%d\n\n", p->info->matricula);
    }
}

int main()
{

    Lista *l = lista_cria();
    l = lista_insere(l, 202311173, "Leandro Oliveira do Nascimento");
    l = lista_insere(l, 2032, "Leandro Kise");
    l = lista_insere(l, 2023, "Victor do Nascimento");
    lista_imprime(l);
    system("pause");
}