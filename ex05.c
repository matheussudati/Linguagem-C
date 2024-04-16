#include <stdio.h>

int meio(){
    int central = 0;
    central = 1;
    return central;
}

int main() {
    int central, matriz[3][3] = {{1, 2, 3}, {4, 5 ,6}, {7, 8, 9}};
    central = meio();
    printf("Numero central da matriz: %d", matriz[central][central]);
    return 0;
}