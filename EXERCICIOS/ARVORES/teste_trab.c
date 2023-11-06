#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct informacoes
{
    int dado;
    int prioridade;
};
typedef struct informacoes Informacoes;

struct heap
{
    Informacoes info;
    struct heap *esquerda;
    struct heap *direita;
};
typedef struct heap Heap;

Heap *heap_cria_vazia()
{
    return NULL;
}

Heap *insere_na_fila(int prioridade, int dado)
{
    Heap *novo = (Heap *)malloc(sizeof(Heap));
    novo->info.prioridade = prioridade;
    novo->info.dado = dado;
    novo->esquerda = heap_cria_vazia();
    novo->direita = heap_cria_vazia();
    return novo;
}

int quant_de_nos(Heap *raiz)
{
    int somador = 0;
    if (raiz == NULL)
        return 0;
    if(raiz->direita != NULL)
        somador++;
    if(raiz->esquerda != NULL)
        somador++;    
    somador += quant_de_nos(raiz->esquerda);
    somador += quant_de_nos(raiz->direita);

    return somador;
}
Heap *fila_prio_inserir(Heap *raiz, int prioridade, int dado)
{
    // SE A ARVORE NAO TIVER ELEMENTOS RETORNA NOVO COMO A RAIZ DA ARVORE
    if (raiz == NULL)
    {
        Heap *novo = insere_na_fila(prioridade, dado);
        return novo;
    }

    // SE TIVER NULO AS DUAS, INSERE NA ESQUERDA PRIMEIRO
    if (raiz->esquerda == NULL)
    {
        raiz->esquerda = fila_prio_inserir(raiz->esquerda, prioridade, dado);
    }
    // SE TIVER ESQUERDA != E DIREITA == NULO
    else if (raiz->direita == NULL)
    {
        raiz->direita = fila_prio_inserir(raiz->direita, prioridade, dado);
    }
    // SE TIVER DOIS FILHOS
    else
    {
        // MUDAR A IMPLEMNTACAO DE ADICIONAR O PROXIMO NO ANALISAR A QUANTIDADE DE NOS
        // FAZER UM CONTAGEM DE NOS NA ESQUERDA -> NA PARTE ESQUERDA E NA PARTE DIREITA
        
        if (quant_de_nos(raiz->direita) < quant_de_nos(raiz->esquerda))
            raiz->direita = fila_prio_inserir(raiz->direita, prioridade, dado);
        else{
            raiz->esquerda = fila_prio_inserir(raiz->esquerda, prioridade, dado);
        }
    }

    if (raiz->esquerda != NULL && raiz->esquerda->info.prioridade > raiz->info.prioridade)
    {
        Informacoes temp = raiz->info;
        raiz->info = raiz->esquerda->info;
        raiz->esquerda->info = temp;
    }

    if (raiz->direita != NULL && raiz->direita->info.prioridade > raiz->info.prioridade)
    {
        Informacoes temp = raiz->info;
        raiz->info = raiz->direita->info;
        raiz->direita->info = temp;
    }

    return raiz;
}

void fila_prio_imprime(Heap *a)
{
    if (a != NULL)
    {
        printf("PAI :%d\n|", a->info.prioridade);
        if (a->esquerda != NULL && a->direita != NULL)
        {
            printf("FILHOS:%d, %d\n\n\n", a->esquerda->info.prioridade, a->direita->info.prioridade);
            fila_prio_imprime(a->esquerda);
            fila_prio_imprime(a->direita);
        }
        else if (a->direita == NULL && a->esquerda != NULL)
        {
            printf("FILHO:%d\n\n\n", a->esquerda->info.prioridade);
            fila_prio_imprime(a->esquerda);
        }
        else if (a->esquerda == NULL && a->direita != NULL)
        {
            printf("FILHO:%d\n\n\n", a->direita->info.prioridade);
            fila_prio_imprime(a->direita);
        }
        else
        {
            printf("SEM FILHOS\n\n\n");
        }
    }
}
int main()
{
    Heap *a = NULL;
    a = fila_prio_inserir(a, 7, 10);
    a = fila_prio_inserir(a, 2, 10);
    a = fila_prio_inserir(a, 3, 10);
    a = fila_prio_inserir(a, 11, 10);
    a = fila_prio_inserir(a, 15, 10);
    a = fila_prio_inserir(a, 15, 10);
    a = fila_prio_inserir(a, 31, 10);
    a = fila_prio_inserir(a, 221, 10);
    a = fila_prio_inserir(a, 211, 10);
    a = fila_prio_inserir(a, 251, 10);
    a = fila_prio_inserir(a, 231, 10);

    // fila_prio_inserir(a, 13, 10);

    fila_prio_imprime(a);
}