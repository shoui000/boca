#include <stdio.h>

#define MAX_DEVICES 100

typedef struct {
  int id;
  float grade;
} hackedDevice;

int newDevice(hackedDevice devices[], int lastDevice);

void listDevices(hackedDevice devices[], int lastDevice);

void sortDevices(hackedDevice devices[], int lastDevice);

int main() {
  int option, lastDevice = -1;
  hackedDevice devices[MAX_DEVICES];

  while (1) {
    printf("====== CYBERTEST - MENU ======\n");
    printf("1 - Cadastrar novo dispositivo\n");
    printf("2 - Listar dispositivos\n");
    printf("3 - Ordenar por vulnerabilidade\n");
    printf("4 - Sair\n");
    printf("Escolha: ");

    scanf("%d", &option);

    switch (option) {
      case 1:
        lastDevice = newDevice(devices, lastDevice);
        break;

      case 2:
        listDevices(devices, lastDevice);
        break;

      case 3:
        sortDevices(devices, lastDevice);
        break;

      case 4:
        printf("Saindo do sistema...\n");
        return 0;
        break;

      default:
        printf("Opção Inválida!\n");
        break;
    }

    putchar('\n');
  }

  return 0;
}

int newDevice(hackedDevice devices[], int lastDevice) {
  if (lastDevice == MAX_DEVICES) {
    printf("ERRO! Dispositivo excede maximo de dispositivos cadastrados");
    return lastDevice;
  }

  hackedDevice d;
  printf("Codigo do dispositivo: ");
  scanf("%d", &d.id);
  printf("Nota de vulnerabilidade: ");
  scanf("%f", &d.grade);

  if (d.grade > 10 || d.grade < 0) {
    printf("ERRO! Nota de vulnerabilidade esta fora da escala\n");
    return lastDevice;
  }

  lastDevice++;
  devices[lastDevice] = d;

  return lastDevice;
}

void listDevices(hackedDevice devices[], int lastDevice) {
  printf("Lista de dispositivos cadastrados:\n");

  for (int i = 0; i <= lastDevice; i++) {
    printf("Codigo: %d | Vulnerabilidade: %.1f\n", devices[i].id, devices[i].grade);
  }
}

void sortDevices(hackedDevice devices[], int lastDevice) {
  printf("Ordenando dispositivos...\n");

  if (lastDevice < 1) {
    return;
  }

  // bubble sort
  int swaps = 0;
  do {
    swaps = 0;
    for (int i = 0; i < lastDevice; i++) {
      if (devices[i].grade < devices[i+1].grade) {

        hackedDevice temp = devices[i+1];
        devices[i+1] = devices[i];
        devices[i] = temp;
        swaps++;

      }
    }
  } while (swaps);

}

