#include "data.h"

int main() {
  tData d1 = leData();
  tData d2 = leData();

  while (1) {
    if (ehIgual(d1, d2)) {
      break;
    }

    imprimeData(d1);
    d1 = avancaDia(d1);
  }
  return 0;
}
