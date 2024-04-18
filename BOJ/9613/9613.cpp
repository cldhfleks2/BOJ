#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

int GCD(int a, int b) {
	int temp;
	while (b != 0) {
		temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}

int main(void) {
	int t = 0;
	scanf("%d", &t);

	while (t--) {
		int n = 0;
		scanf("%d", &n);
		int* numbers = new int[n];
		for (int i = 0; i < n; i++)
			scanf("%d", &numbers[i]);
		long long res = 0;
		for (int i = 0; i < n - 1; i++)
			for (int j = i + 1; j < n; j++) {
				res += GCD(numbers[i], numbers[j]);
			}
		printf("%lld\n", res);
	}
	return 0;
}