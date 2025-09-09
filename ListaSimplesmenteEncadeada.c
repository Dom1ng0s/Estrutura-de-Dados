#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* proximo;
} No;

typedef struct Lista
{
    No *inicio;
    int tam;
}Lista;
void criar_lista(Lista *lista)
{
    lista->inicio = NULL;
    lista->tam = 0;
}

// procedimento para inserir no inicio:

void inserir_no_inicio(Lista *lista, int valor)
{
    No *novo = malloc(sizeof(No));
    if(novo){
        novo-> valor = valor;
        novo -> proximo = lista->inicio;
        lista->inicio = novo;
        lista->tam++;
    }
    else{
        printf("Erro ao alocar memória");
    }
}

// Procedimento para inserir no final:
void inserir_no_fim(Lista *lista, int valor)
{
    No *aux, *novo = malloc(sizeof(No));
    if(novo)
    {
        novo-> valor = valor;
        novo -> proximo = NULL;

        // é o primeiro?
        if(lista->inicio == NULL)
        {
            lista->inicio = novo;
        }
        else
        {
            aux = lista->inicio;
            while(aux ->proximo)
            {
                aux = aux->proximo;
            }
            aux->proximo = novo;
        }
        lista->tam++;
    }
    else 
    {
        printf("Erro ao alocar memória");
    }
    
    

}

//procedimento para inserir no meio
void inserir_no_meio(Lista *lista,int valor,int ant)
{
    No *aux, *novo = malloc(sizeof(No));

    if(novo)
    {
        novo->valor =valor;
        if(lista->inicio == NULL)
        {
            novo->proximo = NULL;
            lista->inicio = novo;
        }
        else 
        {
            aux = lista->inicio;
            while(aux-> valor != ant && aux -> proximo)
            {
                aux = aux->proximo;
            }
            novo -> proximo = aux->proximo;
            aux->proximo = novo;
        }
        lista->tam++;
    }
    else printf("Erro ao alocar memória");
}

// imprimir

void imprimir(Lista lista)
{
    No *no = lista.inicio;
    printf("\n\tLista de %d elementos: ",lista.tam);
    while(no)
    {
        printf("%d - ",no->valor);
        no = no->proximo;
    }
    printf("\nFim da Lista\n");
}


int main()
{
    int opcao,valor,ant;
    //No *lista = NULL;
    Lista lista;
    criar_lista(&lista);
    do{
        printf("\n\t0 - Sair \n\t1 - InserirI \n\t2 - InserirF \n\t3 - InserirM \n\t4 - Imprimir\n\t Opção: ");
        scanf("%d",&opcao);
        switch (opcao)
        {
            case 0:
                printf("Saindo...");
                break;
            case 1:
                
                printf("Digite o valor a ser inserido no inicio: ");
                scanf("%d",&valor);
                inserir_no_inicio(&lista,valor);
                imprimir(lista);
                break;
            case 2:
                
                printf("Digite o valor a ser inserido no fim: ");
                scanf("%d",&valor);
                inserir_no_fim(&lista,valor);
                imprimir(lista);
                break;
            case 3:
                
                printf("Digite o valor a ser inserido no meio: ");
                scanf("%d",&valor);
                printf("Digite o valor anterior ao qual deseja inserir: ");
                scanf("%d",&ant);
                inserir_no_meio(&lista,valor,ant);
                imprimir(lista);
                break;
            case 4:
                imprimir(lista);
                break;
            default:
                printf("Opção inválida");
                break;
            }
    }while(opcao !=0);
}
