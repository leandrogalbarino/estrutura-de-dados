#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct lista
{
    int cpf;
    char nome[100];
    int fator;
    struct lista *prox;
};
typedef struct lista Lista;

Lista *ist_insere(Lista *l, int cpf, char nome[100], int fator)
{
    Lista *p;
    Lista *ant = NULL;
    Lista *aux = NULL;

    aux = (Lista *)malloc(sizeof(Lista));
    if (aux == NULL)
    {
        printf("ERRO NA ALOCACAO");
        exit(1);
    }

    if (l == NULL)
    {
        aux->cpf = cpf;
        strcpy(aux->nome, nome);
        aux->fator = fator;
        aux->prox = NULL;
        return aux;
    }

    for (p = l; p != NULL; p = p->prox)
    {
        if (p->fator > fator)
        {
            if (ant != NULL)
            {
                ant->prox = aux;
            }
            aux->cpf = cpf;
            aux->fator = fator;
            strcpy(aux->nome, nome);

            aux->prox = p;
            break;
        }
        ant = p;
    }

    if (p == NULL)
    {
        p = (Lista *)malloc(sizeof(Lista));
        ant->prox = p;

        p->cpf = cpf;
        p->fator = fator;
        strcpy(p->nome, nome);
        p->prox = NULL;
    }

    return l;
}

Lista *lst_remove(Lista *l, int fator)
{
    Lista *p;
    Lista *ant = NULL;

    if (l == NULL)
    {
        return l;
    }
    for (p = l; p != NULL; p = p->prox)
    {
        if (p->fator == fator)
        {
            if (ant == NULL)
            {
                l = p->prox;
                free(p);
            }
            else
            {
                ant->prox = p->prox;
                free(p);
            }
        }
        ant = p;
    }
    return l;
}