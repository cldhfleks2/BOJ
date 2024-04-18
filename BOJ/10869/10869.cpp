#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>

int main(int a, int b) {
	scanf("%d %d", &a, &b);

	printf("%d\n%d\n%d\n%d\n%d",
		a + b,
		a - b,
		a * b,
		a / b,
		a % b);

	return 0;
}