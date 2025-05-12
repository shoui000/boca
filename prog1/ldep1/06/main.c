#include <stdio.h>

int main(){
	int i, j, soma=0;
	
	scanf("%d %d", &i, &j);

	for(int x = 0; x < i; x++) {
		int somaLinha = 0;
		for(int z = 0; z < j; z++) {
			int y;
			scanf("%d" , &y);
			somaLinha += y;
		}

		printf("%d\n", somaLinha);
		soma += somaLinha;
	}

	printf("%d\n", soma);
	return 0;
}
