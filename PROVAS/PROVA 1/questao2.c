#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct lista
{
    char data;
    struct lista *prox;
};
typedef struct lista Lista;

Lista *empilhar(Lista *l, char data)
{
    Lista *novo = (Lista *)malloc(sizeof(Lista));
    if (novo == NULL)
        exit(1);
    novo->data = data;
    novo->prox = l;
    return novo;
}
Lista *desempilhar(Lista *l)
{
    Lista *p = l->prox;
    free(l);
    return p;
}

int lista_vazia(Lista *l)
{
    if (l == NULL)
        return 1;
    else
        return 0;
}

// IMPLEMENTADA NA HORA DA PROVA;
int testa_Parenteces(char *expressao)
{
    Lista *l = NULL;
    int i;
    for (i = 0; i < strlen(expressao); i++)
    {
        if (expressao[i] == '(')
        {
            l = empilhar(l, expressao[i]);
        }
    }
    Lista *p;
    int parenteces_abertos = 0;
    int parenteces_fechados = 0;
    for (p = l; p != NULL; p = p->prox)
    {
        if (p->data == '(')
            parenteces_abertos++;
        if (p->data == ')')
            parenteces_fechados++;
    }

    if (parenteces_abertos == parenteces_fechados)
    {
        return 1;
    }
    return 0;
}

// CORRETA, NÃO IMPLEMENTEI ESSA VERSAO
int testa_Parenteces(char *expressao)
{
    Lista *l = NULL;
    int i;
    for (i = 0; i < strlen(expressao); i++)
    {
        if (expressao[i] == '(')
        {
            l = empilhar(l, expressao[i]);
        }
        else if (expressao[i] == ')')
        {
            if (l == NULL)
            {
                return 0;
            }
            else
            {
                l = desempilha(l);
            }
        }
    }

    if (lista_vazia(l))
    {
        return 1;
    }
    return 0;
}