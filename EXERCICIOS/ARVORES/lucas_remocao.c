#include <stdio.h>
#include <stdlib.h>


struct informacoes
{
    int dado;
    int prioridade;
};
typedef struct informacoes Informacoes;

struct heap
{
    Informacoes info;
    int ultimo_dado;
    int ultima_prioridade;
    struct heap *esquerda;
    struct heap *direita;
};
typedef struct heap Heap;

Heap *busca_no(Heap *raiz, int dado, int prioridade)
{
    if (raiz == NULL)
    {
        return NULL;
    }

    if (raiz->info.dado == dado && raiz->info.prioridade == prioridade)
    {
        return raiz;
    }

    Heap *no_na_esquerda = busca_no(raiz->esquerda, dado, prioridade);
    if (no_na_esquerda != NULL)
    {
        return no_na_esquerda;
    }

    Heap *no_na_direita = busca_no(raiz->direita, dado, prioridade);
    if (no_na_direita != NULL)
    {
        return no_na_direita;
    }
}

Heap *busca_pai(Heap *raiz, int dado, int prioridade)
{
    if (raiz == NULL || (raiz->esquerda == NULL && raiz->direita == NULL))
    {
        return NULL;
    }

    if ((raiz->esquerda != NULL && raiz->esquerda->info.dado == dado && raiz->esquerda->info.prioridade == prioridade) ||
        (raiz->direita != NULL && raiz->direita->info.dado == dado && raiz->direita->info.prioridade == prioridade))
    {
        return raiz;
    }

    Heap *pai_na_esquerda = busca_pai(raiz->esquerda, dado, prioridade);
    if (pai_na_esquerda != NULL)
    {
        return pai_na_esquerda;
    }

    Heap *pai_na_direita = busca_pai(raiz->direita, dado, prioridade);
    if (pai_na_direita != NULL)
    {
        return pai_na_direita;
    }

    return NULL;
}

Heap *troca_nos(Heap *raiz, Heap *ultimo)
{
    Heap *pai_ultimo = busca_pai(raiz, raiz->ultimo_dado, raiz->ultima_prioridade);
    Informacoes temp_info = raiz->info;
    raiz->info = ultimo->info;

    if (pai_ultimo->direita->info.dado == raiz->ultimo_dado && pai_ultimo->direita->info.prioridade == raiz->ultima_prioridade)
    {
        pai_ultimo->direita = NULL;
    }
    else if (pai_ultimo->esquerda->info.dado == raiz->ultimo_dado && pai_ultimo->esquerda->info.prioridade == raiz->ultima_prioridade)
    {
        pai_ultimo->esquerda = NULL;
    }

    ultimo = NULL;

    return raiz;
}

Heap *remover(Heap *raiz)
{
    Heap *ultimo_no = busca_no(raiz, raiz->ultimo_dado, raiz->ultima_prioridade);
    printf("ULTIMO NO: %d com prioridade %d", ultimo_no->info.dado, ultimo_no->info.prioridade);

    if (ultimo_no != NULL)
    {
        raiz->ultima_prioridade = ultimo_no->info.prioridade;
        raiz->ultimo_dado = ultimo_no->info.dado;

        raiz = troca_nos(raiz, ultimo_no);
    }

raiz = ordena_heap(raiz);

    return raiz;
}