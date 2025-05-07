#include <stdio.h>

int main(){
  float num;
  char t;

  scanf("%f %c", &num, &t);
  if (t == 'c' || t == 'C') {
    printf("%.2f (%c)", ((num * 9.0/5.0) + 32), 'F');
  } else {
    printf("%.2f (%c)", ((num - 32) * 5.0/9.0), 'C');
  }

  return 0;
}
