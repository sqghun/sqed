// demo de manipulação de arquivos e colunas csv cadastro

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXLIN 900 

typedef struct
{
  char ids[20];    // 1
  char nome[100];  // 2 
  char cargo[100]; // 5
  char org[100];   // 17
  char uorg[100];  // 19   
} Registro;


char extrai(char *ptr, char *str){
  while(*ptr!='"'){
    *str = *ptr;
    ptr++;
    str++;  
  }
  *str = '\0';
  ptr++;
  return ptr;
}


Registro coleta(char *lin){
  Registro r;
  char *p, *q;
  int cpon=0;
  
  p = lin;
  
  while(*p!='\0'){
    if(*p=='"'){
      cpon++;
      p++;
      switch(cpon){
      case 1:
         p = extrai(p, r.ids);  
         break;
      case 2:
         p = extrai(p, r.nome);  
         break;
      case 5:
         p = extrai(p, r.cargo);  
         break;
      case 17:
         p = extrai(p, r.org);  
         break;
      case 19:
         p = extrai(p, r.uorg);  
         return r; 
         break;
      default:
         while(*p!='"') p++;
         p++   
      }  
    }
    p++; 
  } 
  return r;
}

void imprimeReg(Registro r){
    printf("ID: \t%s\nNome:\t%s\nCargo:\t%s\nOrg:\t%s\nUorg:\t%s\n\n");
}


int main() {
  FILE *arq; 
  Registro reg;
  char linha[MAXLIN]; 
     
  arq = fopen("/home/pub/ed/Cadastro.csv","r"); 
 
  if(!arq){
     printf("Erro de abertura de arquivo.\n");
     exit(-1);
  }   

  printf("\nEntre com parte do nome do servidor: ");
  fgets(query, 100, stdin);
  
  while(!feof(arq)) {
    fgets(linha, MAXLIN, arq);
    reg = coleta(linha);
    if(strstr(reg.nome , query)) { 
       imprimeReg((reg); 
    }     
  }  

  fgets(linha, MAXLIN, arq);
  reg = coleta(linha); 
  printf("%s", reg); 


  //while(!feof(arq)){  
  //  posicao = ftell(arq); 
   // fgets(linha, MAXLIN, arq);
  //  contalinhas++;
  //  if(strlen(linha)>tamanhoMaximo){
  //    tamanhoMaximo = strlen(linha);
  //    posicaoMax = posicao;
  //  }  
    //printf("%s", linha); 
}
