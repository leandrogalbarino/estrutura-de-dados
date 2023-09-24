struct diagonal{
    int ordem; 
    int* v; 
};
typedef struct diagonal Diagonal;

Diagonal aloca_mat(int ordem);
Diagonal preenche_mat(Diagonal vet, int ordem);
void mostra_mat(Diagonal vet, int ordem);