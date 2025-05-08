#include <stdio.h>
#include <math.h>
#define pi 3.141592

int main(){
  float raio, area, metadeArea, sRaio;
  scanf("%f", &raio);

  area = raio * raio * pi;
  metadeArea = area / 2.0;
  sRaio = sqrt(metadeArea / pi);

  printf("%.2f %.2f", area, sRaio);

  return 0;
}
