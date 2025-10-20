// Lê arquivo csv e monta lsita de registros de ORG especificadas
// Silvia Q
// 06/10/2025

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//#include <arqutil.h>
#include <cadlista.h>


void insereNo(ListaReg **lista, Registro reg) {
    NoListaLigada *novoNo;
    NoListaLigada *aux;
   
    novoNo = malloc(sizeof(ListaReg));
    if(!novoNo) {
      printf("Erro de alocação de memoria\n");
      exit(-1); 
    }
    memcpy(&(novoNo->registro), &reg, sizeof(Registro));
    novoNo->proximo=NULL;
    
    if(*lista==NULL) {
       *lista = novoNo;
    } else {
      aux = *lista;
      while(aux->proximo!=NULL){
         aux = aux->proximo;
      }
      aux->proximo=novoNo; 
   }   
}


int encontraListaRegs(char *q, int tipo, ListaReg **listaregs){
   FILE *arq; 
   Registro reg;
   char linha[MAXLIN];     
   int conta = 0;
   //ListaReg *pregs;
   
   //alocado += passo;
   //pregs = malloc(alocado*sizeof(Registro));
   
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
           insereNo(listaregs, reg);
     }
  }   
  //*regvet = pregs;
  return conta;
}

void imprimeReg(Registro r){
    printf("ID: \t%s\nNome:\t%s\nCargo:\t%s\nORG:\t%s\nUORG:\t%s\n\n",
        r.ids,r.nome,r.cargo,r.org, r.uorg);
}        

void imprimeLista(NoListaLigada *lista){
  if(lista == NULL) return;
  imprimeReg(lista->registro);
  imprimeLista(lista->proximo);
}


int main(int argc, char **argv) {
  char query[100];
  int encontrados=0;
     
  ListaReg *listaRegistros=NULL;   

  if(argc<2){ // não passou parâmetros para o programa
     printf("\nEntre com parte da org desejada: ");
     fgets(query, 100, stdin);
     }
  else {
     strcpy(query, argv[1]);
  }          
  limpa(query);

  encontraListaRegs = encontraRegs(query, ORG, &listaRegistros);
  imprimeLista(listaRegistros);
 
}
