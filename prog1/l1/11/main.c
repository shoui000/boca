#include <stdio.h>

int main() {
  char *arr[] = {"Jan", "Fev", "Mar", "Abr", "Mai", "Jun", "Jul", "Ago", "Set", "Out", "Nov", "Dez"};

  int n;
  scanf("%d", &n);
  if (n > 0 && n < 13) {
    printf("%s.", arr[n-1]);
  } else {
    printf("Invalido.");
  }

  return 0;
}
