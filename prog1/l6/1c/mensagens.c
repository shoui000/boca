#include <stdio.h>
#include "pacote.h"
#include "mensagens.h"

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
