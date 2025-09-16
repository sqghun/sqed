// encontrar caracteres numa string
// strcpy, strcat, strstr, strcmp
// man strstr -- documentação C
// ponteiro = variavel q contem endereço de memória
// scanf lẽ endereço da variável

#include <stdio.h>

#define MAXN 100

int main() {
    float notas[MAXN];

    int conta=0;

    float valor;
    float soma=0;
    float media=0;
    float dp;

    printf("Entre com notas, -1 termina\n1> ");
    while(1){
       scanf("%f", &notas[conta]);
       if(notas[conta]<0)
         break;
       conta++;
       printf("%d > ", conta+1);  
    } 
      
    
    for(int i=conta-1; i>=0; i--) {
      printf("%.2f", notas[i]);   
 //     soma += notas[j];
    }
} 
