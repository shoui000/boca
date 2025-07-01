#include <stdio.h>

int main() {
  int a, b, num;

  scanf("%d %d", &a, &b);
  printf("RESP:");

  for (int i = 0; i < b; i++) {
    scanf("%d", &num);

    if (num == a) {
      printf("%d", i);
      return 0;
      break;
    }
  }

  printf("%d", b);
  return 0;
}
