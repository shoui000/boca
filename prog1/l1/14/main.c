#include <stdio.h>

#define max(a, b) ((a > b) ? a : b)
#define min(a, b) ((a < b) ? a : b)

int main(){
  int x1, y1, x2, y2, x3, y3;
  scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);

  if ( ( x3 <= max(x1, x2) && x3 >= min(x1, x2) ) && ( y3 <= max(y1, y2) && y3 >= min(y1, y2) ) ) {
    printf("Dentro");
  } else {
    printf("Fora");
  }
  return 0;
}
