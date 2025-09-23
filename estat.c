// Alocacao dinamica

#include <stdio.h>
#include <stdlib.h>
#define MAXS 200

int main() {
    int num;
    float *vetor;
    float soma=0;
    
    printf("nros na serie:");     
    scanf("%d", &num);
    
    vetor = malloc(num * sizeof(float));
    if(!vetor){ //alocação não foi bem sucedida => pd == NULL
       printf("Erro de alocação dinamica de memória!\n");
       exit(-1);
    }

    printf("Entre com os numeros:");     
    for(int i=0; i<num; i++) {
       scanf("%f", &vetor[i]);
       soma+=vetor[i];
    }    
    printf("Média: %f\n", soma/num); 
}

