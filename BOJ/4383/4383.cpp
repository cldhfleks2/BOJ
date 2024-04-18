#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>

int main(int n) {
	while (scanf("%d", &n) != EOF) {
		
		int* seq = new int[n];
		for (int i = 0; i < n; i++)
			scanf("%d", &seq[i]);

		int* num = new int[n];
		bool destroyed = false;
		for (int i = 1; i <= n-1; i++) //초기화
			num[i] = 0;

		for (int i = 0; i < n-1; i++) {
			int diff = abs(seq[i] - seq[i + 1]); //두수 차의 절댓값
			if (diff < 1 || n - 1 < diff) { //절댓값이 범위외 Not jolly
				destroyed = true;
				break;
			}
			if (num[diff] > 0) { //중복된경우 Not jolly
				destroyed = true;
				break;
			}
			else {
				num[diff]++; //체크
			}
		}

		if (destroyed) {
			printf("Not jolly\n");
		}
		else {
			printf("Jolly\n");
		}

	}

	return 0;
}