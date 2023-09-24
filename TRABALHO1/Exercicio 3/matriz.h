struct matriz{
    int ordem;
    int** mat;
};
typedef struct matriz Matriz;

Matriz* cria_mat(int ordem);
void preenche_mat(Matriz* mat);
void mostra_mat(Matriz* mat);
void desaloca_mat(Matriz* mat);
