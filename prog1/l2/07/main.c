#include <stdio.h>

int main(){
  int n, primo=1;
  scanf("%d", &n);

  for (int i = 1; i < n; i++) {
    if (n % i == 0 && i != 1) {
      primo = 0;
      break;
    }
  }

  if (primo) {
    printf("Primo");
  } else {
    printf("Nao primo");
  }

  return 0;
}
