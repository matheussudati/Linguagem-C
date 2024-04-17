#include <stdio.h>
#include <conio.h>
#define MAX 100

void testeMedalha(int medalha[], int arrayEmpate[], int *empate, int *marcador, int *maior, int numP);

void testeEmpate(int medalha[], int numP, int *p, char classificacaoPaises[numP][3], char paises[numP][3], int medalhaPrata[], int medalhaBronze[], int *maior, int *marcador, int *i, int *z, int *x);

void trocaMedalha(int *empate, int *marcador, int *maior, int numP, int arrayEmpateOuro[numP], int medalha[numP], int arrayEmpate[numP], int *x);

int main(){

    int numP = MAX, medalhaOuro[numP], medalhaPrata[numP], medalhaBronze[numP], maior = 0, empate = 0, arrayEmpateOuro[numP], x = 0, z = 0, arrayEmpatePrata[numP], arrayEmpateBronze[numP], marcador = 0, p = 0;
    char paises[numP][3], classificacaoPaises[numP][3];

    for(int i = 0; i < numP; i++){
        printf("Digite as 3 iniciais do %d pais: ", i+1);
        fflush(stdin);
        gets(paises[i]);
        printf("Quantas medalhas de Ouro? ");
        scanf("%d", &medalhaOuro[i]);
        printf("Quantas medalhas de Prata? ");
        scanf("%d", &medalhaPrata[i]);
        printf("Quantas medalhas de Bronze? ");
        scanf("%d", &medalhaBronze[i]);
        
    }

    int i = 0; 
    maior = 0;

    do{
        testeMedalha(medalhaOuro, arrayEmpateOuro, &empate, &marcador, &maior, numP);

        if(marcador == 0){
            testeEmpate(medalhaOuro, numP, &p, classificacaoPaises, paises, medalhaPrata, medalhaBronze, &maior, &marcador, &i, &z, &x);
            continue;
        }
        maior = 0;

    	trocaMedalha(&empate, &marcador, &maior, numP, arrayEmpateOuro, medalhaPrata, arrayEmpatePrata, &x);
        if(marcador == 0){
            testeEmpate(medalhaPrata, numP, &p, classificacaoPaises, paises, medalhaOuro, medalhaBronze, &maior, &marcador, &i, &z, &x);
            maior = 0;
            continue;
        }

        trocaMedalha(&empate, &marcador, &maior, numP, arrayEmpatePrata, medalhaBronze, arrayEmpateBronze, &x);
        if(marcador == 0){
            testeEmpate(medalhaBronze, numP, &p, classificacaoPaises, paises, medalhaPrata, medalhaOuro, &maior, &marcador, &i, &z, &x);
            maior = 0;
            continue;
        }

        i++;
    } while(i < numP);

    for(int i = 0; i < numP; i++){
        printf("\n%d Lugar: ", i+1);
        for(int j = 0; j < 3; j++){
            printf("%c", classificacaoPaises[i][j]);
        }
    }

    return 0;
}

void testeMedalha(int medalha[], int arrayEmpate[], int *empate, int *marcador, int *maior, int numP){
    for(int j = 0; j < numP; j++){      
        if(*maior == medalha[j] && j > 0){
            arrayEmpate[j] = 1;
            *empate = *empate + 1;
            *marcador = *marcador + 1;
        } 
        if(medalha[0] == *maior && *empate > 0){
            arrayEmpate[0] = 1;
        }
        if(*maior < medalha[j]){
            *maior = medalha[j];
            *empate = 0;
            *marcador = 0;
        }
    }
}

void testeEmpate(int medalha[], int numP, int *p, char classificacaoPaises[numP][3], char paises[numP][3], int medalhaPrata[], int medalhaBronze[], int *maior, int *marcador, int *i, int *z, int *x){
            for(int i = 0; i < numP; i++){
                if(*maior == medalha[i]){
                    for(int x = 0; x < 3; x++){
                        classificacaoPaises[*p][x] = paises[i][x];
                    }
                    medalha[i] = -1-i;
                    medalhaPrata[i] = -1-i;
                    medalhaBronze[i] = -1-i;
                    *p = *p + 1;
                }
            }
            *maior = 0;
            *marcador = 0;
            *i = *i + 1;
            *z = 0;
            *x = 0;
        }

void trocaMedalha(int *empate, int *marcador, int *maior, int numP, int arrayEmpateOuro[numP], int medalha[numP], int arrayEmpate[numP], int *x){
    if(*empate > 0){
        int z = 0;
        *empate = 0;
        *marcador = 0;
        for(int j = 0; j < numP; j++){
            if(arrayEmpateOuro[j] == 1){ 
                if(x == 0){
                    *maior = medalha[j];
                    z = j;
                }
                if(*maior == medalha[j] && j > z){
                    arrayEmpate[j] = 1;
                    *empate = *empate + 1;
                    *marcador = * marcador + 1;
                }
                if(medalha[0] == *maior && *empate > 0){
                    arrayEmpate[0] = 1;
                }
                if(*maior < medalha[j]){
                    *maior = medalha[j];
                }
                *x = *x + 1;
            } 
        }
    }
}