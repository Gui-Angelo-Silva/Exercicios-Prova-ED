#include <stdio.h>
#include <string.h>
#define N 3

struct Dados
{
    int codigo;
    char nome[30];
    int telefone;
};

typedef struct Dados Dados;

void preencher(Dados usuario[], int *insercao);
void listar(Dados usuario[], int *insercao);
void ordenarNome(Dados usuario[], int *insercao);
void consulta(Dados usuario[], int *insercao);

int main()
{

    Dados usuario[N];
    int insercao, n, aux;

    for (int i = 0;; i++)
    {
        printf("-----------Menu-----------\n");
        printf("[1] - Cadastro de usuário\n");
        printf("[2] - Listar os usuários\n");
        printf("[3] - Ordenar os usuários\n");
        printf("[4] - Consulta pelo nome\n");
        printf("[0] - Sair\n");
        printf("--------------------------\n");
        scanf("%d", &n);

        if (n == 0)
        {
            break;
        }

        if (n == 1)
        {
            printf("\n---------Cadastro---------\n");
            preencher(usuario, &insercao);
        }

        if (n == 2)
        {
            printf("\n\n----------Listar----------\n");
            listar(usuario, &insercao);
        }

        if (n == 3)
        {
            printf("\n\n---------Ordenar----------\n");
            ordenarNome(usuario, &insercao);
        }

        if (n == 4)
        {
            printf("\n---------Consulta---------\n");
            consulta(usuario, &insercao);
        }
    }
}

void preencher(Dados usuario[], int *insercao)
{

    printf("Informe o código: ");
    scanf("%d", &usuario[*insercao].codigo);
    printf("Informe o nome: ");
    scanf("%s", &usuario[*insercao].nome);
    printf("Informe o telefone: ");
    scanf("%d", &usuario[*insercao].telefone);
    printf("--------------------------\n");
    *insercao += 1;
}

void listar(Dados usuario[], int *insercao)
{
    for (int i = 0; i < *insercao; i++)
    {
        printf("Código: %d\n", usuario[i].codigo);
        printf("Nome: %s\n", usuario[i].nome);
        printf("Telefone: %d\n", usuario[i].telefone);
        printf("--------------------------\n");
    }
}

void ordenarNome(Dados usuario[], int *insercao)
{
    for (int i = 0; i < (*insercao - 1); i++)
    {
        int comp = strcmp(usuario[i].nome, usuario[(i + 1)].nome);

        if (comp > 0)
        {
            Dados aux;
            aux = usuario[i];
            usuario[i] = usuario[i + 1];
            usuario[i + 1] = aux;
            i =- 1;
        }
    }

    for(int i = 0; i < *insercao; i++){
        printf("Código: %d\n", usuario[i].codigo);
        printf("Nome: %s\n", usuario[i].nome);
        printf("Telefone: %d\n", usuario[i].telefone);
        printf("--------------------------\n");
    }
}

void consulta(Dados usuario[], int *insercao)
{
    char pnome[30];

    printf("Informe o nome para ser pesquisado: ");
    scanf("%s", &pnome);

    int enc = 0;

    for (int i = 0; i < *insercao; i++)
    {
        int comp = strcmp(pnome, usuario[i].nome);

        if (comp == 0)
        {
            printf("Código: %d\n", usuario[i].codigo);
            printf("Nome: %s\n", usuario[i].nome);
            printf("Telefone: %d\n", usuario[i].telefone);

            enc = 1;
            break;
        }
    }

    if (enc == 0)
    {
        printf("Nome de usuário não encontrado!\n\n");
    }
}