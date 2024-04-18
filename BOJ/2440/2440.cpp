#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>

int main(int n) {
	scanf("%d", &n);
	for (int i = n; i > 0; i--) {
		for (int k = i; k < n; k++)
			printf(" ");
		for (int j = 0; j < i; j++)
			printf("*");
		printf("\n");
	}
}