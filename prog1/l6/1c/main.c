#include <stdio.h>
#include "pacote.h"
#include "mensagens.h"

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
