#include <stdio.h>
#include <math.h>
#include <string.h>

int delta(int a, int b, int c){
    float DeltaCalculo;
    DeltaCalculo = pow(b, 2) - 4 * a * c;
    return(DeltaCalculo);
}

float baskara(int a, int b, float DeltaCalculo) {
    float baskaraCalculo;
    char escolha[2];
    printf("Deseja a raiz negativa (N) ou positiva (P)? ");
    scanf("%1s", escolha);
    
    if(strcmp(escolha, "N") == 0) {
        baskaraCalculo = (-b -(sqrt(DeltaCalculo))) / (2 * a); 
    }   
    else if(strcmp(escolha, "P") == 0) {
        baskaraCalculo = (-b + (sqrt(DeltaCalculo)))/ (2 * a); 
    }
    else {
        printf("Escolha inválida!\n");
        baskaraCalculo = 0;
    }
    
    return baskaraCalculo;
}

float temperaturaC(float c) 
{
    float f;
    f = (9*c)/5 + 32;
    return(f);
}

float temperaturaF(float f) 
{
    float c;
    c = 5*(f - 32)/9;
    return(c);
}

int main() {
    int a, b, c;
    float DeltaCalculo, baskaraCalculo, c_temperatura, f_temperatura;
    printf("Qual valor de a: ");
    scanf("%d", &a);
    printf("Qual valor de b: ");
    scanf("%d", &b); 
    printf("Qual valor de c: ");
    scanf("%d", &c);
    printf("Escolha uma temperatura em C para F: ");
    scanf("%f", &c_temperatura);
    DeltaCalculo = delta(a, b, c);
    baskaraCalculo = baskara(a, b, DeltaCalculo);
    f_temperatura = temperaturaC(c_temperatura); 
    printf("Valor de Delta e: %.0f", DeltaCalculo);
    printf("\nValor de Baskara e: %.5f", baskaraCalculo);
    printf("\nTemperatura %.2fC para F e: %.2f", c_temperatura, f_temperatura);
    printf("\nEscolha uma temperatura em C para F: ");
    scanf("%f", &f_temperatura);
    c_temperatura = temperaturaF(f_temperatura);
    printf("\nTemperatura %.2fF para C e: %.2f", f_temperatura, c_temperatura);
    return 0;
}