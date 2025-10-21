// Silvia Quiota 
// Tarefa: Implementar lista

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <termios.h>
//#include <unistd.h>
#include <ctype.h>

typedef struct no {
    int numero;
    struct no *proximo;
} NoListaLigada;

void push(NoListaLigada **lista, int valor) {
    NoListaLigada *novoNo=NULL;
    NoListaLigada *aux;
   
    novoNo = malloc(sizeof(NoListaLigada));
    if(!novoNo) {
      printf("Erro de alocação de memoria\n");
      exit(-1); 
    }
    novoNo->numero=valor;
    novoNo->proximo=NULL;
    
    if(*lista==NULL) {
       novoNo->numero=valor;
       novoNo->proximo=NULL;
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

void imprimeLista(NoListaLigada *lista){
    if(lista==NULL) return;
    printf(" %d:\n", lista->numero);
    imprimeLista(lista->proximo);
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

    while(op!='X') {
        printf("\nQual operação Push(I), Pop(O), peek(P) ou Sai(x): ");
        scanf(" %c", &op);
        printf("Entrou com: %c\n",op);

        switch (toupper(op))
        {
        case 'I':
            /* code PUSH */
            printf("Entre com valor: ");
            scanf(" %d", &valor);
            clear_stdin_buffer();        
            push(&lista, valor);
            break;
        case 'O':
            /* code POP */
            if( pop(&lista, &valor) )
                printf("Valor: %d\n", valor);
            else
                printf("lista vazia\n");
            break;
        case 'P':
            /* code PEEK */
            if( peek(lista, &valor) )
                printf("Valor no topo da lista: %d", valor);
            else
                printf("lista vazia\n");
            break;
        case 'X':
            printf("Vai entrar no imprime.\n");
            imprimeLista(lista);
            break;
        default:
            printf("Opção inválida: %c\n", op);
            break;
        }
    }
}
