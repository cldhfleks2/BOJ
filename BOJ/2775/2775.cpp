#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
int dp[15][15]; //0층~14층 : 1호~14호

int DP(int k, int n) {
	if (k == 0) return n; //0층 i호에는 i명이 산다

	int sum = 0;
	//메모이제이션과 재귀를 통해 k-1층의 1~n호실까지합을 구함
	for (int i = 1; i <= n; i++) { 
		if (dp[k - 1][i] != -1)
			sum += dp[k - 1][i]; //이미있으면 꺼내씀
		else
			sum += DP(k - 1, i); //재귀적호출
	}
	//구한 합을 저장
	dp[k][n] = sum; 
	return sum;
}

int main(int t, int k, int n) {
	scanf("%d", &t);
	for (int i = 0; i < 15; i++) for (int j = 0; j < 15; j++) dp[i][j] = -1; //초기화
	for (int i = 1; i <= 14; i++) dp[0][i] = i; //0층 i호에는 i명이산다.
	while (t--) {
		scanf("%d%d", &k, &n);
		if (dp[k][n] != -1) { //이미 찾은값이면
			printf("%d\n", dp[k][n]);
			continue;
		}

		printf("%d\n", DP(k, n));
	}


	return 0;
}