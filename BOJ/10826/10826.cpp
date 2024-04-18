#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
typedef long long ll;
ll fibo[10001] = { 0, };


int main(void) {
	int N;
	scanf("%d", &N);
	fibo[0] = 0;
	fibo[1] = 1;
	for (int i = 2; i <= N; i++) {
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	}
	printf("%lld", fibo[N]);

	return 0;
}
