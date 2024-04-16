#include <stdio.h>
// 1 tipo de struct

void main() {
    struct registro {
    int idade;
    double salario;
    };

    struct registro x, y;
    x.idade = 50;
    x.salario = 10000.0;
    y.idade = 20;
    y.salario = 5000.0;

    return 0;
}