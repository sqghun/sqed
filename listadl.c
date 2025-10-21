// Implementa lista ligada

#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int numero;
    struct no *anterior;
    struct no *proximo;
    
} NoListaDL;


void insereNo(NoListaDL **lista, int carga){
    NoListaDL *novoNo;
    NoListaDL *aux;

    novoNo = malloc(sizeof(NoListaDL));
    if(!novoNo) {
        printf("Erro de alocação de memória.\n");
        exit(-1);   
    }
    novoNo->numero = carga;
    novoNo->proximo=NULL;

    if( *lista==NULL )
        *lista = novoNo;
    else {
        aux = *lista;
        while(aux->proximo!=NULL){
            aux = aux->proximo;
        }
        aux->proximo=novoNo;
    }
}

void insereNoInicio(NoListaDL **lista, int carga) {
    NoListaDL *novoNo=NULL;

    novoNo = malloc(sizeof(NoListaDL));
    if(!novoNo) {
        printf("Erro de alocação de memória.\n");
        exit(-1);   
    }
    novoNo->numero = carga;
    novoNo->proximo=NULL;
    novoNo->anterior=NULL;
    
    if( *lista==NULL )
        *lista = novoNo;   
    else {
        novoNo->proximo = *lista;
        (*lista)->anterior = novoNo;
        *lista = novoNo;
    }

}

void imprimeNo(NoListaDL *no){
    if(!no) 
        printf("Nó Null\n");
    else
        printf("%d\n",no->numero);
}

void imprimeLLvelho(NoListaDL *lista){
    NoListaDL *aux;

    aux = lista;
    while(aux!=NULL){
        printf("%d\n", aux->numero);
        aux= aux->proximo;
    }
}

void imprime(NoListaDL *lista){
    while(lista) {
      printf("%d\n", lista->numero);
      lista = lista->proximo;
    }
    return;
}    

void imprimeLL(NoListaDL *lista){
    if(lista == NULL) return;  
    printf("%d\n", lista->numero);
    imprimeLL( lista->proximo);
}

void imprimeLLReversa(NoListaDL *lista){
    if(lista == NULL) return;  
    imprimeLLReversa( lista->proximo);
    printf("%d\n", lista->numero);
}

NoListaDL *encontraNo(NoListaDL *lista, int q) {
    NoListaDL *paux;

    paux = lista;
    while(paux) {     // paux != NULL
        if(paux->numero == q)
            return paux;
        paux = paux->proximo;
    }
    return NULL;
}

void removeNoPtr(NoListaDL **lista, NoListaDL *elemento) {
    NoListaDL *paux;

    if(*lista == elemento){   //elemento é o primeiro da lista
        *lista = elemento->proximo;
        (*lista)->anterior = NULL;
        free(elemento);
        return;
    }
    paux = *lista;
    while( paux->proximo != elemento && paux!=NULL )  {
        paux = paux->proximo;
    }
    if(paux) {
        paux->proximo = elemento->proximo;
        if(paux->proximo){   
          paux->proximo->anterior = paux; 
        }
        free(elemento);
    }
}

void removeNo(NoListaDL **lista, int q) {
    removeNoPtr( lista, encontraNo( *lista, q));
}

NoListaDL *noAnterior(NoListaDL *lista, NoListaDL *no) {
    NoListaDL *paux;

    if(no==lista) return NULL;
    paux = lista;
    while(paux->proximo!=no && paux->proximo!=NULL)
        paux = paux->proximo;
    if(paux->proximo==no) return paux;
    return NULL;
}


int main() {
    NoListaDL *noAux;

    NoListaDL *registro=NULL;

    //insereNoInicio( &registro, 10 );
    //insereNoInicio( &registro, 9 );
    //insereNoInicio( &registro, 8 );
    
    insereNoInicio( &registro, 99 );
    insereNoInicio( &registro, 11 );
    insereNoInicio( &registro, 12 );
    insereNoInicio( &registro, 13 );

    removeNo( &registro, 99 );

    //imprimeLLReversa( registro );

    imprime( registro );
    //printf("\nEncontrando nó anterior ao '12'\n");
    //noAux = noAnterior(registro, encontraNo(registro,12) );

    //imprimeNo(noAux);


}
