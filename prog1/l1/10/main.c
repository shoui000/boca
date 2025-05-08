#include <stdio.h>

int main(){
  int a;
  scanf("%d", &a);

  if (a & 0x01) {
    printf("Impar");
  } else {
    printf("Par");
  }

  return 0;
}
