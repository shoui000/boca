#include <stdio.h>

int main(){
  int qtd=0;

  scanf("%d", &qtd);

  for(int i = 1; i <= qtd; i++){
    int cont = 0;
    for(int j = 1; j <= i; j++){
      if(i%j==0){
        cont++;
      }
    }

    if (cont == 2){
      printf("%d ", i);
    }

  }

  return 0;
}
