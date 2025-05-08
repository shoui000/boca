#include <stdio.h>

int main(){
  int n1, n2;
  scanf("%d %d", &n1, &n2);

  float media = (n1+n2) / 2.0;

  if (media >= 7.0) {
    printf("%.1f - Aprovado", media);
  } else if (media < 5.0) {
    printf("%.1f - Reprovado", media);
  } else {
    printf("%.1f - De Recuperacao", media);
  }

  return 0;
}
