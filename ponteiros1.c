// Ler uma string e retornar o nro de palavras

#include <stdio.h>
#define MAXS 200

int main() {
    char entrada[MAXS];
    char *p;
    int conta=0;
    
    fgets(entrada, MAXS, stdin); 

    printf("Cadeia de char lida: %s\n\n:", entrada);     
    p = entrada;
    while(*p!='\0'){
      while(*p!=' ' && *p!='\n' && *p!='\n'){ 
        p++;
      }
      while((*p==' ' || *p=='\n') && *p!='\0'){ 
        p++;
      }
      conta++;
    }
    printf("Nro de palavras: %d\n\n:", conta);     
} 
