#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>

int main(int n) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = i; j < n; j++)
			printf(" ");
		printf("*");
		for (int j = 1; j < i; j++) {
			printf(" *");
		}
		printf("\n");
	}


	return 0;
}