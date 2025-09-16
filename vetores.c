// encontrar caracteres numa string
// strcpy, strcat, strstr, strcmp
// man strstr -- documentação C
// ponteiro = variavel q contem endereço de memória
// scanf lẽ endereço da variável

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAXN 100

int main() {
    float notas[MAXN];
    int i=0;
    float valor;
    float soma=0;
    float media=0;
    float dp;
    
    printf("Você alocou estaticamente %ld bytes:", sizeof(notas));
    
    printf("Entre com notas, -1 termina\n1> ");
    while(1){
       scanf("%f", &notas[i]);
       if(valor<0)
         break;
       notas[i] = valor;  
       soma += notas[i];
       i++;
       printf("%d > ", i+1);  
    } 
    printf("\n Você entrou com %d valores\n", i);
    for(int j=0; j<i; j++) {
      printf("%.2f", notas[j]);   
 //     soma += notas[j];
    }

    if(i<=0){
      exit(0);
    }
       
    media = soma / i;
    
    for(int j=0; j<i; j++) {
      soma += (notas[j]-media) * (notas[j]-media);
    }
    
    dp = sqrt(soma);
    printf("%.2f Desvio Padrao:", dp);      
} 
