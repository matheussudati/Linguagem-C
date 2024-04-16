#include <stdio.h>
#define MAX 100

// struct com array

int main() {
    typedef struct{
    int idade;
    double salario;
    } registro;

    registro v[MAX];
    for(int i = 0; i < 5; i++){
        printf("\nDigite a idade do %d funcionario: ", i+1);
        scanf("%d", &v[i].idade);
        printf("\nDigite o salario do %d funcionario: ", i+1);
        scanf("%lf", &v[i].salario);
    }

    for(int i = 0; i < 5; i++){
        printf("\nIdade do %d funcionario: %d", i+1, v[i].idade);
        printf("\nSalario do %d funcionario: %.2lf", i+1, v[i].salario);
    }
    return 0;
}