#define _CRT_SECURE_NO_WARNINGS 
#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
const int MOD = 1000000;

//�ǻ�� �ֱ� : M=10^k �� ������ �ֱ�� �׻� 15x10^(k-1)��.
//���⼭ k = 6�̹Ƿ� 15x10^5 ���� �ݺ��ȴ�

int main(void) {
	long long N, ppre = 1, pre = 0, current = 0;
	scanf("%lld", &N);
	N %= 1500000;
	while (N--) {
		current = (ppre % MOD + pre % MOD)% MOD;
		ppre = pre % MOD;
		pre = current;
	}
	printf("%lld", current);

	return 0;
}