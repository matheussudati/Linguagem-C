#include <stdio.h>
#define MAX 100

// struct com array

int main() {
    typedef struct{
    int idade;
    double salario;
    } registro;
    int i = 0, idade, salario, maior = 0, menor = 0;
    registro v[MAX];

    do{
        printf("\nDigite a idade do %d funcionario: ", i+1);
        scanf("%d", &idade);
        if(idade > 15){
            v[i].idade = idade;
        } else{
            continue;
        }
        printf("\nDigite o salario do %d funcionario: ", i+1);
        scanf("%d", &salario);
        if(i == 0){
            maior = salario;
            menor = salario;
        }
        if(maior < salario){
            maior = salario;
        }
        if(menor > salario){
            menor = salario;
        }
        v[i].salario = salario;
        i++;
    } while (i < 5);

    for(int i = 0; i < 5; i++){
        printf("\nIdade do %d funcionario: %d", i+1, v[i].idade);
        printf("\nSalario do %d funcionario: %.2lf", i+1, v[i].salario);
    }
    printf("\nSalario Maior: %.d", maior);
    printf("\nSalario Menor: %.d", menor); 
    return 0;
}