#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

Matriz* cria_mat(int ordem){
    int i;
    Matriz* matriz = (Matriz*)malloc(sizeof(Matriz));
    if(matriz==NULL){
        printf("Erro na alocacao dinamica");
    }

    matriz->ordem = ordem;

    matriz->mat = (int**)malloc(matriz->ordem*sizeof(int*));
    if(matriz->mat==NULL){
        printf("Erro na alocacao dinamica");
        exit(1);
    }

    for(i=0;i<matriz->ordem;i++){
        matriz->mat[i] = (int*)malloc(matriz->ordem*sizeof(int));
        if(matriz->mat[i]==NULL){
            printf("Erro na alocacao dinamica");
            exit(1);
        }
    }

    return matriz;
}

void preenche_mat(Matriz* mat){
    int i,j;

    for(i=0;i<mat->ordem;i++){
        for(j=0;j<mat->ordem;j++){
            printf("Insira o valor na posicao [%d][%d]: ",i,j);
            scanf("%d", &mat->mat[i][j]);
        }
    }

}

void mostra_mat(Matriz* mat){
    int i,j;

    printf("Matriz:\n");
    for(i=0;i<mat->ordem;i++){
        for(j=0;j<mat->ordem;j++){
            printf("%d ",mat->mat[i][j]);
        }
        printf("\n");
    }
}

void desaloca_mat(Matriz* mat){
    int i;

    for(i=0;i<mat->ordem;i++){
        free(mat->mat[i]);
    }
    free(mat->mat);
}
