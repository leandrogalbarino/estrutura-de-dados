#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// implemente uma funcao com lista simples, que empresta um livro pelo nome, se tiver desponivel muda disponibilidade para 0;

struct lista
{
    int id;
    char nome[50];
    char descrissao[50];
    int disponivel;
    struct lista *prox;
};
typedef struct lista Lista;

void retira_livro(Lista *l, char *nome_livro)
{
    Lista *p;
    if (l == NULL)
    {
        printf("NÃO EXISTEM LIVROS\n");
        return;
    }
    for (p = l; p != NULL; p = p->prox)
    {
        if (strcmp(nome_livro, p->nome) == 0)
        {
            if (p->disponivel == 1)
            {
                printf("LIVRO EMPRESTADO COM SUCESSO!!\n");
                    p->disponivel = 0;
                break;
            }
            else
            {
                printf("LIVRO INDISPONIVEL NO MOMENTO!!\n");
                break;
            }
        }
    }
    if (p == NULL)
    {
        printf("LIVRO NÃO ENCONTRADO\n");
    }
}
