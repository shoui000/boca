#include <stdio.h>

int verificaPrimo(int n) {
  int x = (n > 0) ? n : -n;
  if (x == 0 || x == 1) {
    return 0;
  } else {
    for (int i = 2; i <= x/2; i++) {
      if (x % i == 0) {
        return 0;
        break;
      }
    }

    return 1;
  }
}

int verificaNegativo(int n) {
  return (n < 0) ? 1 : 0;
}

int transformarPrimo(int n) {
  if (verificaPrimo(n)) {
    return n;
  }

  int x = verificaNegativo(n) ? -n : n;
  int i = x;
  while (1) {
    if (i == 32000) {
      return n;
    }

    if (verificaPrimo(i)) {
      return verificaNegativo(n) ? -i : i;
    }

    i++;
  }

  return 0;
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    printf("\t");
    for (int j = 0; j < m; j++) {
      int x;
      scanf("%d", &x);

      printf("%d ", transformarPrimo(x));
    }

    printf("\n");
  }
  return 0;
}
