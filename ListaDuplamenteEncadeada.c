#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* proximo;
    struct No* anterior;
} No;
typedef struct Lista
{
    No *inicio;
    No *fim;
    int tamanho;
}Lista;

Lista* criar_lista() {
    Lista *nova_lista = malloc(sizeof(Lista));
    nova_lista->inicio = NULL;
    nova_lista->fim = NULL;
    nova_lista->tamanho = 0;
    return nova_lista;
}

void inserir_no_inicio(Lista *lista, int valor) {
    No *novo = malloc(sizeof(No));
    if (novo) {
        novo->valor = valor;
        novo->proximo = lista->inicio; 
        novo->anterior = NULL;
        
        if (lista->inicio != NULL) {
            lista->inicio->anterior = novo;
        } else {
            lista->fim = novo;
        }
        
        lista->inicio = novo; 
        lista->tamanho++;      
    }
}

void inserir_no_final(No **inicio, int valor) {
    No *aux, *novo = malloc(sizeof(No));
    if(novo) {
        novo->valor = valor;
        novo->proximo = NULL;

        if(*inicio == NULL) {
            *inicio = novo;
        } else {
            aux = *inicio;
            while(aux->proximo) { 
                aux = aux->proximo;
            }
            aux->proximo = novo;
            novo->anterior = aux;
        }
    }
}

void imprime_do_inicio(Lista *lista) {
    printf("Lista do inicio para o fim (%d elementos): ", lista->tamanho);
    No *atual = lista->inicio; 
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("\n");
}

void liberar_lista(Lista *lista) {
    No *atual = lista->inicio; 
    while (atual != NULL) {
        No *temp = atual;
        atual = atual->proximo;
        free(temp);
    }
    free(lista);
}

void imprime_do_final(Lista *lista) {
    printf("Lista do fim para o inicio (%d elementos): ", lista->tamanho);
    No *atual = lista->fim; 
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->anterior;
    }
    printf("\n");
}

void exibir_menu() {
    printf("\n--- MENU - Lista Duplamente Encadeada ---\n");
    printf("1. Inserir um valor no INÍCIO\n");
    printf("2. Inserir um valor no FINAL\n");
    printf("3. Imprimir a lista (do início ao fim)\n");
    printf("4. Imprimir a lista (do fim ao início)\n");
    printf("5. Ver o tamanho atual da lista\n");
    printf("0. Sair do programa\n");
    printf("Escolha uma opção: ");
}

int main() {
    Lista *minha_lista = criar_lista();
    int opcao;
    int valor;

    do {
        exibir_menu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor para inserir no início: ");
                scanf("%d", &valor);
                inserir_no_inicio(minha_lista, valor);
                printf("Valor %d inserido com sucesso!\n", valor);
                break;

            case 2:
                printf("Digite o valor para inserir no final: ");
                scanf("%d", &valor);
                inserir_no_final(minha_lista, valor);
                printf("Valor %d inserido com sucesso!\n", valor);
                break;

            case 3:
                if (minha_lista->inicio == NULL) {
                    printf("A lista está vazia!\n");
                } else {
                    imprime_do_inicio(minha_lista);
                }
                break;

            case 4:
                if (minha_lista->inicio == NULL) {
                    printf("A lista está vazia!\n");
                } else {
                    imprime_do_final(minha_lista);
                }
                break;
            
            case 5:
                printf("Tamanho atual da lista: %d\n", minha_lista->tamanho);
                break;

            case 0:
                printf("Encerrando o programa...\n");
                break;

            default:
                printf("Opção inválida! Tente novamente.\n");
                break;
        }

    } while (opcao != 0);

    liberar_lista(minha_lista);
    printf("Memória liberada. Programa finalizado.\n");
    
    return 0;
}
