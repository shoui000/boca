#include <stdio.h>

int main(){
  int n = 0, sN = 0, p = 0, sP = 0;
  int c;
	while (scanf("%d", &c) == 1) {
    if (c > 0) {
      p++;
      sP += c;
    } else if (c < 0) {
      n++;
      sN += c;
    }
	}

  printf("%d %d %d %d", n, p, sN, sP);
	return 0;
}

