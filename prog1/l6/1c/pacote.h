#ifndef pacote
#define pacote

typedef struct {
  int msgId, pctId, msgSize, error;
  char msgPart[10];
} tPacote;

tPacote LePacote();

void ImprimePacote(tPacote pct);

int VerificaPacote(tPacote pct);

#endif // !pacote
