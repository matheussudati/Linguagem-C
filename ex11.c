#include <stdio.h>

typedef struct{
    int x1, y1;
    int x2, y2;
}Retangulo;

int main() {
    Retangulo ret;
    int area, difx, dify, p;
    printf("X1: "); 
    scanf("%d", &ret.x1);
    printf("Y1: "); 
    scanf("%d", &ret.y1);
    printf("X2: "); 
    scanf("%d", &ret.x2);
    printf("Y2: "); 
    scanf("%d", &ret.y2);
    difx = ret.x2 - ret.x1;
    dify = ret.y2 - ret.y1;
    area = difx * dify;
    p = (difx * 2 + dify * 2) * 3;
    printf("\nArea: %d", area);
    printf("\nPerimetro: %d", p);
    return 0;
}