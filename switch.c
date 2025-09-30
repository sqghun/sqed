#include <stdio.h>

int main() {
  char s[100];
  char cara;

  fgets(s, 100, stdin);
  
  cara = s[0];
  switch (cara) {
     case 'h':
       printf("colocou H\n");
       break;
     case 'c': 
     case 'C': 
       printf("colocou H\n");
       break;
     default:
       printf("não colocou opções válidas! \n");
       break;
  }
}
