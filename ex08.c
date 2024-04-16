#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void Embaralhar(int c, int f, int matriz[c][f])
{
    for(int i = 0; i < c; i++){
        for(int j = 0; j < f; j++){
            matriz[i][j] = rand() % 100;
        }
    }
}

void OrdemCrescente(int c, int f, int matriz[c][f])
{
    int a;
    for(int i = 0; i < c; i++){
        for(int j = 0; j < f; j++){
            for(int x = 0; x < f; x++){
                if(matriz[i][x] > matriz[i][j]){
                    a = matriz[i][x];
                    matriz[i][x] = matriz[i][j];
                    matriz[i][j] = a;
                }
            }
        }
    }
}

int main()
{
    int c, f;
    printf("Digite numero de colunas: ");
    scanf("%d", &c);
    printf("Digite numero de fileiras: ");
    scanf("%d", &f);
    int matriz[c][f];
    Embaralhar(c, f, matriz);
    OrdemCrescente(c, f, matriz);
    for(int i = 0; i < c; i++){
        for(int j = 0; j < f; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}