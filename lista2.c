// Implementa lista ligada

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct no
{
    int numero;
    struct no *proximo;
} NoListaLigada;

void insereNo(NoListaLigada **lista, int carga) {
    NoListaLigada *novoNo;
    NoListaLigada *aux;
   
    novoNo = malloc(sizeof(NoListaLigada));
    if(!novoNo) {
      printf("Erro de alocação de memoria\n");
      exit(-1); 
    }
    novoNo->numero = carga;
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

void imprimeLL(NoListaLigada *lista){
  if(lista == NULL) return;
  printf("%d\n", lista->numero);
  imprimeLL(lista->proximo);
}

void insereNoInicio(NoListaLigada **lista, int carga) {
    NoListaLigada *novoNo;
  
    novoNo = malloc(sizeof(NoListaLigada));
    if(!novoNo) {
      printf("Erro de alocação de memoria\n");
      exit(-1); 
    }
    novoNo->numero = carga;
    novoNo->proximo=NULL;
    
    if(*lista==NULL) {
       *lista = novoNo;
    } else {
       novoNo->proximo = *lista;
       *lista = novoNo;    
   }   
}

int main() {
  NoListaLigada *registro=NULL;
  
  insereNo(&registro, 10);
  insereNo(&registro, 11);
  insereNo(&registro, 19);
  insereNoInicio(&registro, 9);

  imprimeLL(registro);
}  
