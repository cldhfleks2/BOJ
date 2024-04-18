#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
int n, m, x, y, k, **map;
int top = 0, right = 0, forward = 0, left = 0, backward = 0, bottom = 0;

void roll(int dir) { //1~4 �������� �ֻ����� ����
	int temp = top;
	if (dir == 1) { //�������� �ֻ����� ����
		top = left;
		left = bottom;
		bottom = right;
		right = temp;
	}
	else if (dir == 2) {
		top = right;
		right = bottom;
		bottom = left;
		left = temp;
	}
	else if (dir == 3) {
		top = backward;
		backward = bottom;
		bottom = forward;
		forward = temp;
	}
	else if (dir == 4) {
		top = forward;
		forward = bottom;
		bottom = backward;
		backward = temp;
	}
}

int main(void) {
	scanf("%d %d %d %d %d", &n, &m, &x, &y, &k);
	map = new int* [n];
	for (int i = 0; i < n; i++) {
		map[i] = new int[m];
		for (int j = 0; j < m; j++)
			scanf("%d", &map[i][j]);
	}

	for (int i = 0, dir; i < k; i++) {
		scanf("%d", &dir);
		//��ɾ��� ������ �ֻ����� ������.
		if (dir == 1) {
			if (y + 1 >= m) { //�ֻ����� ������ ����� ����
				continue;
			}
			y++;
			roll(1);
		}
		else if (dir == 2) {
			if (y - 1 <= -1) {
				continue;
			}
			y--;
			roll(2);
		}
		else if (dir == 3) {
			if (x - 1 <= -1) {
				continue;
			}
			x--;
			roll(3);
		}
		else if (dir == 4) {
			if (x + 1 >=  n) {
				continue;
			}
			x++;
			roll(4);
		}
		//�������ֻ����� �����ٴ��� ���Ͽ� ���ڸ� ����
		if (map[x][y] == 0) { //������ ���� ���ڰ� 0�̸�
			map[x][y] = bottom; //�ֻ��� �ٴڼ��ڸ� ������ ����
		}
		else {
			bottom = map[x][y]; //���������� ���ڸ� �ֻ��� �ٴ����� ����
			map[x][y] = 0; //ĭ�� ���μ��ڸ� 0���� �ʱ�ȭ
		}
		printf("%d\n", top); //�ֻ��� ����� ���ڸ� �����

	}
	return 0;
}