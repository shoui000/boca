#include <stdio.h>
#include <math.h>

int main(){
	int n, i;
	scanf("%d %d", &n, &i);
	
	if ((int)floor(n / pow(10, (i-1))) % 2 == 0) {
		printf("PAR");
	} else {
		printf("IMPAR");
	};
	return 0;
}
