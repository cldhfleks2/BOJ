#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using namespace std;

int main(void) {
	queue<int> q, res; //ť ����
	int N, K;
	scanf("%d%d", &N, &K);
	int test = N;
	for (int i = 1; i <= N; i++) { //ť�� �ٳ���
		q.push(i);
	}
	while (test--) {
		int loop = K-1;
		while (loop--) {
			int temp = q.front();
			q.pop();
			q.push(temp);
		}
		int temp = q.front();
		q.pop();
		res.push(temp);
	}
	// ���
	printf("<");
	for (int i = 0; i < N - 1; i++) {
		printf("%d, ", res.front());
		res.pop();
	}
	printf("%d>", res.front());

	return 0;
}