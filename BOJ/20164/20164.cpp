#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
int N, max=0, min=0x7fffffff;

int findOddCnt(char* c, int size) {
	int odd = 0;
	for (int i = 0; i < size; i++)
		if ((c[i] - '0') % 2 != 0) odd++;
	return odd;
}

//�ּڰ��� ����
void func(int n, int cnt) {
	int size = 1, _ = n, n2, odd = 0; 
	while (_ / 10 != 0) { //�ڸ������ϱ�
		size++;
		_ /= 10;
	}
	char c[10];
	sprintf(c, "%d", n); //���ڿ��� ��ȯ
	//1�ܰ� : ���ڸ� ������ Ȧ�� ������ ����
	odd += findOddCnt(c, size);

	//2�ܰ� : ���ڸ��� ���� : ������ ��������.
	//�̰����� ��� �ִ� �ּ� ������ �̷����
	if (size == 1) {
		if (max < cnt + odd) max = cnt + odd;
		if (min > cnt + odd) min = cnt + odd;
		return;
	}

	//3�ܰ� : ���ڸ���
	if (size == 2)
		func((c[0] - '0') + (c[1] - '0'), cnt + odd);

	//4�ܰ� ���ڸ��̻��̸�
	if (size >= 3) {
		for (int i = 1; i < size - 1; i++) {
			for (int j = i + 1; j < size; j++) {
				int s1=0, s2=0, s3=0;
				char c1[10] = {'\0',}, c2[10] = { '\0', }, c3[10] = { '\0', };
				//3������� �ڸ�
				for (int k = 0; k < i; k++) { 
					c1[s1] = c[k];
					s1++;
				}
				for (int k = i; k < j; k++) {
					c2[s2] = c[k];
					s2++;
				}
				for (int k = j; k < size; k++) {
					c3[s3] = c[k];
					s3++;
				}
				//������ ��ȯ
				n2 = atoi(c1) + atoi(c2) + atoi(c3);

				func(n2, cnt + odd);
			}
		}
	}
}

int main(void) {
	scanf("%d", &N);

	func(N, 0);
	printf("%d %d", min, max);

	return 0;
}