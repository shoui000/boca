#include <stdio.h>
#include <math.h>

int main(){
  int n;
  scanf("%d", &n);

  float soma = 0;
  for (int i = 1; i <= n; i++) {
    soma += 6 / (float)(i * i);
  }

  float result = sqrt(soma);
  printf("%.6f", result);
  return 0;
}
