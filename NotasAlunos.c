#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

typedef struct aluno
{
    char nome[12];
    double nota;
    bool aprovado;
}aluno;
void bubbleSortNome(int n, aluno turma[n]) {
    int i,j;
    aluno temp;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) 
        {
            if (strcmp(turma[i].nome, turma[j].nome)>0) 
                {
                    temp = turma[i];
                    turma[i] = turma[j];
                    turma[j] = temp;
                }
         }
    }
}   

int contemNumero(const char *nome) {
    for (int j = 0; nome[j] != '\0'; j++) {
        if (isdigit(nome[j])) {
            return 1;
        }
    }
    return 0;
}
int eMaiuscula(const char *nome){
    
    if (isupper(nome[0])) {
         return 0;
    }
    
    return 1;
}

void BuscaPorNome(int n, aluno turma[n])
{
    printf("Busca por nome selecionada. ");
    erro_nome2: 
    printf("Por favor digite o nome com letra maiúscula:");
    char nome[15];
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';
    if (eMaiuscula(nome))
    {
        printf("Erro: Nome não começa com letra maiúscula, por favor tente novamente\n");
        goto erro_nome2;
    }
    int contador= 0;
        for(int i = 0; i < n;i++)
        {
            
            if(strcmp(nome, turma[i].nome) == 0) 
            {
                if(turma[i].aprovado ==  true)
                {
                    printf("%s foi aprovado(a) com nota %.2f\n",turma[i].nome, turma[i].nota);
                }
                else
                {
                    printf("%s não foi aprovado(a), pois ficou com nota %.2f\n",turma[i].nome, turma[i].nota);
                }

                contador +=1;
                
            }         
        }
    if (contador == 1)
    {
        printf("Existe 1 pessoa com nome de %s",nome);
    }
    else if (contador != 1)
    {
        printf("Existem %d pessoas com nome de %s",contador,nome);
    }
    
}
void Todos(int n, aluno turma[n])
{
    printf("Todos os alunos cadastrados:\n");
    for(int i = 0; i < n; i++)
    {
        if(turma[i].aprovado == true)
        {
            printf("%s foi aprovado(a) com nota %.2f\n",turma[i].nome, turma[i].nota);
        }
        else
        {
            printf("%s não foi aprovado(a), pois ficou com nota %.2f\n",turma[i].nome, turma[i].nota);
        }
    }
}
void BubbleArray(int n,aluno turma[n])
{
    int i, j;
    aluno temp;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) 
        {
            if (strcmp(turma[i].nome, turma[j].nome) == 0) 
            {
                if(turma[i].nota < turma[j].nota)
                {
                    temp = turma[i];
                    turma[i] = turma[j];
                    turma[j] = temp;
                }
            }
         }
    }

}


int main()
{
    int n;
    printf("Quantos alunos deseja cadastrar?");
    scanf("%d", &n);
    getchar();
    aluno turma[n];
    
    for( int i = 0; i < n; i++)
    {
        erro_nome:
        printf("Nome do aluno %d: \n",i+1);
        fgets(turma[i].nome, sizeof(turma[i].nome), stdin);
        turma[i].nome[strcspn(turma[i].nome, "\n")] = '\0';

        if(contemNumero(turma[i].nome))
        {
            printf("ERRO: Nome possui número, favor tentar novamente\n");

            goto erro_nome;
        }
        if(eMaiuscula(turma[i].nome))
        {
            printf("ERRO: Nome não possui a primeira letra maiúscula, favor tentar novamente\n");

            goto erro_nome;
        }
        
        int leitura_valida;
        do {
            erro_nota:
            printf("Nota do aluno %d:\n", i + 1);
            leitura_valida = scanf("%lf", &turma[i].nota);
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            if (leitura_valida != 1) {
                printf("ERRO: Entrada invalida. Por favor, digite um numero.\n");
            }
            else if (turma[i].nota < 0 || turma[i].nota > 10) {
                printf("ERRO: A nota deve estar entre 0 e 10. Tente novamente.\n");
                leitura_valida = 0; 
            }
        } while (leitura_valida != 1); 

        if(turma[i].nota < 0 || turma[i].nota > 10)
        {
            printf("ERRO: Nota precisa estar entre 0 e 10. Por favor tente novamente \n");
            goto erro_nota;
        }
        if(turma[i].nota >= 7)
        {
            turma[i].aprovado = true;
        }
        else 
        {
            turma[i].aprovado = false;
        }
    }
    bubbleSortNome(n,turma);
    BubbleArray(n,turma);
    erro_escolha:
    printf("Deseja buscar por nome ou ver todos os alunos cadastrados? (1 para nome, 2 para todos): ");
    int opcao;
    scanf("%d", &opcao);
    if(opcao == 1)
    {
        
        BuscaPorNome(n,turma);
    }
    else if(opcao == 2)
    {   
        
        Todos(n,turma);
    }
    else
    {
        printf("Opção inválida. Por favor, escolha 1 ou 2.\n");
        goto erro_escolha;
    }
    return 0;
}
