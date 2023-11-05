#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct arv
{
    int info;
    struct arv *esquerda;
    struct arv *direita;
};
typedef struct arv Arv;

int arv_vazia(Arv *arvore)
{
    if (arvore == NULL)
        return 1;
    return 0;
}

// IMPRESSÃO
void ordem_simetrica(Arv *arvore)
{
    if (!arv_vazia(arvore))
    {
        ordem_simetrica(arvore->esquerda);
        printf("%d|", arvore->info);
        ordem_simetrica(arvore->direita);
    }
}

Arv *arv_cria_vazia()
{
    return NULL;
}

Arv *arv_cria(char info, Arv *sae, Arv *sad)
{
    Arv *arvore = (Arv *)malloc(sizeof(Arv));
    arvore->esquerda = sae;
    arvore->direita = sad;
    arvore->info = info;
    return arvore;
}

// 1. Considerando os algoritmos de inserção e remoção em uma árvore binária de busca, mostre como fica a composição da árvore após cada uma das operações a seguir:
Arv *abb_insere(Arv *a, int v)
{
    // SE a == NULL, cria o nó
    if (a == NULL)
    {
        a = (Arv *)malloc(sizeof(Arv));
        a->info = v;
        a->esquerda = arv_cria_vazia();
        a->direita = arv_cria_vazia();
    }
    // Se v < a->info, cria o nó na sub arvore da esquerda
    else if (v < a->info)
        a->esquerda = abb_insere(a->esquerda, v);
    // Se v >= a->info, cria o nó na sub arvore da direita
    else
    {
        a->direita = abb_insere(a->direita, v);
    }
    return a;
}

Arv *abb_retira(Arv *a, int v)
{
    if (a == NULL)
    {
        return NULL;
    }

    if (v < a->info)
        a->esquerda = abb_retira(a->esquerda, v);
    else if (v > a->info)
        a->direita = abb_retira(a->direita, v);
    else
    {
        if (a->esquerda == NULL && a->direita == NULL)
        {
            free(a);
            return NULL;
        }
        else if (a->esquerda != NULL && a->direita == NULL)
        {
            Arv *temp = a;
            a = a->esquerda;
            free(temp);
        }
        else if (a->direita != NULL && a->esquerda == NULL)
        {
            Arv *temp = a;
            a = a->direita;
            free(temp);
        }
        else
        {
            Arv *temp = a->esquerda;
            while (temp->direita != NULL)
                temp = temp->direita;

            a->info = temp->info;
            temp->info = v;

            a->esquerda = abb_retira(a->esquerda, v);
        }
    }
    return a;
}

// 2. Escreva uma função que percorra uma árvore binária de busca e mostre os valores armazenados em ordem decrescente.
void abb_imprime(Arv *a)
{
    if (!arv_vazia(a))
    {
        abb_imprime(a->direita);
        printf("%d|", a->info);
        abb_imprime(a->esquerda);
    }
}
// 3. Escreva uma função que percorra uma árvore binária e retorne true caso ela seja uma árvore binária de busca e false caso contrário.

int main()
{
    Arv *a = arv_cria_vazia();
    a = abb_insere(a, 5);
    a = abb_insere(a, 1);
    a = abb_insere(a, 3);
    a = abb_insere(a, 4);
    a = abb_insere(a, 7);
    a = abb_insere(a, 2);
    a = abb_insere(a, 8);
    ordem_simetrica(a);
    printf("\n");
    abb_imprime(a);
    printf("\n");

    printf("%d", ehABB(a));
    // a = abb_retira(a, 8);
    // a = abb_retira(a, 1);
    // a = abb_retira(a, 5);
    // a = abb_retira(a, 4);
    // ordem_simetrica(a);
}