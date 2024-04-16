#include <stdio.h>

/*
Estrutura de uma funçao-

tipo_da_funcao NomeDaFuncao (Lista_de_Parametros)
{
 corpo da fuçao
 return...
}
*/

/*
void Ola()
{
    printf("Ola \n");
}

void main()
{
    Ola(); 
    Ola();
    Ola();
}
*/

int main(){
    int num;
    printf("Digite um numero: ");
    scanf("%d", &num);
    printf("numero digitado: %d", num);
    return 0;
}