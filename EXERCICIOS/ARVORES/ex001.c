#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 1.Faça o percurso pré-ordem, pós-ordem e ordem simétrica. Mostre a saída gerada.
// Monte a árvore em C e implemente as funções de percurso pré-ordem, pós-ordem e ordem simétrica (imprimindo na ordem correta na tela).

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
void pre_ordem(Arv *arvore)
{
    if (!arv_vazia(arvore))
    {
        printf("%d|", arvore->info);
        pre_ordem(arvore->esquerda);
        pre_ordem(arvore->direita);
    }
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

// IMPRESSÃO
void pos_ordem(Arv *arvore)
{
    if (!arv_vazia(arvore))
    {
        pos_ordem(arvore->esquerda);
        pos_ordem(arvore->direita);
        printf("%d|", arvore->info);
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
// QUESTAO 2;
int pares(Arv *a)
{
    if (arv_vazia(a))
    {
        return 0;
    }
    int contagem = 0;
    if (a->info % 2 == 0)
    {
        contagem++;
    }

    contagem += pares(a->esquerda);
    contagem += pares(a->direita);
    return contagem;
}
// 3. Implemente uma função que crie uma cópia de uma árvore binária.
Arv *arv_copia(Arv *a)
{
    if (arv_vazia(a))
    {
        return a;
    }
    Arv *copia = (Arv *)malloc(sizeof(Arv));

    copia->esquerda = arv_copia(a->esquerda);
    copia->direita = arv_copia(a->direita);
    copia->info = a->info;

    return copia;
}

// 4. Implemente uma função que retorne a quantidade de folhas de uma árvore binária.
// Esta função deve obedecer ao protótipo:
int folhas(Arv *a)
{
    if (arv_vazia(a))
    {
        return 0;
    }
    int contador = 0;
    if (a->esquerda == NULL && a->direita == NULL)
    {
        contador++;
    }
    else
    {
        contador += folhas(a->esquerda);
        contador += folhas(a->direita);
    }
    return contador;
}

// 5.Implemente uma função que retorne a quantidade de nós de uma árvore binária que possuem apenas um filho.
int um_filho(Arv *a)
{
    if (arv_vazia(a))
    {
        return 0;
    }
    int contador = 0;
    if (a->direita == NULL && a->esquerda != NULL)
    {
        contador++;
    }
    else if (a->esquerda == NULL && a->direita != NULL)
    {
        contador++;
    }
    contador += um_filho(a->esquerda);
    contador += um_filho(a->direita);
    return contador;
}
// 6. Implemente uma função que compare se duas árvores binárias são iguais.
bool igual(Arv *a, Arv *b)
{
    bool verdadeiro = false;
    if (arv_vazia(a) || arv_vazia(b))
    {
        if (arv_vazia(a) && arv_vazia(b))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    if (a->info == b->info)
    {
        verdadeiro = true;
    }
    else
    {
        return false;
    }

    verdadeiro = igual(a->esquerda, b->esquerda);
    if (!verdadeiro)
        return false;

    verdadeiro = igual(a->direita, b->direita);

    return verdadeiro;
}

int main()
{
    Arv *g = arv_cria(1, arv_cria(7, arv_cria_vazia(), arv_cria_vazia()), arv_cria_vazia());
    Arv *h = arv_cria(1, arv_cria(7, arv_cria_vazia(), arv_cria_vazia()), arv_cria_vazia());
    Arv *d = arv_cria(1, arv_cria(7, g, arv_cria_vazia()), arv_cria(23, arv_cria_vazia(), h));

    Arv *raiz = arv_cria(47, arv_cria_vazia(), arv_cria(25, arv_cria_vazia(), arv_cria(3, d, arv_cria_vazia())));

    Arv *p = arv_cria(1, arv_cria(7, arv_cria_vazia(), arv_cria_vazia()), arv_cria_vazia());
    Arv *q = arv_cria(1, arv_cria(7, arv_cria_vazia(), arv_cria_vazia()), arv_cria_vazia());
    Arv *s = arv_cria(1, arv_cria(7, p, arv_cria_vazia()), arv_cria(23, arv_cria_vazia(), q));

    Arv *raiz2 = arv_cria(47, arv_cria_vazia(), arv_cria(25, arv_cria_vazia(), arv_cria(3, s, arv_cria_vazia())));

    printf("\n");
    printf("FOLHAS: %d\n", folhas(raiz2));
    printf("POSSUEM APENAS UM FILHO: %d", um_filho(raiz2));

    printf("SAO UGUAIS: %d", igual(raiz2, raiz));
}