#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 3

typedef struct{
char nome[80];
float preco;
} PROD;

void ordenar(PROD pd[])
{
    char aux[80];
    int x;
    float m;
    for(int i = 0; i < MAX; i++){
        for(int j = i+1; j < MAX; j++){
            x = strcmp(pd[i].nome,pd[j].nome);
            if(x > 0){
                strcpy(aux, pd[i].nome);
                strcpy(pd[i].nome, pd[j].nome);
                strcpy(pd[j].nome, aux);
                m = pd[i].preco;
                pd[i].preco = pd[j].preco;
                pd[j].preco = m;
            }
        }
    }
}

void infla(PROD pd[])
{
    for(int i = 0; i < MAX; i++){
        if(pd[i].preco < 100){
            pd[i].preco = pd[i].preco + (pd[i].preco * 0.05);
        }
    }
}

void imprimir(PROD pd[])
{
    for(int i = 0; i < MAX; i++){
        printf("Produto: %s Preco: %.2f\n", pd[i].nome, pd[i].preco);
    }
}

int main()
{
    PROD pd[MAX];
    for(int i = 0; i < MAX; i++){
        fflush(stdin);
        printf("Digite o %d produto: ", i+1);
        fgets(pd[i].nome,80,stdin);
        pd[i].nome[strcspn(pd[i].nome,"\n")] = '\0';
        printf("preco: ");
        scanf("%f", &pd[i].preco);
    }
    ordenar(pd);
    infla(pd);
    imprimir(pd);
    return 0;
}