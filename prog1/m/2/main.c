#include <stdio.h>

int main(){
  float n;
  scanf("%f", &n);
  int parteInteira = (int)n;
  float parteReal = n - parteInteira;

  printf("INTEIRO:%d,REAL:%.2f", parteInteira, parteReal);
  return 0;
}
