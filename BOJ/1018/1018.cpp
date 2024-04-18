#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>

int main(int m, int n) {
	scanf("%d %d\n", &m, &n);
	bool** chess = new bool* [m];
	for (int t = 0; t < m; t++) //M x N ü������ ����
		chess[t] = new bool[n];
	
	//�Է¹���
	//W : false
	//B : true
	for (int i = 0; i < m; i++) {
		char temp;
		for (int j = 0; j < n; j++) {
			scanf("%c", &temp);
			if (temp == 'W')
				chess[i][j] = false;
			else
				chess[i][j] = true;
		}
		scanf("%c", &temp); //�ٹٲ޹�������
	}
	int res = 0x7fffffff, temp = 0;

	//�»���� B�ΰ��
	for (int k = 0; 7 + k < m; k++) { //���������
		for (int l = 0; 7 + l < n; l++) { //����������

			//�»���� B�ΰ��
			for (int i = k; i < 8 + k; i++) {
				for (int j = l; j < 8 + l; j++) {
					if ((i + j) % 2 == 0) {
						if (chess[i][j] != true)
							temp++;
					}
					else {
						if (chess[i][j] != false)
							temp++;
					}
				}
			}
			if (res > temp)
				res = temp;
			temp = 0;

			//�»���� W�ΰ��
			for (int i = k; i < k + 8; i++) {
				for (int j = l; j < l + 8; j++) {
					if ((i + j) % 2 == 0) {
						if (chess[i][j] != false)
							temp++;
					}
					else {
						if (chess[i][j] != true)
							temp++;
					}
				}
			}
			if (res > temp)
				res = temp;
			temp = 0;
		}
	}
	printf("%d", res);

	return 0;
}