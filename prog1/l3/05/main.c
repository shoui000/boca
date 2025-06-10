#include <stdio.h>

int Propriedade(int num) {
  int ab, cd, ef;
  
  ab = num / 100;
  cd = num - (ab * 100);

  ef = ab + cd;

  if (ef * ef == num) {
    return 1;
  }

  return 0;
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);

  for (int i = n+1; i < m; i++) {
    if (Propriedade(i)) {
      printf("%d\n", i);
    }
  }

  return 0;
}
