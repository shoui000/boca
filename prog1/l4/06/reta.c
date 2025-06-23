#include <stdio.h>
#include "ponto.h"
#include "reta.h"

tReta novaReta(tPonto p1, tPonto p2) {
  tReta r = {p1, p2};
  return r;
}

tReta leReta() {
  tPonto inicial = lePonto();
  tPonto final = lePonto();

  return novaReta(inicial, final);
}

void imprimeReta(tReta r) {
  printf("[");
  imprimePonto(r.pI);
  printf(":");
  imprimePonto(r.pF);
  printf("]");
}

tPonto getPInicial(tReta r) {
  return r.pI;
}

tPonto getPFinal(tReta r) {
  return r.pF;
}

tReta movReta(tReta r, int Dx, int Dy) {
  tReta nR = {{r.pI.x + Dx, r.pI.y + Dy}, {r.pF.x + Dx, r.pF.y + Dy}};
  return nR;
}

float tamReta(tReta r) {
  return distanciaPontos(r.pI, r.pF);
}
