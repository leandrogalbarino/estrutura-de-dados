#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lista.h"

Lista *lista_cria()
{
    return NULL;
}

Lista *lista_insere(Lista *l, int valor)
{
    Lista *novo = (Lista *)malloc(sizeof(Lista));
    novo->info = valor;
    novo->prox = l;
    return novo;
}

void lista_imprime(Lista *l)
{
    Lista *p;
    for (p = l; p != NULL; p = p->prox)
    {
        printf("INFO = %d\n", p->info);
    }
    printf("\n"); // Adiciona uma nova linha no final da impressão
}

bool lista_vazia(Lista *l)
{
    if (l == NULL)
    {
        return true;
    }
    return false;
}

Lista *busca(Lista *l, int buscar)
{
    Lista *p;
    for (p = l; p != NULL; p = p->prox)
    {
        if (p->info == buscar)
        {
            return p;
        }
    }
    return NULL;
}

// 1. Implemente uma função que tenha como valor de retorno o comprimento de uma lista
// encadeada, isto é calcule o número de nós de uma lista. Esta função deve obedecer ao
// protótipo:
int comprimento(Lista *l)
{
    Lista *p;
    int tamanho = 0;
    for (p = l; p != NULL; p = p->prox)
    {
        tamanho++;
    }
    return tamanho;
}

// 2. Considere listas encadeadas de valores inteiros e implemente uma função para
// retornar o número de nós da lista que possuem o campo info com valores maiores do
// que n. Esta função deve obedecer ao protótipo:
int maiores(Lista *l, int n)
{
    Lista *p;
    int maior = 0;
    for (p = l; p != NULL; p = p->prox)
    {
        if (p->info > n)
        {
            maior++;
        }
    }
    return maior;
}
// 3. Implemente uma função que tenha como valor de retorno o ponteiro para o último nó
// de uma lista encadeada. Esta função deve obedecer ao protótipo:
Lista *ultimo(Lista *l)
{
    Lista *p = l;
    if (lista_vazia(l))
    {
        return NULL;
    }
    while (true)
    {
        if (p->prox == NULL)
        {
            return p;
        }
        p = p->prox;
    }
}

// 4. Implemente uma função que receba duas listas encadeadas de valores inteiros e
// retorne a lista resultante da concatenação das duas listas recebidas como parâmetros,
// isto é, após a concatenação, o último elemento da primeira lista deve apontar para o
// primeiro elemento da segunda lista. Esta função deve obedecer ao protótipo:
Lista *concatena(Lista *l1, Lista *l2)
{
    if (lista_vazia(l1))
    {
        if (lista_vazia(l2))
        {
            return NULL;
        }
        return l2;
    }
    Lista *p;
    p = ultimo(l1);

    p->prox = l2;

    return l1;
}