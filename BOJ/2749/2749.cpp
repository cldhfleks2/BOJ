#define _CRT_SECURE_NO_WARNINGS 
#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
const int MOD = 1000000;

//피사노 주기 : M=10^k 로 나눌때 주기는 항상 15x10^(k-1)임.
//여기서 k = 6이므로 15x10^5 수가 반복된다

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