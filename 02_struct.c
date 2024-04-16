#include <stdio.h>
// 2 tipo de struct

void main() {
    typedef struct{
    int idade;
    double salario;
    } registro;

    registro x, y;
    x.idade = 50;
    x.salario = 10000.0;
    y.idade = 20;
    y.salario = 5000.0;

    return 0;
}