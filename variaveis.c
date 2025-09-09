#include <stdio.h>

int main() {
  char caractere;
  int inteiro;
  float pontoFlutuante; 
  double duplo;
  short int intPequeno;
  long int intLongo;
  
  caractere = 'A';
  printf("\n O valor de caractere é %c", caractere);
  printf("\n O valor de caractere é %d", caractere);
  printf("\n");
  
  printf("\n O tamanho da variavel inteiro é \t%ld", sizeof(inteiro));
  printf("\n O tamanho da variavel caractere é \t%ld", sizeof(caractere));
  printf("\n");
 
}
