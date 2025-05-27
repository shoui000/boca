#include <stdio.h>

int main() {
	int n;
	scanf("%d",&n);

	int nums[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &nums[i]);
	}

	getchar();

	int x = 0;
	int waiting = 0;
	while (x != 2) {
		char c;
		scanf("%c", &c);

		if (c != '"' && c != '%' && !waiting) {
			printf("%c", c);
		} else if (waiting) {
			int pos = ((int)c) - 49;
			if (pos >= n || pos < 0) {
				printf("ERRO");
			} else {
				printf("%d", nums[pos]);
			}

			waiting = 0;
		} else if (c == '%') {
			waiting = 1;
		}

		if (c == '"') {
			x++;
		}
	}

	return 0;
}
