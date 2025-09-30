// demo de manipulação de arquivos

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLIN 900 

//int tamanhoString(char *s){
//   int conta=0;
//   while(*s!=\0){
//     conta++;
//     s++
//   }
//   return conta;
//}

int main() {
  FILE *arq;
  char linha[MAXLIN];
  int contalinhas=0;
  long int tamanhoMaximo=0;
  long int posicao=0;
  long int posicaoMax=0;
  
  arq = fopen("/home/pub/ed/Cadastro.csv","r"); 
 
  if(!arq){
     printf("Erro de abertura de arquivo.\n");
     exit(-1);
  }   

  fgets(linha, MAXLIN, arq);
  while(!feof(arq)){  
    posicao = ftell(arq); 
    fgets(linha, MAXLIN, arq);
    contalinhas++;
    if(strlen(linha)>tamanhoMaximo){
      tamanhoMaximo = strlen(linha);
      posicaoMax = posicao;
    }  
    //printf("%s", linha); 
  }

  fseek(arq, posicaoMax, SEEK_SET);
  fgets(linha, MAXLIN, arq);
  printf("\n%s\n", linha); 
  
  printf("O arquivo tem %d linhas\n", contalinhas); 
  printf("O tamanho máximo de linha é %ld\n", tamanhoMaximo); 
  printf("O nro da linha é %ld\n", posicaoMax); 
  
}
