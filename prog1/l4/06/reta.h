#include "ponto.h"
#ifndef reta
#define reta

typedef struct {
  tPonto pI, pF;
} tReta;

tReta novaReta(tPonto p1, tPonto p2);

tReta leReta();

void imprimeReta(tReta r);

tPonto getPInicial(tReta r);

tPonto getPFinal(tReta r);

tReta movReta(tReta r, int Dx, int Dy);

float tamReta(tReta r);

#endif // !reta
