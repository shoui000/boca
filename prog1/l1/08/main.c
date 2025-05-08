#include <stdio.h>

int main(){
  char l;
  scanf("%c", &l);

  char vogais[] = {'a', 'e', 'i', 'o', 'u'};
  for (int i = 0; i < 5; i++) {
    if(vogais[i] == l || vogais[i] == (l+32)){
      printf("Vogal");
      return 0;
    }
  }

  printf("Nao vogal");
  return 0;
}
