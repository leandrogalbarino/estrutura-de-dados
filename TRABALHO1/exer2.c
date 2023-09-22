#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
// 2. Faça um programa que trate uma matriz esparsa de inteiros. O programa deve armazenar os valores não nulos da matriz esparsa em uma lista simplesmente encadeada (ver struct Lista), e os demais valores (que são nulos) não devem ser lidos nem armazenados em lugar algum. O programa deve contemplar as operações de:

struct lista
{
    int linha;
    int coluna;
    int info;
    struct lista *prox;
};
typedef struct lista Lista;

struct esparsa
{
    int linhas;
    int colunas;
    struct lista *prim;
};
typedef struct esparsa Esparsa;

//  Criação da matriz;
Lista *mat_cria(Esparsa *matriz)
{
    Lista *p;
    int linhas, colunas;
    printf("DIGITE O NUMERO DE LINHAS:");
    scanf("%d", &linhas);
    printf("DIGITE O NUMERO DE COLUNAS:");
    scanf("%d", &colunas);
    printf("\n");

    matriz->linhas = linhas;
    matriz->colunas = colunas;
    p = NULL;
    return p;
}
int verif_num_maior_que_limite(int *numero, int *limite)
{
    int pergunta;
    if (*numero > *limite)
    {
        printf("VOCE DIGITOU UM NUMERO MAIOR QUE O LIMITE %d!!\n", *limite);
        printf("DESEJA AUMENTAR O LIMITE? (S/N): ");
        scanf(" %c", &pergunta);
        printf("\n");
    }
    return pergunta;
}

void verif_num_menor_que_limite(int *numero, int *limite)
{
    if (*numero <= 0)
    {
        printf("VOCE DIGITOU UM NUMERO MENOR QUE O LIMITE!!\n");
        printf("POR FAVOR, FORNECA UM NUMERO ENTRE 1 - %d\n\n", *limite);
    }
}

void solicitarNumero(int *numero, int *limite, char *nome)
{
    char pergunta;

    while (1)
    {
        printf("DIGITE O NUMERO DA %s:", nome);
        scanf("%d", numero);
        if (*numero <= *limite && *numero > 0)
        {
            return;
        }

        pergunta = verif_num_maior_que_limite(numero, limite);
        verif_num_menor_que_limite(numero, limite);

        if (pergunta == 'S' || pergunta == 's')
        {
            *limite = *numero;
            return;
        }
    }
}

void informacoes(int *linha, int *coluna, int *info, Esparsa *matriz)
{
    Lista *p;
    int iguais;

    do
    {
        iguais = 0;
        solicitarNumero(linha, &matriz->linhas, "LINHA");
        solicitarNumero(coluna, &matriz->colunas, "COLUNA");
        for (p = matriz->prim; p != NULL; p = p->prox)
        {
            if (p->linha == *linha && p->coluna == *coluna)
            {
                printf("A LINHA E A COLUNA QUE VOCE INFORMOU JA ARMAZENA UMA VARIAVEL! ");
                printf("POR FAVOR, INFORME OUTRA:\n\n");
                iguais = 1;
            }
        }
    } while (iguais == 1);

    printf("DIGITE A VARIAVEL:");
    scanf("%d", info);
    printf("\n");
}

Lista *mat_ult(Lista *l)
{
    Lista *p;
    if (l == NULL)
    {
        return l;
    }

    for (p = l; p != NULL; p = p->prox)
    {
        if (p->prox == NULL)
        {
            break;
        }
    }
    return p;
}

Lista *lista_aloca()
{
    Lista *p;
    p = (Lista *)malloc(sizeof(Lista));

    if (p == NULL)
    {
        printf("FALHA EM ALOCAR, O PROGRAMA SERÁ ENCERRADO");
        exit(1);
    }
    return p;
}

void matriz_info(int linha, int coluna, int info, Lista *l)
{
    l->linha = linha;
    l->coluna = coluna;
    l->info = info;
    l->prox = NULL;
}

//  Preenchimento da matriz (ler apenas os valores não nulos);
Lista *mat_preenche(Esparsa *matriz)
{
    Lista *p;
    Lista *l = NULL;
    int info, linha, coluna;
    char deseja_continuar = 'S';

    while (deseja_continuar == 'S' || deseja_continuar == 's')
    {
        if (matriz->prim == NULL)
        {
            informacoes(&linha, &coluna, &info, matriz);
            if (info != 0)
            {
                // tratar quando linha <= 0;
                l = lista_aloca();
                matriz_info(linha, coluna, info, l);
                matriz->prim = l;
            }
        }
        else
        {
            p = mat_ult(matriz->prim);
            informacoes(&linha, &coluna, &info, matriz);
            if (info != 0)
            {
                p->prox = lista_aloca();
                p = p->prox;
                matriz_info(linha, coluna, info, p);
            }
        }

        printf("DIGITE 'S' PARA CONTINUAR:");
        scanf(" %c", &deseja_continuar);
        printf("\n");
    }

    return matriz->prim;
}

void mat_busca_printa(Esparsa *matriz, int i, int j)
{
    Lista *p;
    for (p = matriz->prim; p != NULL; p = p->prox)
    {
        if ((p->linha == i && p->coluna == j) && p->info != 0)
        {
            printf("|%d|", p->info);
            return;
        }
    }
    printf("|0|");
}

//  Impressão da matriz;
void mat_imprime(Esparsa *matriz)
{
    int i, j;
    for (i = 1; i <= matriz->linhas; i++)
    {
        for (j = 1; j <= matriz->colunas; j++)
        {
            mat_busca_printa(matriz, i, j);
        }
        printf("\n");
    }
}

void mat_busca(int linha, int coluna, Esparsa *matriz)
{
    Lista *p;
    for (p = matriz->prim; p != NULL; p = p->prox)
    {
        if (p->linha == linha && p->coluna == coluna)
        {
            printf("O ELEMENTO DE [%d,%d] TEM VALOR:%d\n\n", linha, coluna, p->info);
            return;
        }
    }
    if ((linha <= matriz->linhas && coluna <= matriz->colunas) && (linha > 0 && coluna > 0))
    {
        printf("O ELEMENTO DE [%d,%d] TEM VALOR:0\n\n", linha, coluna);
    }
    else
    {
        printf("[%d,%d] NAO EXISTE NA MATRIZ\n\n", linha, coluna);
    }
}

//  Consulta de um determinado elemento da matriz   ;
void mat_consulta_elemento(Esparsa *matriz)
{
    int linha, coluna;

    printf("DIGITE A LINHA QUE DESEJA CONSULTAR:");
    scanf("%d", &linha);

    printf("DIGITE A COLUNA QUE DESEJA CONSULTAR:");
    scanf("%d", &coluna);
    printf("\n");

    mat_busca(linha, coluna, matriz);
}

int soma_linha(Esparsa *matriz, int linha)
{
    Lista *p;
    int somatorio = 0;
    for (p = matriz->prim; p != NULL; p = p->prox)
    {
        if (p->linha == linha)
        {
            somatorio = somatorio + p->info;
        }
    }
    return somatorio;
}

//  Impressão de somatório de uma linha i (informada pelo usuário);
void mat_imprime_somatorio(Esparsa *matriz)
{
    int linha;
    int somatorio = 0;
    printf("DIGITE A LINHA QUE DESEJA IMPRIMIR O SOMATORIO:");
    scanf("%d", &linha);
    printf("\n");

    if ((linha <= matriz->linhas) && (linha > 0))
    {
        somatorio = soma_linha(matriz, linha);
        printf("SOMATORIO DA LINHA %d: %d\n\n", linha, somatorio);
    }
    else
    {
        printf("A LINHA [%d] NAO EXISTE NA MATRIZ\n\n", linha);
    }
}

int quantidade_de_nos(Esparsa *matriz)
{
    int nos = 0;
    Lista *p;
    for (p = matriz->prim; p != NULL; p = p->prox)
    {
        nos++;
    }
    return nos;
}

//  Percentual de elementos não nulos na matriz lida.
void mat_percentual(Esparsa *matriz)
{
    float percentual = 0;
    int nos = quantidade_de_nos(matriz);
    percentual = (float)nos / (matriz->linhas * matriz->colunas);
    printf("O PERCENTUAL DE NOS DA MATRIZ:%f\n\n", percentual);
}

int main()
{
    Esparsa matriz;
    matriz.prim = mat_cria(&matriz);
    matriz.prim = mat_preenche(&matriz);
    mat_imprime(&matriz);
    mat_consulta_elemento(&matriz);
    mat_imprime_somatorio(&matriz);
    mat_percentual(&matriz);
}