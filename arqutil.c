// Lendo dados de arquivo CSV Cadastro

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "arqutil.h"

#define MAXLIN 900

//typedef struct 
//{
//    char ids[20];      // CPO 1
//    char nome[100];    // CPO 2
//    char cargo[60];    // CPO 5
//    char org[100];     // CPO 17
//    char uorg[100];    // CPO 19
//} Registro;

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
}        
 

int encontraRegs(Registro *listaRegs, char *q, int tipo, Registro **regvet){
   FILE *arq; 
   Registro reg;
   char linha[MAXLIN];     
   int conta = 0;
   Registro *pregs;
   int alocado=0;
   int passo=1000;
   //*regvet = NULL;
   
   alocado += passo;
   pregs = malloc(alocado*sizeof(Registro));
   
   arq = fopen("/home/pub/ed/Cadastro.csv","r"); 
 
   if(!arq){
      printf("Erro de abertura de arquivo.\n");
      exit(-1);
   }   
  
   while(!feof(arq)) {
     fgets(linha, MAXLIN, arq);
     reg = coleta(linha);
     if( (tipo == ORG && strstr(reg.org,q)) ||
         (tipo == UORG && strstr(reg.uorg,q)) ||
         (tipo == NOME && strstr(reg.nome,q)) ||
         (tipo == CARGO && strstr(reg.cargo,q))) {
           conta++;
           if(conta>alocado) {
             alocado += passo;
             pregs = realloc(pregs, alocado * sizeof(Registro)); 
           }
           //*regvet = realloc(*regvet, conta * sizeof(Registro));
           memcpy(pregs+conta-1, &reg, sizeof(Registro));
           //imprimeReg(reg);
     }
  }   
  *regvet = pregs;
  return conta;
}

int encontraRegsEstruturado(char *q, int tipo, Registro **regvet){
   FILE *arq; 
   Registro reg;
   char linha[MAXLIN];     
   int conta = 0;
   Registro *pregs;
   int alocado=0;
   int passo=1000;
   //*regvet = NULL;
   
   alocado += passo;
   pregs = malloc(alocado*sizeof(Registro));
   
   arq = fopen("/home/pub/ed/CadEstruturado.db","r"); 
 
   if(!arq){
      printf("Erro de abertura de arquivo.\n");
      exit(-1);
   }   
  
   while(!feof(arq)) {
     fread(&reg, sizeof(Registro), 1, arq);
     if( (tipo == ORG && strstr(reg.org,q)) ||
         (tipo == UORG && strstr(reg.uorg,q)) ||
         (tipo == NOME && strstr(reg.nome,q)) ||
         (tipo == CARGO && strstr(reg.cargo,q))) {
           conta++;
           if(conta>alocado) {
             alocado += passo;
             pregs = realloc(pregs, alocado * sizeof(Registro)); 
           }
           //*regvet = realloc(*regvet, conta * sizeof(Registro));
           memcpy(pregs+conta-1, &reg, sizeof(Registro));
           //imprimeReg(reg);
     }
  }   
  *regvet = pregs;
  return conta;
}

int encontraRegsIndiceOrg(char *q, int tipo, Registro **regvet){
   FILE *arq, *arqindice;; 
   Registro reg;
   RegIndOrg regind;

   char linha[MAXLIN];     
   int conta = 0;
   Registro *pregs = NULL;
   int alocado=0;
   int passo=1000;
   
   alocado += passo;
   pregs = malloc(alocado*sizeof(Registro));
   
   arqindice = fopen("/tmp/indiceOrg.db","r"); 
   arqindice = fopen("/home/pub/ed/CadEstruturado.db","r"); 
 
   if(!arq || !arqindice){
      printf("Erro de abertura de arquivo.\n");
      exit(-1);
   }   
  
   while(!feof(arqindice)) {
     fread(&reg, sizeof(RegindOrg), 1, arqindice);
     if(strstr(regind.org,q)) {
       fseek(arqindice, regind.indice*sizeof(Registro), SEEK_SET); 
       fread(&reg, sizeof(Registro),1, arq);  
       conta++;
       if(conta>alocado) {
          alocado += passo;
          pregs = realloc(pregs, alocado * sizeof(Registro)); 
       }
        memcpy(pregs+conta-1, &reg, sizeof(Registro));
     }
  }   
  *regvet = pregs;
  return conta;
}




