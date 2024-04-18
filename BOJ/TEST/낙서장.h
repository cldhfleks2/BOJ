#include <stdio.h>

int main(void) {
	int n, sum;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
		sum += i;

	printf("%d", sum);


	return 0;
}