#include <stdio.h>

// x1, x2, x3
// x1 > x2 < x3 vale
// x1 < x2 > x3 pico

float equacionar(float a, float b, float c, float d, float x) {
    return (a * (x*x*x) + b * (x*x) + c * (x) + d);
}

int main() {
  float a, b, c, d, e, f;
  scanf("%f %f %f %f %f %f", &a, &b, &c, &d, &e, &f);
  int vale = 0, pico = 0;

  for (int x = e; x < f; x++) {
    float analise[3];
    analise[0] = equacionar(a, b, c, d, x-1);
    analise[1] = equacionar(a, b, c, d, x);
    analise[2] = equacionar(a, b, c, d, x+1);

    if (analise[0] > analise[1] && analise[1] < analise[2]) {
      printf("Vale em x=%d\n", x);
      vale=1;
    }

    if (analise[0] < analise[1] && analise[1] > analise[2]) {
      printf("Pico em x=%d\n", x);
      pico=1;
    }
  }

  if (!pico) {
    printf("Nao ha pico\n");
  }

  if (!vale) {
    printf("Nao ha vale");
  }

  return 0;
}
