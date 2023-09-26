#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

Diagonal aloca_mat(int ordem){
    Diagonal vet;
    int i,j;

    vet.ordem = ordem;
    vet.v = (int*)malloc(ordem*sizeof(int));

    if(vet.v == NULL){
        printf("Erro na alocacao dinamica.");
        exit(1);
    }
    return vet;
}

Diagonal preenche_mat(Diagonal vet, int ordem){
    int i;

    for(i=0;i<ordem;i++){
        printf("Valor de [%d][%d]: ", i,i);
        scanf("%d", &vet.v[i]);
    }
}

void mostra_mat(Diagonal vet, int ordem){
    int i,j;

    for(i=0;i<ordem;i++){
        for(j=0;j<ordem;j++){
            if(i==j){
                printf("%d ", vet.v[i]);
            }
            else{
                printf("0 ");
            }
        }
        printf("\n");
    }
}