#include <bits/stdc++.h>
using namespace std;
// �������� ���� �������� �Ѵٰ� ����
// �� 1+2+4 = 1+4+2
typedef long long ll;
const ll MOD = 1000000000;
const int MAX = 1000005;

int N;
// dp[x][k] : x ��, 2^k �� ������ ����� �� ����
int dp[MAX][22];

int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; ++i) {
		int k = 0;
		int curr = 1;
		while (curr <= i) {
			int pre = i - curr; // �����ϴ� ��
			// ����
			if (pre == 0) dp[i][k] = 1;
			else {
				ll temp = 0LL;
				for (int j = 0; j <= k; ++j) temp = (temp + 1LL * dp[pre][j]) % MOD;

				dp[i][k] = (int)temp;
			}
			curr *= 2;
			k++;
		}
	}

	ll ans = 0LL;
	for (int i = 0; i < 22; ++i) ans = (ans + 1LL * dp[N][i]) % MOD;

	cout << ans << '\n';

	return 0;