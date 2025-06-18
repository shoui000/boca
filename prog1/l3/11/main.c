#include <stdio.h>

int EhPar(int x) { 
  return (x % 2 == 0);
}

void PrintaPares(int n) {
  for (int i = 1; i <= n*2; i++) {
    if (EhPar(i)) {
      printf("%d ", i);
    }
  }
}

void PrintaImpares(int n) {
  for (int i = 1; i <= n*2; i++) {
    if (!EhPar(i)) {
      printf("%d ", i);
    }
  }
}

int main() {
  int x, y;
  scanf("%d %d", &x, &y);

  switch (x) {
    case 0:
      PrintaPares(y);
      break;
    case 1:
      PrintaImpares(y);
      break;
  }

  return 0;
}
