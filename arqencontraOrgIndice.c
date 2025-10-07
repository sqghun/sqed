// Lê arquivo csv e monta lsita de registros de ORG especificadas
// Silvia Q
// 06/10/2025

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "arqutil.h"

int main(int argc, char **argv) {
  char query[100];
  int encontrados=0;
     
  Registro *listaRegistros;   

  if(argc<2){ // não passou parâmetros para o programa
     printf("\nEntre com parte da org desejada: ");
     fgets(query, 100, stdin);
     }
  else {
     strcpy(query, argv[1]);
  }          
  limpa(query);

  encontrados = encontraRegsEstruturado(query, ORG, &listaRegistros);
  printf("\n%d Registros encontrados\n", encontrados);
 
}
