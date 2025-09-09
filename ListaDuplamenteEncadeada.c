#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* proximo;
    struct No* anterior;
} No;

void inserir_no_inicio(No **inicio, int valor) {
    No *novo = malloc(sizeof(No));
    novo->valor = valor;
    novo->proximo = *inicio;
    novo->anterior = NULL;
    if (*inicio != NULL) (*inicio)->anterior = novo;
    *inicio = novo;
}
void imprime_do_inicio(No *inicio) {
    No *atual = inicio;
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
}
void LiberaLista(No *inicio) {
    No *atual = inicio;
    while (atual != NULL) {
        No *temp = atual;
        atual = atual->proximo;
        free(temp);
    }
}
void ImprimeFinal(No *inicio)
{
    No *atual = inicio;
    while(atual && atual-> proximo){
        atual = atual->proximo;
    }
    while (atual != NULL) {
        printf("%d ",atual->valor);
        atual = atual->anterior;
    }

}

int main ()
{
    int N, i = 0, X;
    printf("Digite aqui quantos valores você deseja inserir:");
    scanf("%d",&N);
    No*inicio = NULL;
    while ( i < N)
    {
        printf("Digite aqui o valor do nó %d:",i+1);
        scanf("%d",&X);
        inserir_no_inicio(&inicio,X);
        

        ++i;
    }
    imprime_do_inicio(inicio);
    printf("\n");
    ImprimeFinal(inicio);
    LiberaLista(inicio);
    
}
