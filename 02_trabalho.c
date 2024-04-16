#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define MAX 100

typedef struct {
    int id;
    float salario;
    int quantidade_filhos;
    char nome[30];
} Funcionario;

void incluir(Funcionario func[], int *i) 
{
    fflush(stdin);
    printf("nome: ");
    fgets(func[*i].nome,30,stdin);
    printf("salario: ");
    scanf("%f", &func[*i].salario);
    printf("filhos: ");
    scanf("%d", &func[*i].quantidade_filhos);
    func[*i].id = *i;
    (*i)++;
}

void excluir(Funcionario func[], int *i) 
{
    int escolha;
    printf("ID: ");
    scanf("%d", &escolha);
    escolha--;
    for(int j = 0; j < *i; j++){
        strcpy(func[escolha+j].nome,func[escolha+j+1].nome);
        func[(escolha+j)].salario = func[escolha + (j + 1)].salario;
        func[(escolha+j)].quantidade_filhos = func[escolha + (j + 1)].quantidade_filhos;
    }
    (*i)--;
}

void listar(Funcionario func[], int *i)
{
    for(int j = 0; j < *i; j++)
    {
        printf("\n\nID: %d \nNome: %sSalario: %.2f \nFilhos: %d", (func[j].id + 1), func[j].nome, func[j].salario, func[j].quantidade_filhos);
    }
}



void alterar(Funcionario  func[])
{
    int escolha, id;
    printf("ID: ");
    scanf("%d", &id);
    printf("**************************\n");
    printf(" 1 - Nome                 \n");
    printf(" 2 - Filhos               \n");
    printf(" 3 - Salario              \n");
    printf("**************************\n");
    printf("ESCOLHA: ");
    scanf("%d", &escolha);
    id--;
    switch(escolha)
    {
        case 1: fflush(stdin); printf(": "); fgets(func[id].nome,30,stdin); break;
        case 2: scanf("%d", &func[id].quantidade_filhos); break;
        case 3: scanf("%f", &func[id].salario); break;
    }
}

void filhos(Funcionario func[], int *i)
{
    for(int j = 0; j < *i; j++)
    {
        if(func[j].quantidade_filhos > 2)
        {
            printf("\n\nID: %d \nNome: %sSalario: %.2f \nFilhos: %d", (func[j].id + 1), func[j].nome, func[j].salario, func[j].quantidade_filhos);
        }
    }
}

void soma(Funcionario func[], int *i)
{
    float soma = 0;
    for(int j = 0; j < *i; j++)
    {
        soma = soma + func[j].salario;
    }
    printf("\nSOMA TOTAL DOS SALARIO: %.2f", soma);
}

void maior(Funcionario func[], int *i)
{
    float maior = func[0].salario;
    for(int j = 0; j < *i; j++)
    {
        if(maior < func[j].salario)
        {
            maior = func[j].salario;
        }
    }
    printf("\nMAIOR SALARIO: %.2f", maior);
}

void menor(Funcionario func[], int *i)
{
    float menor = func[0].salario;
    for(int j = 0; j < *i; j++)
    {
        if(menor > func[j].salario)
        {
            menor = func[j].salario;
        }
    }
    printf("\nMENOR SALARIO: %.2f", menor);
}

void aumento(Funcionario func[], int *i)
{
    for(int j = 0; j < *i; j++)
    {
        if(func[j].salario < 1000)
        {
            func[j].salario = func[j].salario + (func[j].salario * 0.1);
        }
    }
}

int main() {
    Funcionario func[MAX];
    int i = 0, op = -1;
 
   while (op!=10){
       
           do{
               
            printf("**************************\n");
            printf(" 1 - Cadastrar Registro   \n");
            printf(" 2 - Listar Registros     \n");
            printf(" 3 - Alterar Registro     \n");
            printf(" 4 - Eliminar Registro    \n");
            printf(" 5 - Listar 2 Filhos      \n");
            printf(" 6 - Soma Salarios        \n");
            printf(" 7 - Maior Salario        \n");                
            printf(" 8 - Menor Salario        \n");  
            printf(" 9 - Aumentar Salario 10%%\n");  
            printf("**************************\n");        
            printf("Digite uma opcao: [1-6]: ");
            scanf("%d",&op);    
             
        } while(op < 1 || op > 10);
           
           switch(op){
               
              case 1:  incluir(func, &i);  break;
              case 2:  listar(func, &i);   break;
              case 3:  alterar(func);  break;
              case 4:  excluir(func, &i);  break;
              case 5:  filhos(func, &i);  break;
              case 6:  soma(func, &i);  break;
              case 7:  maior(func, &i);  break;
              case 8:  menor(func,  &i);  break;
              case 9:  aumento(func, &i); break;
        }
        setbuf(stdin,NULL);
        getchar();    
   }
    return 0;
}