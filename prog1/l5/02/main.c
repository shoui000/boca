#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  getchar();

  int diff = -2;
  int nota, anterior;
  for (int i = 0; i < n; i++) {
    scanf("%d", &nota);
    getchar();
    
    if (i == 0) {
      anterior = nota;
      continue;
    }

    if (i != 1) {
      if ( (anterior > nota && diff != -1) || 
           (anterior < nota && diff != 1) ) {

        printf("DESORDENADO");
        return 0;
        break;
      }
    }

    if (anterior > nota) {
      diff = -1;
    } else if (anterior < nota) {
      diff = 1;
    } 

    anterior = nota;
  }

  switch (diff) {
    case 1:
      printf("CRESCENTE");
      break;
    case -1:
      printf("DECRESCENTE");
      break;
    default:
      printf("CRESCENTE&DECRESCENTE");
      break;
  }

  return 0;
}
