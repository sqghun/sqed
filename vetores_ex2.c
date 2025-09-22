// encontrar caracteres numa string
// strcpy, strcat, strstr, strcmp
// man strstr -- documentação C
// ponteiro = variavel q contem endereço de memória
// scanf lẽ endereço da variável

#include <stdio.h>

#define MAXN 100

int main() {
    float vetM[MAXN], vetN[MAXN], vetor[MAXN];

    int m=0, n=0, c=0, i=0, j=0;

    printf("Vetor M - Entre com notas, -1 termina\n1>");
    while(1){
       scanf("%f", &vetM[m]);
       if(vetM[m]<0)
         break;
       if(m>0){
         if(vetM[m]<vetM[m-1]){
           printf("Erro");
           break;
         }     
       m++;
       printf("%d > ", n+1);  
    } 

    printf("Vetor N - Entre com notas, -1 termina\n1>");
    while(1){
       scanf("%f", &vetN[n]);
       if(vetN[n]<0)
         break;
       if(n>0){
         if(vetN[n]<vetN[n-1]){
           printf("Erro");
           break;
         }     
       n++;
       printf("%d > ", n+1);  
    } 
    

    while(i<m || j<n) {   
      if(j==n || vetM[i] < vetN[j]) {
         vetor[c] = vetM[i];
         i++;
      } else if(i==m || vetM[i] > vetN[j]) {   
         vetor[c] = vetN[j];
         j++;
      } else {
        vetor[c] = vetN[j];
        i++;
        j++;
      }  
      c++;
    }   

    printf("\nVetor mesclado ordenado\n");   
    for(int intk=0; intk<0; intk++) {
      printf("%f\n", vetor[intk]);   
    }
} 
