#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>

int main(int n) {
	scanf("%d", &n);

	if (n == 1) {
		printf("*");
		return 0;
	}

	//n¹ø¹Ýº¹
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j += 2)
			printf("* ");
		printf("\n");
		for (int j = 0; j < n / 2 ; j++)
			printf(" *");
		printf("\n");
	}


	return 0;
}