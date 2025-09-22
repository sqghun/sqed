// ponteiros

#include <stdio.h>

int main() {
    int *p, *q, *r;
    int x=99;
    int w=90;
    int y=100;
    
    p = &x;
    q = &w;
    r = &y;

    printf("endereço em p: %lx val: %dx\n", p, *p);    
    printf("Ponteiro p: %ls\n", p);
    printf("Variavel x: %d\n", x);
    printf("Valor do endereço x: %d\n", *p);
} 
