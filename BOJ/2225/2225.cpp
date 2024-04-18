#include <iostream>
using namespace std;
long** dp;
int MOD = 1000000000;
long decomposition(int k, int n) {
	for (int i = 1; i <= k; i++) {
		for (int j = 0; j <= n; j++) {
			for (int l = 0; l <= j; l++) {
				cout << "!" << endl;
				dp[i][j] += (dp[i][j] + dp[i - 1][j - 1])%MOD;
			}
		}
	}
	return dp[k][n];
}
int main() {
	int n = 0;
	int k = 0;
	cin >> n >> k;
	dp = new long* [k + 1];
	for (int i = 0; i < k + 1; i++) { //1~k까지 2차원배열생성
		dp[i] = new long[n + 1];
	}
	for (int i = 0; i <= n; i++) {
		dp[1][i] = 1;
		dp[0][i] = 0;
	}
	cout << "!" << decomposition(k, n) << endl;

	return 0;
}