#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 4

int preencherVetor(int vet[]);
int mostrarVetor(int vet[]);
int somaTotalVetor(int vet[]);
int maiorMenorVetor(int vet[], int *maior, int *menor);
int parVetor(int vet[]);
//int imparVetor(int vet[]);

int main(){
    int vet[N], maior, menor;
    preencherVetor(vet);
    mostrarVetor(vet);
    printf("\n");
    printf("Total........%d\n", somaTotalVetor(vet));
    maiorMenorVetor(vet, &maior, &menor);
    printf("Maior........%d\n", maior);
    printf("Menor........%d\n", menor);
    parVetor(vet);
    //imparVetor(vet);
}

int preencherVetor(int vet[]){
    int i;
    srand(time(NULL));

    for(i = 0; i < N; i++){
        vet[i] = rand() % 10;
    }
}

int mostrarVetor(int vet[]){
    int i;

    for(i = 0; i < N; i++){
        printf("vet[%d] = %d\n", i, vet[i]);
    }
}

int somaTotalVetor(int vet[]){
    int i, total = 0;

    for(i = 0; i < N; i++){
        total += vet[i];
    }

    return total;
}

int maiorMenorVetor(int vet[], int *maior, int *menor){
    int i;

    for(i = 0; i < N; i++){
        if(i == 0){
            *maior = vet[i];
            *menor = vet[i];
        }
        if(vet[i] > *maior){
            *maior = vet[i];
        }
        else if(vet[i] < *menor){
            *menor = vet[i];
        }
    }
}

int parVetor(int vet[]){
    int i;
    for(i = 0; i < N; i++){
        if(vet[i] % 2 == 0){
            printf("Par[%d] = %d\n", i, vet[i]);
        }
    }
}
/*
int imparVetor(int vet[]){
    int i;
    for(i = 0; i < N; i++){
        if(vet[i] % 2 == 0){
            printf("Impar[%d] = %d\n", i, vet[i]);
        }
    }
}
*/