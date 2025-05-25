#include <stdio.h>

int main(){
  int l, c, maxI, maxJ, max;
  scanf("%d %d", &l, &c);

  for(int i = 0; i < l; i++) {
    for (int j = 0; j < c; j++) {
      int v;
      scanf("%d", &v);

      if ((i == 0 && j == 0) || max < v) {
        maxI = i+1; maxJ = j+1; max = v;
      }

    }
  }

  printf("%d (%d, %d)", max, maxI, maxJ);
  return 0;
}
