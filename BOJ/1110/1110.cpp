#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using std::to_string; using std::stoi;


void func(int n) {
	int _, res=0, num=n;
	while (1) {
		_ = (n % 10) * 10 + (n / 10 + n % 10) % 10;
		res++;
		n = _;
		if (_ == num) break;
	}
	printf("%d", res);
}


int main(int n) {
	scanf("%d", &n);
	func(n);

	return 0;
}