#include <stdio.h>

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  printf("RESP:");
  for (n++; n<m; n++) {

    int primo = 1;
    for (int i = 1; i < n; i++) {
      if (n % i == 0 && i != 1) {
        primo = 0;
        break;
      }
    }

    if (primo) {
      printf("%d ", n);
    }

  }
  return 0;
}
