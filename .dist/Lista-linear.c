#include <stdio.h>
#define N 5

struct TipoNodo
{
    int codigo;
    char nome[10];
    float altura;
};
typedef struct TipoNodo TipoNodo;

int menu();
int inserirInicio(TipoNodo LL[], int IA, int FA, int *IL, int *FL, TipoNodo InfoNodo);
int mostrarLL(TipoNodo LL[], int IA, int FA, int IL, int FL);

int main()
{
    TipoNodo LL[N], infoNodo;
    short opcao;
    int IA = 0, FA = N - 1, IL = -1, FL = -1;

    do
    {
        opcao = menu();
        switch (opcao)
        {
        case 1:
            printf("\n\nInserir no inicio\n\n");
            printf("Codigo....: ");
            scanf("%d", &infoNodo.codigo);
            printf("Nome......: ");
            scanf("%s", infoNodo.nome);
            printf("Altura....: ");
            scanf("%f", &infoNodo.altura);
            if (inserirInicio(LL, IA, FA, &IL, &FL, infoNodo))
                printf("\n>>>>>>Lista cheia!!!<<<<<<<\n\n");
            else
                printf("\n\n>>>>>>Inserido com sucesso!!!\n\n");
            break;
        case 2:
            printf("\n\nMostrar a lista\n\n");
            mostrarLL(LL, IA, FA, IL, FL);
            break;
        case 0:
            printf("\n\nJa vai tarde!!!\n\n");
            break;
        default:
            printf("\n\nErrroouuu!!!\n\n");
        }
    } while (opcao != 0);
}

int menu()
{
    short opcao;
    printf("%%%%%%%%  M E N U %%%%%%%%%%\n");
    printf("[1] Inserir no inicio\n");
    printf("[2] Mostrar\n");
    printf("[0] Sair\n");
    printf("%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n");
    printf("Escolha uma opcao: ");
    scanf("%hd", &opcao);
    return opcao;
}

int inserirInicio(TipoNodo LL[], int IA, int FA, int *IL, int *FL, TipoNodo infoNodo)
{
    if (IA == *IL && FA == *FL)
        return 1;
    else
    {
        if (*IL == -1)
            *IL = *FL = IA;
        else if (*IL > IA)
            *IL = *IL - 1;
        else
        {
            for (int i = *FL; i >= *IL; i--)
                LL[i + 1] = LL[i];
            *FL = *FL + 1;
        }
        LL[*IL] = infoNodo;
        return 0;
    }
}

int mostrarLL(TipoNodo LL[], int IA, int FA, int IL, int FL)
{
    for (int i = IA; i <= FA; i++)
    {
        if (i >= IL && i <= FL)
            printf("%3d - %5.2f - %s\n", LL[i].codigo, LL[i].altura, LL[i].nome);
        else
            printf("----------\n");
    }
    printf("\n\n");
    return 0;
}