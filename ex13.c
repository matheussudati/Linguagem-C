#include <stdio.h>
#include <string.h>
#define MAX 5

typedef struct{
    int sexo;
    float altura;
}Pessoa;

void maiorMenor(Pessoa pes[],float *menor, float *maior){
    *maior = pes[0].altura;
    *menor = pes[0].altura;
    for(int i = 0; i < MAX; i++){
        if(*maior < pes[i].altura){
            *maior = pes[i].altura;
        }
        if(*menor > pes[i].altura){
            *menor = pes[i].altura;
        }
    }
}

void media(Pessoa pes[], float *mediaM){
    float mas;
    float total;
    for(int i = 0; i < MAX; i++){
        if(pes[i].sexo == 1){
            mas++;
            total = total + pes[i].altura;
        }
    }
    *mediaM = total/mas;
}

void mulher(Pessoa pes[], int *mulheres){
    for(int i = 0; i < MAX; i++){
        if(pes[i].sexo == 2){
            (*mulheres)++;
        }
    }
}

int main(){
    Pessoa pes[MAX];
    float maior, menor, mediaM;
    int mulheres = 0;
    for(int i = 0; i < MAX; i++){
        printf("(1-Masculino) (2-Feminino): ");
        scanf("%d", &pes[i].sexo);
        printf("Altura: ");
        scanf("%f", &pes[i].altura);
    }
    maiorMenor(pes, &menor, &maior);
    media(pes, &mediaM);
    mulher(pes, &mulheres);
    printf("\nMaior: %.2f, Menor: %.2f", maior, menor);
    printf("\nMedia da altura: %.2f", mediaM);
    printf("\nQuantida de mulheres: %d", mulheres);
    return 0;
}