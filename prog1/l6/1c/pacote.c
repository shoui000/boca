#include <stdio.h>
#include "pacote.h"

tPacote LePacote() {
  tPacote t;
  scanf("%3d %3d %1d%9c %4d", &t.msgId, &t.pctId, &t.msgSize, t.msgPart, &t.error);
  t.msgPart[9] = '\0';
  return t;
}

void ImprimePacote(tPacote pct) {
  printf("PCT: %d,%d,%d,", pct.msgId, pct.pctId, pct.msgSize);

  for (int i = 0; i < pct.msgSize; i++) {
    putchar(pct.msgPart[i]);
  }

  printf(",%d\n", pct.error);
}

int VerificaPacote(tPacote pct) {
  int sum = 0;

  sum = pct.msgId + pct.pctId + pct.msgSize;

  for (int i = 0; i < pct.msgSize; i++) {
    sum += (int)pct.msgPart[i];
  }

  return (sum == pct.error);
}
