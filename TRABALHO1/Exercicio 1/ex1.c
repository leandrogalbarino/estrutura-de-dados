#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

int consulta(Diagonal vet, int ordem){
    int i;
    int linha, coluna;
    char tecla;

    do{
        mostra_mat(vet,ordem);

        printf("Informe a linha onde se encontra: ");
        scanf("%d", &linha);
        printf("Informe a coluna onde se encontra: ");
        scanf("%d", &coluna);

        if(linha && coluna < ordem){
            if(linha != coluna){
                printf("Valor 0 encontrado na posicao [%d][%d] da matriz.\n", linha, coluna);
                printf("Quer consultar novamente(s/n)? ");
                scanf(" %c", &tecla);
            }
            else if(linha == coluna){
                printf("Valor %d encontrado na posicao [%d][%d] da matriz.\n", vet.v[linha], linha, coluna);
                printf("Quer consultar novamente(s/n)? ");
                scanf(" %c", &tecla);
            }
        }
        else if(linha || coluna >= ordem){
            printf("Nao existe nenhum valor na posicao [%d][%d] pois a consulta se encontra fora do tamanho da matriz %dx%d.\n", linha, coluna, ordem, ordem);
            printf("Quer consultar novamente(s/n)? ");
            scanf(" %c", &tecla);
        }

    }while(tecla == 's');
}

int main(){
    Diagonal vet;

    printf("Tamanho da ordem: ");
    scanf("%d", &vet.ordem);

    vet = aloca_mat(vet.ordem);
    preenche_mat(vet,vet.ordem);
    consulta(vet,vet.ordem);

    free(vet.v);

    return 0;
}