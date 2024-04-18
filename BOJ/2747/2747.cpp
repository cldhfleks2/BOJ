#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
typedef long long ll;

int main(void) {
	ll N, ppre = 1, pre = 0, current=0;
	scanf("%d", &N);
	while (N--) {
		current = ppre + pre;
		ppre = pre;
		pre = current;
		printf("%lld\n", current);
	}
	printf("%lld", current);

	return 0;
}