#include <stdio.h>

int main() {
  int b, c, d;
  int a = 0;

  scanf("%d", &d);
  while(a < d){
    scanf("%d %d", &b, &c);
    printf("%d\n", b + c);
    a++;
  }

  return 0;
}
