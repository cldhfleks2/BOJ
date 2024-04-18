#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>


int LCM(int a, int b) {
	if (a > b) { //a< b
		int temp = a;
		a = b;
		b = temp;
	}
	int res = 1;
	bool check = false;
	while (1) {
		for (int i = 2; i <= b; i++) {
			if (a % i == 0 &&
				b % i == 0) {
				check = true; //연산체크
				a /= i; //a, b를 모두 나누어서 다시저장
				b /= i;
				res *= i; //약수기록
			}
		}
		if (check) {
			check = false;
		}
		else {
			res *= a * b;
			break;
		}
	}
	return res;
}

int main(void) {
	int T;
	scanf("%d", &T);
	while (T--) {
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%d\n", LCM(a, b));
	}

	return 0;
}