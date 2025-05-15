#include <stdio.h>

int main(){
  int n, m;
  scanf("%d %d", &n, &m);

  for (n++; n<m; n++) {
    int ab, cd, ef;

    ab = n / 100;
    cd = n - (ab * 100);
    ef = ab + cd;

    if (ef * ef == n){
      printf("%d\n", n);
    }
  }
  return 0;
}
