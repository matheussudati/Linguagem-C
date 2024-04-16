#include <stdio.h>
#include <stdlib.h>

int numeroRecebe(int a, int b){
    if(a > b){
        return(a);
    }
    return(b);
}

int numeroDivisao(int a, int b){
    int divisao = 0;
    if(a == 0 || b ==0){
        divisao = 0;
        return(divisao);
    }
    divisao = a/b;
    return(divisao);
}

void numeroTabuada(int a){
    printf("\n\nTabuada do %d:", a);
    for(int i = 1; i < 11; i++){
        printf("\n%d x %d: %d", a, i, i*a);
    }
}  

int numeroProcurar(int c){
    int vetor[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1}, indice;
    for(int i = 0; i < 10; i++){
        if(vetor[i] == c){
            indice = i;
            return(indice);   
        }
    }
    indice = -1;
    return(indice);
}

int numeroRepetido(int d){
    int matriz[10][10], repetido = 0;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            matriz[i][j] = rand() % 10;
            if(matriz[i][j] == d)
                repetido++;
        }
    }
    return(repetido);
}

int main(){
    int a, b, maior, divisao, indice, c, d, repetido;
    printf("Digite o primeiro numero: ");
    scanf("%d", &a);
    printf("Digite o segundo numero: ");
    scanf("%d", &b);
    printf("\nProcure um numero: ");
    scanf("%d", &c);
    printf("\nVeja quantas vezes o nuemro de 0 a 10 aparece na matriz: ");
    scanf("%d", &d);
    maior = numeroRecebe(a, b);
    divisao = numeroDivisao(a, b);
    printf("\nMaior: %d", maior);
    printf("\nDivisao: %d", divisao);
    numeroTabuada(a);
    indice = numeroProcurar(c);
    if(indice == -1){
        printf("\nNumero nao esta no vetor.");
    } else{
        printf("\nNumero numero esta na posicao: %d", indice);
    }
    repetido = numeroRepetido(d);
    printf("\nNumero aparece: %d vezes", repetido);
    return 0;
}