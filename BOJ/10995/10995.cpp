#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>

int main(int n) {
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		if (i % 2 == 0) {
			for (int j = 0; j < n; j++)
				printf(" *");
			printf("\n");
		}
		else {
			for (int j = 0; j < n; j++)
				printf("* ");
			printf("\n");
		}
	}


	return 0;
}