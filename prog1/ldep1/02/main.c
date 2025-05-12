#include <stdio.h>

int main() {
    int idade;

    scanf("%d", &idade);

    if(idade < 16)  printf("vc nao pode votar!\n");
    if(idade >= 16 && idade < 18 || idade >= 65) printf("vc pode votar, mas nao eh obrigado!\n");
    if(idade >= 18 && idade < 65) printf("vc eh obrigado a votar!\n");

    return 0;
}
