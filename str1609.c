// encontrar caracteres numa string
// strcpy, strcat, strstr, strcmp
// man strstr -- documentação C
// ponteiro = variavel q contem endereço de memória

#include <stdio.h>
#include <string.h>

int main() {
    char *s = "Bem-vindo";
    char q[20];
    
    char texto[500];    

    char *p1, * p2, * p2
    
    
    printf("Entre seu nome:");
    fgets(q, 20, stdin);
    printf("%s %s", s, q); 
    
    strcpy(texto, s);
    strcat(texto, " ");
    strcat(texto, q);
    strcat(texto, "!");
    strcat(texto, "\n");
    printf("%s",texto);
    printf("Tamanho: %ld\nd", strlen(texto));
    
    // o string texto é terminado com \n do fgets
    
    for(int i=0; i<strlen(q); i++){
       if(q[i] == '\n'){
          q[i]='\0';
          break;
       }   
    }    

    printf("%s",texto);
    printf("Tamanho: %ld\nd", strlen(texto));

    strcpy(texto, s);
    strcat(texto, " ");
    strcat(texto, q);
    strcat(texto, "!");
    strcat(texto, "\n");
    printf("%s",texto);
    printf("Tamanho: %ld\nd", strlen(texto));
    
}    
