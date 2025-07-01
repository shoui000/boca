#include <stdio.h>

int abs(int x) {
  return (x < 0) ? -x : x;
}

int main() {
  int n;
  scanf("%d", &n);

  if (n < 2) {
    printf("IMPOSSIVEL");
    return 0;
  }

  int alturas[n], num = 0, anterior = 0, diff = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", &num);
    alturas[i] = num;

    if (i == 0) { 
      anterior = num;
      continue;
    }

    if (abs(num-anterior) > diff) {
      diff = abs(num - anterior);
    }

    anterior = num;
  }

  for (int i = 0; i < n-1; i++) {
    if (abs(alturas[i+1] - alturas[i]) == diff) {
      printf(" (%d %d)", i, i+1);
    }
  }

  return 0;
}
