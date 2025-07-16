#include <stdio.h>

typedef struct {
  int msgId, pctId, msgSize, error;
  char msgPart[10];
} tPacote;

tPacote LePacote() {
  tPacote t;
  scanf("%3d %3d %1d%9c %4d", &t.msgId, &t.pctId, &t.msgSize, t.msgPart, &t.error);
  t.msgPart[9] = '\0';
  return t;
}

void ImprimePacote(tPacote pacote) {
  printf("PCT: %d,%d,%d,", pacote.msgId, pacote.pctId, pacote.msgSize);
  for (int i = 0; i < pacote.msgSize; i++) {
    putchar(pacote.msgPart[i]);
  }
  printf(",%d\n", pacote.error);
}

int main() {
  int n;
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    tPacote t = LePacote();
    ImprimePacote(t);
  }

  return 0;
}
