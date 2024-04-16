#include <stdio.h>

void crescente(int matriz[5][5]){
    int a;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            for(int x = 0; x < 5; x++){
                if(matriz[i][x] > matriz[i][j]){
                    a = matriz[i][x];
                    matriz[i][x] = matriz[i][j];
                    matriz[i][j] = a;
                }
            }
        }
    }
}

int main() {
    int matriz[5][5] = {{5, 4, 3, 2, 1}, {6, 8, 9, 7, 10}, {14, 13, 15, 11, 12}, {19, 20, 18, 17, 16}, {25, 22, 24, 23, 21}};
    crescente(matriz);
        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 5; j++){
                printf("%d ", matriz[i][j]);
            }
            printf("\n");
        }
    return 0;
}