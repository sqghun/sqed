#include <stdio.h>

int main()
{
    int a=7, b=5, c=9;
    int d, e ,f;   
    
    if(a>b && a>c) {
       printf("a é maior\n");
    }
    else if(b>c) {
       printf("b é maior\n");
    }
    else {
       printf("c é maior\n"); 
    } 
 
    scanf("%d %d %d", &d, &e, &f);          
}
