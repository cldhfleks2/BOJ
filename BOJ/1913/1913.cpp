#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>

int main(void) {

	int n, m;
	scanf("%d\n%d", &n, &m);

	int** map = new int* [n]; //�޸𸮼���
	for (int i = 0; i < n; i++)
		map[i] = new int[n];

	for (int i = 0; i < n; i++) //�ʱ�ȭ
		for (int j = 0; j < n; j++)
			map[i][j] = 0;
	

	//0 : ��
	//1 : ��
	//2 : ��
	//3 : ��
	int flag = 0; //������ ���
	int r = 0, c = 0; //��, �� ��ġ
	//�����±��� ���������� �ϴ� 4���� ����
	int down = n, right = n, up = -1, left = 0; 
	//ã�����ϴ� ���� ��ġ
	int locX, locY;
	
	for (int i = n*n; i >= 1; i--) { //������ ���
		map[r][c] = i; //������ġ ���

		if (i == m) {
			locX = r;
			locY = c;
		}

		if (flag == 0) {
			r++;

			if (r == down) {
				r--;
				c++;
				flag++;
				down--;
			}
		}
		else if (flag == 1) {
			c++;

			if (c == right) {
				c--;
				r--;
				flag++;
				right--;
			}
		}
		else if (flag == 2) {
			r--;

			if (r == up) {
				r++;
				c--;
				flag++;
				up++;
			}
		}
		else if (flag == 3) {
			c--;

			if (c == left) {
				c++;
				r++;
				flag = 0;
				left++;
			}
		}

	}

	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
	printf("%d %d", locX+1, locY+1);

	return 0;
}