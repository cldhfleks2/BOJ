#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>

int main(int n) {
	while (scanf("%d", &n) != EOF) {
		
		int* seq = new int[n];
		for (int i = 0; i < n; i++)
			scanf("%d", &seq[i]);

		int* num = new int[n];
		bool destroyed = false;
		for (int i = 1; i <= n-1; i++) //�ʱ�ȭ
			num[i] = 0;

		for (int i = 0; i < n-1; i++) {
			int diff = abs(seq[i] - seq[i + 1]); //�μ� ���� ����
			if (diff < 1 || n - 1 < diff) { //������ ������ Not jolly
				destroyed = true;
				break;
			}
			if (num[diff] > 0) { //�ߺ��Ȱ�� Not jolly
				destroyed = true;
				break;
			}
			else {
				num[diff]++; //üũ
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