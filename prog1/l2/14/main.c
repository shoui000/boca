#include <stdio.h>

int main(){
	printf("RESP:");
	while (1) {
		char c;
		scanf("%c", &c);

		if (c != ' ') {
			printf("%c", c);
			if (c == '.' || c == '?' || c == '!') {
				break;
			}
		}
	}
	return 0;
}

