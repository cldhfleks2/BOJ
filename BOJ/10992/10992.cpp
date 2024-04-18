#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>

int main(int n) {
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++)
		printf(" ");
	printf("*\n");
	for (int i = 2; i < n; i++) {
		for (int j = 0; j < n - i; j++)
			printf(" ");
		printf("*");
		for (int j = 0; j < 2 * i - 3; j++)
			printf(" ");
		printf("*\n");
	}

	if(n != 1)
		for (int i = 0; i < 2 * n - 1; i++)
			printf("*");

	return 0;
}