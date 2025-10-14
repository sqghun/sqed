// header file

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <arqutil.h>


#define MAXLIN 900

#define NOME  0
#define CARGO 1
#define ORG   2
#define UORG  3

typedef struct no  
{
    Registro registro;
    struct no *proximo;
} ListaReg;

