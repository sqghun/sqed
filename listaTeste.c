// Implementa lista

#include <stdio.h>
#include <stdlib.h>
//#include <termios.h>
//#include <unistd.h>
#include <ctype.h>

typedef struct no {
    int numero;
    struct no *proximo;
} NoListaLigada;

//void push(NoListaLigada **lista, int valor) {
//    NoListaLigada *novoNo=NULL;
//
//    novoNo = malloc(sizeof(NoListaLigada));
//    if(!novoNo) { // Erro de alocação de memória
//        printf("\nERRO de alocação de memória\n");
//        exit(-1);
 //   }
//    novoNo->numero = valor;
//    novoNo->proximo = *lista;
//    *lista = novoNo;
//}

void push(NoListaLigada **lista, int valor) {
    NoListaLigada *novoNo;
    NoListaLigada *aux;
   
    novoNo = malloc(sizeof(NoListaLigada));
    if(!novoNo) {
      printf("Erro de alocação de memoria\n");
      exit(-1); 
    }
    //memcpy(&(novoNo->registro), &reg, sizeof(Registro));
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

int pop(NoListaLigada **lista, int *valor) {
    NoListaLigada *ptr;

    ptr = *lista;
    if(!ptr) {  //lista vazia
        return 0;
    }
    *lista = ptr->proximo;
    *valor = ptr->numero;
    free(ptr);
    return 1;
}

int peek(NoListaLigada *lista, int *valor) {
    if(lista==NULL){//lista vazia
        return 0;
    }
    *valor = lista->numero;
    return 1;
}


// Função para ler apenas 1 caracter do teclado
//int pegacara() {
//    struct termios old_tio, new_tio;
//    char ch;

//    tcgetattr(STDIN_FILENO, &old_tio);
//    new_tio = old_tio;
//    new_tio.c_lflag &= ~(ICANON | ECHO);
//   tcsetattr(STDIN_FILENO, TCSANOW, &new_tio);
//    ch = getchar(); // Reads a single character without waiting for Enter
//    tcsetattr(STDIN_FILENO, TCSANOW, &old_tio);
//    return toupper(ch);  
//}
void clear_stdin_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
//////////////////////////////////////////////////

int main() {
    NoListaLigada *lista=NULL;
    int valor;
    char op;

    printf("\nQual operação Push(I), Pop(O), peek(P) ou Sai(X): ");
    scanf(" %c", &op);
    printf("Entrou com: %c\n",op);

}






