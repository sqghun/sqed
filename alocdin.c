// Alocacao dinamica

#include <stdio.h>
#include <stdlib.h>
#define MAXS 200

int main() {
    int *vet;
    int vetor[100];
    //aloca vetor p 100 inteiros
    vet = malloc(100 * sizeof(int));
    printf("tamanho do vet: %ld \n", sizeof(vet)); 
    printf("tamanho do vetor alocado estaticamente: %ld \n", sizeof(vetor)); 
    
    // para a struct data
    typedef struct{
       short int dia;
       short int mes;
       short int ano;
    } Data; 
    Data d;
    Data *pd;

    printf("tamanho da var data: %ld \n", sizeof(d));
    d.dia = 23;
    d.mes = 9;
    d.ano = 2025;

    pd->dia = 27;
    pd->mes = 10;
    pd->ano = 2025;

    printf("tamanho da var ponteiro data: %ld \n", sizeof(pd));  
    printf("endereço armazenado em pd: %ld \n", (long int)pd);  
    
    //pd = &d;
    printf("Dia %d, mês: %d ano: %d \n", pd->dia, pd->mes, pd->ano);
   
    //quero alocar dinamicamente
    pd = malloc(100 * sizeof(Data));
    if(!pd){ //alocação não foi bem sucedida => pd == NULL
       printf("Erro de alocação dinamica de memória!\n");
    }
    else {
        printf("Alocação dinamica de memória!\n");
    }       
    free(pd);
}

