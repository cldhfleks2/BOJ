#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>

int main(int n) {
	scanf("%d", &n);
	std::queue<int> q;
	for (int i = 1; i <= n; i++) //1~N
		q.push(i);
	//1장남을때까지 반복
	while (n > 2) {
		q.pop();
		int num = q.front();
		q.pop();
		q.push(num);
		n--;
	}

	printf("%d", q.back());

	return 0;
}