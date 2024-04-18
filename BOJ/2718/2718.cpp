#include <stdio.h>
long* dp;
long tile(int num) {
	if (num == 0) return dp[0] = 1;
	if (num == 1) return dp[1] = 1;
	if (num == 2) return dp[2] = 5;
	if (num == 3) return dp[3] = 11;
	return dp[num] = tile(num - 1) + 5 * tile(num - 2) + tile(num - 3) - tile(num - 4);
}

int main() {
	int t = 0;
	scanf("%d", &t);
	int* n = new int[t];
	int max = 0;

	for (int i = 0; i < t; i++) {
		int temp;
		scanf("%d", &temp);
		n[i] = temp;
		if (temp > max) max = temp;
	}
	dp = new long[max + 1];

	for (int i = 0; i < t; i++) {
		printf("%d\n", tile(n[i]));
	}

	return 0;
}