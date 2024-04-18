#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
int dp[15][15]; //0��~14�� : 1ȣ~14ȣ

int DP(int k, int n) {
	if (k == 0) return n; //0�� iȣ���� i���� ���

	int sum = 0;
	//�޸������̼ǰ� ��͸� ���� k-1���� 1~nȣ�Ǳ������� ����
	for (int i = 1; i <= n; i++) { 
		if (dp[k - 1][i] != -1)
			sum += dp[k - 1][i]; //�̹������� ������
		else
			sum += DP(k - 1, i); //�����ȣ��
	}
	//���� ���� ����
	dp[k][n] = sum; 
	return sum;
}

int main(int t, int k, int n) {
	scanf("%d", &t);
	for (int i = 0; i < 15; i++) for (int j = 0; j < 15; j++) dp[i][j] = -1; //�ʱ�ȭ
	for (int i = 1; i <= 14; i++) dp[0][i] = i; //0�� iȣ���� i���̻��.
	while (t--) {
		scanf("%d%d", &k, &n);
		if (dp[k][n] != -1) { //�̹� ã�����̸�
			printf("%d\n", dp[k][n]);
			continue;
		}

		printf("%d\n", DP(k, n));
	}


	return 0;
}