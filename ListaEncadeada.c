#include <stdio.h>
#include <stdlib.h>

typedef struct Lista
{
    int valor;
    struct Lista* prox;
}Lista;

void AdicionaNo(Lista **inicio, int Entrada) {
    
    Lista *novo = (Lista *)malloc(sizeof(Lista));
    novo->valor = Entrada;
    novo->prox = *inicio; 
    *inicio = novo;      
}

void PrintaNo(Lista *Atual)
{
    while (Atual != NULL)
    {
        printf("%d\n",Atual->valor);
        Atual = Atual->prox;
    }
}
void imprime_inverso(Lista *Atual) {
    if (Atual == NULL) return; 
    imprime_inverso(Atual->prox); 
    printf("%d\n", Atual->valor);
}
void LiberaLista(Lista *inicio) {
    Lista *atual = inicio;
    while (atual != NULL) {
        Lista *temp = atual;
        atual = atual->prox;
        free(temp);
    }
}

int main()
{
    
    Lista *inicio = NULL;
    
    int N,i =0, X;
    printf("Quantos itens você deseja adicionar na sua lista? ");
    scanf("%d",&N);
    while (i < N)
    {
        int Entrada = 0;
        printf("Digite aqui o item de número %d: ",i+1);
        scanf("%d",&Entrada);
        AdicionaNo(&inicio,Entrada);
        ++i;
    }
    PrintaNo(inicio);
    imprime_inverso(inicio);
    LiberaLista(inicio);

    
}