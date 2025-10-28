// Implementa uma EAD

#include <stdio.h>
#include <stdlib.h>
#

typedef struct no {
    int numero;
    struct no *proximo;
} NoListaLigada;


void insereNo(NoListaLigada **lista, int carga) {
    NoListaLigada *novoNo;

    novoNo = malloc(sizeof(NoListaLigada));
    if(!novoNo) {
        printf("Erro de alocação de memória.\n");
        exit(-1);   
    }
    novoNo->numero = carga;
    novoNo->proximo=NULL;
    if( *lista==NULL )
        *lista = novoNo;   
    else {
        novoNo->proximo = *lista;
        *lista = novoNo;
    }
}

void imprimeNo(NoListaLigada *no){
    if(!no) 
        printf("Nó Null\n");
    else
        printf("%d\n",no->numero);
}

void imprimeLLvelho(NoListaLigada *lista){
    NoListaLigada *aux;

    aux = lista;
    while(aux!=NULL){
        printf("%d\n", aux->numero);
        aux= aux->proximo;
    }
}

void imprimeLL(NoListaLigada *lista){
    if(lista == NULL) return;  
    printf("%d\n", lista->numero);
    imprimeLL( lista->proximo);
}

void imprimeLLReversa(NoListaLigada *lista){
    if(lista == NULL) return;  
    imprimeLLReversa( lista->proximo);
    printf("%d\n", lista->numero);
}

NoListaLigada *encontraNo(NoListaLigada *lista, int q) {
    NoListaLigada *paux;

    paux = lista;
    while(paux) {     // paux != NULL
        if(paux->numero == q)
            return paux;
        paux = paux->proximo;
    }
    return NULL;
}

void removeNoPtr(NoListaLigada **lista, NoListaLigada *elemento) {
    NoListaLigada *paux;

    if(*lista == elemento){   //elemento é o primeiro da lista
        *lista = elemento->proximo;
        free(elemento);
        return;
    }
    paux = *lista;
    while( paux->proximo != elemento && paux!=NULL )  {
        paux = paux->proximo;
    }
    if(paux) {
        paux->proximo = elemento->proximo;
        free(elemento);
    }
}

void removeNo(NoListaLigada **lista, int q) {
    removeNoPtr( lista, encontraNo( *lista, q));
}

int tamanhoBag(NoListaLigada *lista){
   int contador = 0;
   
   while(lista){
     contador++;
     lista = lista->proximo;
   }
}

int sorteiaNum(NoListaLigada *sacola){
    
    return random()%tamanhoBag(sacola);
}


int pegaItem(NoListaLigada **sacola){
    int item, valor;
    NoListaLigada *ptr=NULL;
    
    if(*sacola==NULL){
      printf("Erro - sacola vazia\n);
      return0;
    item = sorteiaNum(*sacola);
    ptr = *sacola;
    for(int i=0; i < item; i++) ptr = ptr->proximo;
    
    valor = ptr->numero;
    removeNoPtr(sacola, ptr);
    return valor;
}

int main() {
    NoListaLigada *noAux;

    NoListaLigada *bag=NULL;
   
    insereNo( &bag, 11 );
    insereNo( &bag, 12 );
    insereNo( &bag, 13 );
    
    printf("Tamanho da sacola: %d\n", tamanhoBag(bag));
    printf("Nro sorteio: %d\n", sorteiaNum(bag));
    printf("Nro sorteio: %d\n", sorteiaNum(bag));
    printf("Nro sorteio: %d\n", sorteiaNum(bag));    
    printf("Nro sorteio: %d\n", sorteiaNum(bag));    

}
