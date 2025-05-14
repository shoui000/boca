#include <stdio.h>

int main(){
  int i = 0;
  int sum = 0;
  int max = 0;
  while (1) {
    int n;
    scanf("%d", &n);
    
    if (n == 0) {
      break;
    }

    i++;
    sum += n;

    if (i == 1 || n > max) {
      max = n;
    }

    printf("%d %.6f\n", max, (sum/(float)i));
  }
}
