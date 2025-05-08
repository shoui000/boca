#include <stdio.h>

int main(){
  char l;
  scanf("%c", &l);

  if ( l >= 97 && l <= 122 ){
    l -= 32;
    printf("%c(%d)", l, l);
  } else if ( l >= 65 && l <= 90 ){
    printf("A letra deve ser minuscula!");
  } else {
    printf("Nao e letra!");
  }

  return 0;
}
