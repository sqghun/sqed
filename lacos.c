#include <stdio.h>

int main()
{
    int i;
    for (i=0; i <11; i++) printf("%d\n",i);

    // criando variáveis na hora    
    for (int j=0; j <11; j++) printf("%d\n",j);

    int k;
    for (;;){
       printf("%d\n",k++);
       if(k>0) break;
    }
          
    i=0;
    while(i<1){
      printf("%d\n",i);
      i++;
    }

    i=0;
    do {
         printf("%d\n",i++);
         //i++;
    } while(i<11);  

    i=0;
    do {
         printf("%d\n",++i);
         //i++;
    } while(i<11);  

    
     
}
