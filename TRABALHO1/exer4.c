#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// 4) Matriz de n dimensões - Faça um programa que trate uma matriz de inteiros de 3 dimensões (linhas, colunas e profundidade), conforme figura abaixo:

int ***aloca_matriz(int m, int n, int z)
{
    int ***mat;
    int i, j;
    mat = (int ***)malloc(m * sizeof(int **));

    for (i = 0; i < m; i++)
    {
        mat[i] = (int **)malloc(n * sizeof(int *));
        for (j = 0; j < n; j++)
        {

            mat[i][j] = (int *)malloc(z * sizeof(int));
        }
    }
    return mat;
}

void preenche_matriz(int m, int n, int z, int ***mat)
{
    int i, j, k;
    bool perguntar_valor = true;
    char parar;
    for (k = 0; k < z; k++)
    {
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (perguntar_valor)
                {
                    printf("DIGITE UM VALOR PARA [%d,%d,%d]:", i + 1, j + 1, k + 1);
                    scanf("%d", &mat[i][j][k]);
                    printf("\n");

                    if (k == z - 1 && i == m - 1 && j == n - 1)
                    {
                        printf("MATRIZ TOTALMENTE PREENCHIDA!!\n\n");
                        break;
                    }

                    printf("DIGITE 'P' PARA PARAR DE PREENCHE:");
                    scanf(" %c", &parar);
                    printf("\n");

                    if (parar == 'p' || parar == 'P')
                    {
                        perguntar_valor = false;
                        printf("PREENCHIMENTO INTERROMPIDO.\n\n");
                    }
                }
                else
                {
                    mat[i][j][k] = 0;
                }
            }
        }
    }
}

void imprime_matriz(int m, int n, int z, int ***mat)
{
    int i, j, k;
    for (k = 0; k < z; k++)
    {
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < n; j++)
            {
                printf("|%d|", mat[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
}
void solicita_dimencoes(int *i, int *j, int *k)
{

    printf("DIGITE O NUMERO DE LINHAS:");
    scanf("%d", &i);

    printf("DIGITE O NUMERO DE COLUNAS:");
    scanf("%d", &j);

    printf("DIGITE O NUMERO DA PROFUNDIDADE:");
    scanf("%d", &k);
}

int main()
{
    int ***matriz;
    int i, j, k;
    solicita_dimencoes(&i, &j, &k);

    matriz = aloca_matriz(i, j, k);
    preenche_matriz(i, j, k, matriz);
    imprime_matriz(i, j, k, matriz);
}