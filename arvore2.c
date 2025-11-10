// Implementa arvore

#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int numero;
    struct no *fe;
    struct no *fd;
    
} No;


void insereNo(No **arv, int valor){
    No *novoNo;
    
    if(!*arv) {
        novoNo = malloc(sizeof(No));
        if(!novoNo) {
           printf("Erro de alocação de memória.\n");
           exit(-1);   
        }

        novoNo->numero = valor;
        novoNo->fd=NULL;
        novoNo->fe=NULL;
        *arv = novoNo;
        return;    
    }
    if(*arv->numero < valor){
      insereNo(&((*arv)->fd), valor); 
    } 
    else{
      insereNo(&((*arv)->fe), valor); 
    } 
    return;
}

No *encontraNo(NoListaDL *lista, int q) {
    No *paux;

    paux = lista;
    while(paux) {     // paux != NULL
        if(paux->numero == q)
            return paux;
        paux = paux->proximo;
    }
    return NULL;
}

void removeNoPtr(NoListaDL **lista, NoListaDL *elemento) {
    No *paux;

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


int main() {
    No *arvore = NULL;

    insereNo( &arvore, 10 );
    insereNo( &arvore, 10 );
    insereNo( &arvore, 10 );
    insereNo( &arvore, 10 );
    insereNo( &arvore, 10 );
    insereNo( &arvore, 10 );

    return 0;
    //imprimeLLReversa( registro );

    //imprime( registro );
    //printf("\nEncontrando nó anterior ao '12'\n");
    //noAux = noAnterior(registro, encontraNo(registro,12) );

    //imprimeNo(noAux);


}
