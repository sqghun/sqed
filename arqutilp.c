// Lendo dados de arquivo CSV Cadastro

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "arqutil.h"

#define MAXLIN 900

typedef struct 
{
    char ids[20];      // CPO 1
    char nome[100];    // CPO 2
    char cargo[60];    // CPO 5
    char org[100];     // CPO 17
    char uorg[100];    // CPO 19
} Registro;

char *extrai(char *ptr, char *str){
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
        if( *p=='"' ){ //achou um campo
            cpon++;
            p++;
            switch(cpon){
                case 1:
                    p = extrai(p,r.ids);
                    break;
                case 2:
                    p = extrai(p,r.nome);
                    break;
                case 5:
                    p = extrai(p,r.cargo);
                    break;
                case 17:
                    p = extrai(p,r.org);
                    break;
                case 19:
                    p = extrai(p,r.uorg);
                    p++;
                    return r;
                    break;
                default:
                    while(*p!='"') p++;
                    p++;
                    break;
            }
        }
        p++;
    }
    return r;
}

void limpa(char *p){
    while(*p!='\n' && *p!='\0') {
        *p = toupper(*p);
        p++;
    }
    *p = '\0';
}

void imprimeReg(Registro r){
    printf("ID: \t%s\nNome:\t%s\nCargo:\t%s\nORG:\t%s\nUORG:\t%s\n\n",
        r.ids,r.nome,r.cargo,r.org, r.uorg);
        
 
int encontraRegs(Registro *listaRegs, char *q, int tipo){
   FILE *arq; 
   Registro reg;
   char linha[MAXLIN];     
   int conta = 0;
   
   arq = fopen("/home/pub/ed/Cadastro.csv","r"); 
 
   if(!arq){
      printf("Erro de abertura de arquivo.\n");
      exit(-1);
   }   
  
   while(!feof(arq)) {
     fgets(linha, MAXLIN, arq);
     reg = coleta(linha);
     switch (tipo){
     case ORG:
        if(strstr(reg.org , q)) { 
          imprimeReg((reg); 
        } 
        break;    
     case UORG:
        if(strstr(reg.uorg , q)) { 
          imprimeReg((reg); 
        } 
        break;    
     case NOME:
        if(strstr(reg.nome , q)) { 
          imprimeReg((reg); 
        } 
        break;    
     case CARGO:
        if(strstr(reg.cargo, q)) { 
          imprimeReg((reg); 
        } 
        break;    
     }
  }  
  return conta;
               
}

