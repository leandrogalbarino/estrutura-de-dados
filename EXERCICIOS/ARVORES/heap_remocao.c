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
    // int ultimo_dado;
    // int ultima_prioridade;
    struct heap *esquerda;
    struct heap *direita;
};
typedef struct heap Heap;


Heap *fila_troca(Heap *raiz, Heap *primeiro_no)
{
    primeiro_no->info = raiz->info;
    return NULL;
}

Heap *fila_prio_remover(Heap *raiz, Heap *primeiro_no)
{
    if (raiz == NULL)
        return NULL;

    if (raiz->esquerda == NULL)
    {
        raiz = fila_troca(raiz, primeiro_no);
    }
    else if (raiz->direita == NULL)
    {
        raiz->esquerda = fila_troca(raiz->esquerda, primeiro_no);
    }
    else
    {
        if (quant_de_nos(raiz->direita) == quant_de_nos(raiz->esquerda))
        {
            raiz->direita = fila_prio_remover(raiz->direita, primeiro_no);
        }
        else if (quant_de_nos(raiz->direita->esquerda) != quant_de_nos(raiz->direita->direita))
        {
            raiz->direita = fila_prio_remover(raiz->direita, primeiro_no);
        }
        else
        {
            raiz->esquerda = fila_prio_remover(raiz->esquerda, primeiro_no);
        }
    }

    return raiz;
}

Heap *ordenar_toda_heap(Heap *raiz)
{
    if (raiz != NULL)
    {
        if (raiz->esquerda != NULL && raiz->esquerda->info.prioridade > raiz->info.prioridade)
        {
            Informacoes temp = raiz->info;
            raiz->info = raiz->esquerda->info;
            raiz->esquerda->info = temp;
            ordenar_toda_heap(raiz->esquerda);
        }

        if (raiz->direita != NULL && raiz->direita->info.prioridade > raiz->info.prioridade)
        {
            Informacoes temp = raiz->info;
            raiz->info = raiz->direita->info;
            raiz->direita->info = temp;
            ordenar_toda_heap(raiz->direita);
        }
    }
    return raiz;
}

Heap *remover(Heap *raiz)
{
    if (raiz == NULL)
        printf("Heap vazia, nao foi possivel remover um elemento!!\n");
    else
    {
        raiz = fila_prio_remover(raiz, raiz);
        ordenar_toda_heap(raiz);

        printf("Elemento removido com sucesso!\n");
    }
    return raiz;
}