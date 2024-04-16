#include <stdio.h>

void crescente(int vetor[], int crescente[]){
    int menor, marcador = 0, remove, maior;
    for(int i = 0; i < 8; i++){
        menor = 30;
        maior = 23;
        for(int j =  0; j < 8; j++){
            if(vetor[j] < menor){
                menor = vetor[j];
                marcador = -1;
            }
            if(vetor[j] > maior){
                maior = vetor[j];
            }
            marcador++;
        }
        crescente[i] = menor;
        remove = 7 - marcador;
        vetor[remove] = maior + 1;
    }
}

int main() {
    int vetor[] = {10, 8, 20, 23, 6, 9, 16, 11}, crescenteArray[8];
    crescente(vetor, crescenteArray);
    for(int i = 0; i < 8; i++){
        printf(" %d", crescenteArray[i]);
    }
    return 0;
}