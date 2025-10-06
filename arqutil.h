// header file

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXLIN 900

typedef struct 
{
    char ids[20];      // CPO 1
    char nome[100];    // CPO 2
    char cargo[60];    // CPO 5
    char org[100];     // CPO 17
    char uorg[100];    // CPO 19
} Registro;


void limpa(char *);
char *extrai(char *, char *)
Registro coleta(char *)

