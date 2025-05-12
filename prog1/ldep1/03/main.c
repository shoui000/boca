#include <stdio.h>

int main() {
  int a, i = 1;

  scanf("%d", &a);

  for(int i = 1; i < a; i++){
    if(i % 2 == 0) {
      printf("%d ", i);
    } else if(i % 3 == 0) {
      printf("%d ", i);
  }}

  printf("\n");
  return 0;
}
