#ifndef lista_h
#define lista_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct lista
{
    int info;
    struct lista *ant;
    struct lista *prox;
};
typedef struct lista Lista;

Lista *concatena(Lista *l1, Lista *l2);

Lista *ultimo(Lista *l);

int maiores(Lista *l, int n);

int comprimento(Lista *l);

Lista *busca(Lista *l, int buscar);

bool lista_vazia(Lista *l);

void lista_imprime(Lista *l);

Lista *lista_insere(Lista *l, int valor);

Lista *lista_cria();

#endif