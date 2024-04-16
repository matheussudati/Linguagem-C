#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void aleatorio(int matriz[4][4])
{
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            matriz[i][j] = rand() % 100;
        }
    }
}

void passagem(int matriz[4][4], int array[16])
{
    int p = 0;
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            array[p] = matriz[i][j];
            p++;
        }
    }
}

void imprimir(int matriz[4][4], int array[16])
{
    int p = 0;
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\nArray:\n");
    for(int j = 0; j < 16; j++)
        {
            printf("%d ", array[p]);
            p++;
        }
}

int main(){
    int matriz[4][4], array[16];
    aleatorio(matriz);
    passagem(matriz, array);
    imprimir(matriz, array);
    return 0;
}