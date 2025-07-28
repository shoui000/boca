#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE_PATH 1000
#define MAX_ROADS 12
#define MAX_COLUMNS 100
#define MAX_CARS_PER_ROAD 10
#define SPRITE_MAX_WIDTH 3
#define SPRITE_MAX_HEIGHT 2
#define UNUSABLE_ROADS 2
#define MAX_SPRITES 5

typedef struct {
  int a, b, c;
} car;

typedef struct {
  int speed, carsCount, direction;
  car cars[MAX_CARS_PER_ROAD];
} road;

typedef struct {
  int a, b, c, road, lifes;
} chicken;

typedef struct {
  int animate, mapWidth, roadsCount;

  chicken chicken;
  int spriteIndex;

  char sprites[MAX_SPRITES][SPRITE_MAX_HEIGHT][SPRITE_MAX_WIDTH];

  road roads[MAX_ROADS];
} GAME;

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("ERRO: Informe o diretorio com os arquivos de configuracao.\n");
    exit(1);
  }

  GAME g;

  exit(0);
}
