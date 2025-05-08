#include <stdio.h>

int main(){
  int p, i;
  scanf("%d %d", &p, &i);
  int result;

  if (p == 1) {
    result = 1;
  } else {
    if (i % p == 0) {
      result = p;
    } else {
      result = i % p;
    }
  }

  printf("RESP:%d", result);
  return 0;
}
