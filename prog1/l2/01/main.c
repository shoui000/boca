#include <stdio.h>

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	printf("RESP:");
	for (n+=1; n < m; n++){
		if (n % 2 == 0) {
			printf("%d ", n);
		}
	}
}
