#include <stdio.h>

int main(){
  int n;
  scanf("%d", &n);

  int maior = 0, menor = 0, pares = 0;
  float media = 0;

  for (int i = 0; i < n; i++){
    int num;
    scanf("%d", &num);

    if (i == 0) {
      maior = num;
      menor = num;
    } else if (num > maior) {
      maior = num;
    } else if (num < menor) {
      menor = num;
    }

    if (num % 2 == 0) {
      pares++;
    }

    media += num;
  }

  media = media / n;

  printf("%d %d %d %d %.6f", maior, menor, pares, (n-pares), media);
  return 0;
}
