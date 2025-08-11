#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    char nome[20];
    char sobrenome[30];
    char telefone[11];
    char telefone_residencial[10];
    char telefone_celular[11];
    bool Deletado; // Indica se o contato foi deletado
} Contato;

void exibirMenu() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif

    printf("---------- AGENDA DE CONTATOS ----------\n");
    printf("1. Mostrar lista de Contatos\n");
    printf("2. Adicionar Contato\n");
    printf("3. Apagar Contato\n");
    printf("0. Sair\n");
    printf("----------------------------------------\n");
}

int main()
{
    int opcao;
    Contato contatos[100];
    int numContatos;
    do
    {
        exibirMenu();
        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);
        int c;
        while ((c = getchar()) != '\n' && c != EOF);

    }while (opcao != 0);
}