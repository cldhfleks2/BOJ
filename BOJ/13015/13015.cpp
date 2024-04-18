#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>

int main(int n) {
	scanf("%d", &n);

	if (n == 1) {
		printf("*");
		return 0;
	}
	else if(n == 2){
		printf("** **\n ***\n** **");
		return 0;
	}
	else if (n == 3) {
		printf("***   ***\n * * * *\n  * * *\n * * * *\n***   ***");
		return 0;
	}
	for (int i = 0; i < n; i++)
		printf("*");
	for (int i = 0; i < 2 * n - 3; i++)
		printf(" ");
	for (int i = 0; i < n; i++)
		printf("*");
	printf("\n");

	for (int i = 1; i <= n-2; i++) {
		for (int j = 0; j < i; j++)
			printf(" ");
		printf("*");
		//내부 공백
		for (int j = 0; j < n - 2; j++)
			printf(" ");
		printf("*");
		//외부 공백
		for (int j = 0; j < 2*(n-i)-3; j++)
			printf(" ");
		printf("*");
		for (int j = 0; j < n - 2; j++)
			printf(" ");
		printf("*\n");
	}

	for (int i = 0; i < n - 1; i++)
		printf(" ");
	printf("*");
	for (int i = 0; i < n - 2; i++)
		printf(" ");
	printf("*");
	for (int i = 0; i < n - 2; i++)
		printf(" ");
	printf("*\n");

	for (int i = n - 2; i >= 1; i--) {
		for (int j = 0; j < i; j++)
			printf(" ");
		printf("*");
		for (int j = 0; j < n - 2; j++)
			printf(" ");
		printf("*");
		for (int j = 0; j < 2 * (n - i) - 3; j++)
			printf(" ");
		printf("*");
		for (int j = 0; j < n - 2; j++)
			printf(" ");
		printf("*\n");
	}

	for (int i = 0; i < n; i++)
		printf("*");
	for (int i = 0; i < 2 * n - 3; i++)
		printf(" ");
	for (int i = 0; i < n; i++)
		printf("*");

	return 0;
}