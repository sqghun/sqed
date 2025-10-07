// Lê arquivo csv e monta lsita de registros de ORG especificadas
// Silvia Q
// 07/10/2025

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "arqutil.h"

int main() {
   FILE *arq, *arqsai; 
   Registro reg;
   char linha[MAXLIN];     
   int conta = 0;
   Registro *pregs;
   int alocado=0;
   int passo=1000;


   arq = fopen("/home/pub/ed/Cadastro.csv","r"); 
   arqsai = fopen("/tmp/CadastroEstruturado.db","w"); 
 
   if(!arq || !arqsai){
      printf("Erro de abertura de arquivo.\n");
      exit(-1);
   }   
  
   while(!feof(arq)) {
     fgets(linha, MAXLIN, arq);
     reg = coleta(linha);
     fwrite(&reg, sizeof(Registro),1, arqsai);
   }
}   

