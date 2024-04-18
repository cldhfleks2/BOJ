#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>

int main(void) {
	int R, C, W, **pt;
	scanf("%d%d%d", &R, &C, &W);
	int size = (R + W);
	pt = new int*[size * (size + 1) / 2 + 1];
	//pt[i][j] i��°�� j��°���� (1���ͽ���)
	for (int i = 1; i <= size; i++) {
		pt[i] = new int[i+1]; //�����ε����� 1���ͼ� 
		pt[i][0] = 0;
	}
	for (int i = 1; i <= size; i++) { //i��°��
		for (int j = 1; j <= i; j++) { //j��° ����
			if (j == 1 || j == i) {
				pt[i][j] = 1; //�糡���ڴ� 1
				//printf("%d ", pt[i][j]);
			}
			else {
			//������ ��������������
			pt[i][j] = pt[i - 1][j - 1] + pt[i - 1][j]; 
			//printf("%d  ", pt[i][j]);
			}
		}
		//printf("\n");
	}
	int res = 0;
	for (int i = 1; i <= W; i++) {
		for (int j = 1; j <= i; j++) {
			res += pt[R + i-1][C + j -1];
			//printf("%d  ", pt[i+ C + R -2][j+ C -1]);
		}
		//printf("\n");
	}
	printf("%d", res);

	return 0;
}