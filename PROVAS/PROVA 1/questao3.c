#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct fila
{
    int id;
    char tarefa[50];
    struct fila *prox;
};
typedef struct fila Fila;

Fila *aciona_tarefa(Fila *l, int id, char *tarefa)
{
    Fila *novo = (Fila *)malloc(sizeof(Fila));
    novo->id = id;
    strcpy(novo->tarefa, tarefa);
    novo->prox = NULL;

    if (l == NULL)
        return novo;
    Fila *p;
    for (p = l; p != NULL; p = p->prox)
    {
        if (p->prox == NULL)
        {
            p->prox = novo;
            break;
        }
    }
    return l;
}