// Estatística descritiva
// Programa para calcular a média, mediana, desvio padrão, valor mínimo e máximo
// de uma série de números informados pelo user

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int num, i , j, pontomedio;
    float *vetor;
    float soma=0, variancia=0;
    float min, max, sd, mediana, media;
    float ant;
    float resto, div; 

    printf("Numeros na serie:");     
    scanf("%d", &num);
    
    vetor = malloc(num * sizeof(float));
    if(!vetor){ //alocação não foi bem sucedida => pd == NULL
       printf("Erro de alocação dinamica de memória!\n");
       exit(-1);
    }

    min=0;
    max=0;
    printf("Entre com os numeros:\n");     
    for(int i=0; i<num; i++) {
       printf("Numero %d: ", (i+1));     
       scanf("%f", &vetor[i]);
       soma+=vetor[i];
       if(vetor[i]<min || i==0){
         min=vetor[i];  
       }
       if(vetor[i]>max){
         max=vetor[i];  
       }
       //printf("Vet: %f\n", vetor[i]); 
       //printf("Min: %f\n", min); 
       //printf("Max: %f\n", max); 
       //printf("i: %f\n", i); 
    }    
    // Cálculo da média  
    media = soma/num;

    // Cálculo do desvio padrão
    soma = 0;
    for(int i=0; i<num; i++) {
      soma += (vetor[i]-media) * (vetor[i]-media);
    }
    variancia = soma/num;
    sd = sqrt(variancia);

    // Cálculo da mediana
    for(int j=0; j<num; j++){
      for(int i=0; i<num; i++) {
        ant=vetor[i];
        if(ant > vetor[i+1] & (i+1) < num){
           vetor[i] = vetor[i+1];
           vetor[i+1] = ant; 
        }
      }  
    }
    pontomedio = num / 2;
    resto = num % 2;
    if(resto==0){
      mediana = (vetor[pontomedio-1] + vetor[pontomedio]) / 2;
    }else {
      mediana = vetor[pontomedio];
    }

    printf("\nDesvio Padrao: %.5f\n", sd);      
    printf("Media: %.3f\n", media); 
    printf("Mediana: %.3f\n", mediana); 
    printf("Valor Minimo: %.2f\n", min); 
    printf("Valor Maximo: %.2f\n", max); 

    free(vetor);
}

