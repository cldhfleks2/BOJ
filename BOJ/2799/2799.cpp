#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>

int m, n;

int main(void) {
	scanf("%d %d\n", &m, &n);
	char junk[502];
	int res[5] = { 0, };
	char** arr = new char* [5*m];
	for (int i = 0; i < 5 * m; i++)
		arr[i] = new char[5 * n + 1]; //������ \0���ڱ��� ����� ũ��

	//�ι������� ############# �� ��������
	scanf("%[^\n]s", &junk); //######## ����

	for (int i = 0; i < 5 * m; i++) {
		scanf("%[\n]c", &junk); //�ٹٲ޹��ڸ� ����

		for (int j = 0; j < 5 * n + 1; j++) {
			scanf("%c", &arr[i][j]);
		}
	}
	//m x n �࿭�� �����Ѵ�.
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			int check = 0;
			for (int k = 0; k < 4; k++) { //4�ٿ� �ش��ϴ� ����ε带 Ž��
				char c = arr[5 * i + k][5 * j + 1];
				if (c == '.') //�����ɹ߽߰� ����
					break;
				check++; //�ƴϸ� ��ӹݺ��Ͽ� ����ε� ���¸� ����
			}
			//������ ����ε� ���¿����� �ᱣ���� �ݿ�
			res[check]++;
		}
	}
	for (int i = 0; i < 5; i++)
		printf("%d ", res[i]);
	
	return 0;
}