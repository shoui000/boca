#include <stdio.h>

// é o código dos outros arquivos, porém em um grande arquivo unico pq deu compilation error no boca

#define MAX_PCTS 100

typedef struct {
  int msgId, pctId, msgSize, error;
  char msgPart[10];
} tPacote;

tPacote LePacote();

void ImprimePacote(tPacote pct);

int VerificaPacote(tPacote pct);

typedef struct {
  int id, lastPct;
  tPacote pcts[MAX_PCTS];
} tMensagens;

tMensagens novaMensagem(tPacote p);

tMensagens adicionarPct(tMensagens m, tPacote p);

tMensagens ordenarPcts(tMensagens m);

void imprimirMensagem(tMensagens m);

int adicionarMensagem(tMensagens m[], int lastMsg, tPacote p) {
  for (int i = 0; i <= lastMsg; i++) {
    if (m[i].id == p.msgId) {
      m[i] = adicionarPct(m[i], p);
      return lastMsg;
    }
  }

  tMensagens x = novaMensagem(p);
  lastMsg++;
  m[lastMsg] = x;

  return lastMsg;
}

void ordenarMensagens(tMensagens m[], int lastMsg) {
  int swaps = 0;
  do {
    swaps = 0;
    for (int i = 0; i < lastMsg; i++) {
      if (m[i].id > m[i+1].id) {
        tMensagens temp = m[i+1];
        m[i+1] = m[i];
        m[i] = temp;
        swaps++;
      }
    }
  } while (swaps);
}

int main() {
  int n, lastMsg = -1;
  scanf("%d", &n);

  tMensagens m[n];

  for (int i = 0; i < n; i++) {
    tPacote t = LePacote();

    lastMsg = adicionarMensagem(m, lastMsg, t);
  }

  ordenarMensagens(m, lastMsg);
  for (int i = 0; i <= lastMsg; i++) {
    m[i] = ordenarPcts(m[i]);
    
    // printf("Mensagem %d\n", i);
    // for (int j = 0; j <= m[i].lastPct; j++) {
    //   ImprimePacote(m[i].pcts[j]);
    // }
    imprimirMensagem(m[i]);
    if (i != lastMsg) { putchar('\n'); }
  }

  return 0;
}

tMensagens novaMensagem(tPacote p) {
  tMensagens m;
  m.id = p.msgId;
  m.lastPct = 0;
  m.pcts[0] = p;

  return m;
}

tMensagens adicionarPct(tMensagens m, tPacote p) {
  m.lastPct++;
  m.pcts[m.lastPct] = p;

  return m;
}

tMensagens ordenarPcts(tMensagens m) {
  // bubble sort
  int swaps = 0;
  do {
    swaps = 0;
    for (int i = 0; i < m.lastPct; i++) {
      if (m.pcts[i].pctId > m.pcts[i+1].pctId) {
        tPacote temp = m.pcts[i+1];
        m.pcts[i+1] = m.pcts[i];
        m.pcts[i] = temp;
        swaps++;
      }
    }
  } while (swaps);

  return m;
}

void imprimirMensagem(tMensagens m) {
  for (int i = 0; i <= m.lastPct; i++) {

    if (!VerificaPacote(m.pcts[i])) {

      printf("##FALHA##");

    } else {

      for (int j = 0; j < m.pcts[i].msgSize; j++) {
        putchar(m.pcts[i].msgPart[j]);
      }

    }
  }
}

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
