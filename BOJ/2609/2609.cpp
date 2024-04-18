#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>

int logic(int a, int b) {
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
			break;
		}
	}
	return res;
}

int LCM(int a, int b) {
	int res = logic(a, b); //최대공약수 여기에 a, b를 나눈몫을 각각곱해줘야함
	int a_q = a / res; //a, b를 최대공약수로 나누어 남은 몫만큼
	int b_q = b / res; //최대공약수들에 곱해주면 최대공배수가된다.
	res *= a_q * b_q;
	
	return res;
}

int GCD(int a, int b) {
	int res = logic(a, b); //최대공약수

	return res;
}

int main(void) {
	int a, b;
	scanf("%d%d", &a, &b); 

	printf("%d\n%d", GCD(a, b), LCM(a, b));
	return 0;
}