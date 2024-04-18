#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>

int main(void) {
	int T, t, temp, max=0;
	long long* dp;
	std::queue<int> input;
	scanf("%d", &T);
	t = T;
	while (t--) {
		scanf("%d", &temp);
		input.push(temp);
		if (max < temp) max = temp; //최댓값기록
	}
	dp = new long long[max + 1]; //1~max까지 dp값기록
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	dp[4] = 2;
	dp[5] = 2; //초깃값들

	for (int i = 6; i <= max; i++) {
		dp[i] = dp[i - 1] + dp[i - 5];
	}
	t = T;
	while (t--) {
		int num = input.front();
		input.pop();
		printf("%lld\n", dp[num]);
	}

	return 0;
}