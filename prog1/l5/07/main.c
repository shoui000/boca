#include <stdio.h>

int main() {
  int n;
  scanf("%d ", &n);

  if (n < 2) {
    printf("NAO");
    return 0;
  }

  int numeros[n];
  
  for (int i = 0; i < n; i++) {
    scanf("%d ", &numeros[i]);
  }

  int razao = numeros[1] - numeros[0];
  for (int i = 0; i < n-1; i++) {
    if (numeros[i+1] - numeros[i] != razao) {
      printf("NAO");
      return 0;
    }
  }

  printf("RESP:%d", razao);

  return 0;
}
