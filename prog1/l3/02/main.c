#include <stdio.h>

float soma(float a, float b)
{
	return a + b;
}

float subtracao(float a, float b)
{
	return a - b;
}

float divisao(float a, float b)
{
	return a / b;
}

float multiplicacao(float a, float b)
{
	return a * b;
}

float operar(float a, float b, char c)
{
	switch (c)
	{
	case '+':
		return soma(a, b);
		break;

	case '-':
		return subtracao(a, b);
		break;

	case '/':
		return divisao(a, b);
		break;

	case '*':
		return multiplicacao(a, b);
		break;
	}
}

int main()
{
	float arr[] = {0, 0};
	char c;
	scanf("%f %f %c", &arr[0], &arr[1], &c);
	arr[0] = operar(arr[0], arr[1], c);

	if (getchar() == ' ')	{
		while (1) {
			int a = scanf("%f %c", &arr[1], &c);
			arr[0] = operar(arr[0], arr[1], c);
			if (getchar() != ' ') {
				break;
			}
		}
	}

	printf("%.2f", arr[0]);

	return 0;
}