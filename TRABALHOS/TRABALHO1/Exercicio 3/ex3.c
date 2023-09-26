#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

int verifica_elementos(Matriz* mat){
    int i,j,identidade;
    identidade = 1;

    for(i=0;i<mat->ordem;i++){
        for(j=0;j<mat->ordem;j++){
            if(i==j){
                if(mat->mat[i][j]!=1){
                    printf("O valor %d na posicao [%d][%d] viola a propriedade de matriz identidade.\n", mat->mat[i][j],i,j);
                    identidade = 0;
                }
            }
            else if(i!=j){
                if(mat->mat[i][j]!= 0){
                    printf("O valor %d na posicao [%d][%d] viola a propriedade de matriz identidade.\n", mat->mat[i][j],i,j);
                    identidade = 0;
                }
            }
        }
    }
    return identidade;
}


void verifica_ordem(int ordem){
    if(ordem <= 0){
        printf("O tamanho da ordem deve ser um valor positivo e maior que zero.");
        exit(1);
    }
}

void verifica_identidade(int verifica, int ordem){
    if(verifica == 1){
        printf("A matriz acima e uma matriz identidade de ordem %d", ordem);
    }
}

void matriz_identidade(){
    int ordem, verifica;
    Matriz* matriz;

    printf("Digite a ordem da matriz: ");
    scanf("%d", &ordem);

    verifica_ordem(ordem);

    matriz = cria_mat(ordem);
    preenche_mat(matriz);
    mostra_mat(matriz);

    verifica = verifica_elementos(matriz);
    verifica_identidade(verifica,ordem);

    desaloca_mat(matriz);
}

int main(){
    
    matriz_identidade();

    return 0;
}