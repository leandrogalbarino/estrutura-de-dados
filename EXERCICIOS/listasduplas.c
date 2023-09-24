#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

// 1. Implemente uma função que insira elementos sempre ao final da lista.
Lista *lst_insere(Lista *l, int i)
{
    Lista *novo;
    Lista *p;

    novo = (Lista *)malloc(sizeof(Lista));
    if (novo == NULL)
    {
        exit(1);
        printf("ERRO AO ALOCAR");
    }
    novo->ant = NULL;
    novo->prox = NULL;
    novo->info = i;

    if (l == NULL)
    {
        return novo;
    }

    for (p = l; p != NULL; p = p->prox)
    {
        if (p->prox == NULL)
        {
            p->prox = novo;
            novo->ant = p;
            break;
        }
    }
    return l;
}
// 2. Implemente uma função que remova o elemento anterior a um elemento de valor v. Esta função deve ter o protótipo:

Lista *lst_retira_ant(Lista *l, int v)
{
    Lista *p;
    if (l == NULL)
    {
        return l;
    }
    if (l->info == v)
    {
        printf("PRIMEIRO ELEMENTO, NÃO FOI POSSIVEL REMOVER O ANTERIOR!");
        return l;
        // PRIMEIRO
    }

    for (p = l; p != NULL; p = p->prox)
    {
        if (p->prox != NULL && p->prox->info == v)
        {
            p->ant->prox = p->prox;
            free(p);
            break;
        }
    }
    return l;
}

// 1) Faça uma função que insira elementos nesta lista, dada a seguinte definição de struct:


int main()

{
    Lista *l = lista_cria();
    int valor;
    scanf("%d", &valor);

    lst_inre(l, valor);
}
