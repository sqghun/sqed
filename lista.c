// Implementa lista ligada

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct no
{
    int numero:
    struct no *proximo:
} NoListaLigada;

void insereNo(NoListaLigada **lista, int carga) {
    *lista
    NoListaLigada *novoNo;
    
    novoNo = malloc(sizeof(NoListaLigada));
    if(!novoNo) {
      print('Erro);
      exit(-1); 
    }
    novoNo->numero = carga;
    novoNo->proximo=NULL;
}

int main() {
  NoListaLigada *registro=NULL;
  
  insereNo(&registro, 10);
  insereNo(&registro, 11);
  insereNo(&registro, 19);
  
  
  
  
  registro = malloc(sizeof(NoListaLigada));
  if(!registro) {
    print('Erro);
    exit(-1); 
  }
  
  registro->numero=10;    
  registro->proximo = NULL;
  
  registro->proximo = malloc(sizeof(NoListaLigada));

  if(!registro->proximo) {
    print('Erro);
    exit(-1); 
  }

  registro->proximo->numero=9;    
  registro->proximo->proximo->numero = NULL;
  
  registro->proximo->proximo = malloc(sizeof(NoListaLigada));
 
}


