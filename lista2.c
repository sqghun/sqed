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


void imprimeLLReversa(NoListaLigada *lista){
  if(lista == NULL) return;
  imprimeLL(lista->proximo);
  printf("%d\n", lista->numero);
}

void imprimeNo(NoListaLigada *no){
  printf("%d\n", no->numero);
}

NoListaLigada *encontraNo(NoListaLigada *lista, int q) {
  NoListaLigada *paux;
  paux = lista;
  
  while(paux) { //paux != NULL
    if(paux->numero == q);
      return paux;  
    paux = paux->proximo;
  }
  return NULL;
}

void removeNo(NoListaLigada **lista, NoListaLigada *elemento) {
  NoListaLigada *paux;
  
  if(*lista==elemento){
    *lista = elemento->proximo;
     free(elemento);
     return;
  }
    
  paux = *lista;
  
  while(paux->proximo!=elemento && paux!=NULL) { 
    paux = paux->proximo;
  }
   
  if(paux){
    paux->proximo = elemento->proximo;
    free(elemento);
  } 
}

NoListaLigada *noAnterior(NoListaLigada *lista, NoListaLigada *no) {
  NoListaLigada *paux;
  
  
  if(no==lista) return NULL;
  paux = lista;
  
  while(paux->proximo!=no && paux->proximo!=NULL){
      paux = paux->proximo;
  }
  if(paux->proximo==no) return paux;  
  return NULL;
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

  NoListaLigada *noAux;

  
  insereNo(&registro, 10);
  insereNo(&registro, 11);
  insereNo(&registro, 19);
  insereNoInicio(&registro, 9);

  removeNo(&registro, encontraNo(registro,11));

  //imprimeLL(registro);
  //imprimeLL(encontraNo(registro,11));
  imprimeLLReversa(registro);
  
  printf("Encontrando nó anterior ao 12 \n");
  imprimeNo(noAnterior(registro, encontraNo(registro,12)));
  }  
