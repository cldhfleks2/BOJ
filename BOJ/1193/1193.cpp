#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
int X;
int dx[4] = {1, 1, -1, 0}; //����, ��, ���, �� �����ιݺ�
int dy[4] = {-1, 0, 1, 1};

int main() {
	scanf("%d", &X);
	if (X == 1) { //����ó���ع�����
		printf("1/1");
		return 0;
	}
	int dir = 0;
	int x = 1, y = 2; //�ʱⰪ 1/2
	bool check = false;
	for (int i = 2; i < X; i++) {
		int xx = x + dx[dir];
		int yy = y + dy[dir];
		if (dir == 1 || dir == 3) check = true;
		x = xx; y = yy; //�м� ����

		//������ �ٲٴ°�츦 üũ
		if ((dir == 0 && yy == 1) || (dir == 1 && check) ||
			(dir == 2 && xx == 1) || (dir == 3 && check)) {
			check = false;
			dir++;
		}
		if (dir == 4) dir = 0; //���� ��ȯ
		//printf(">> %d %d\n", x, y);
	}
	printf("%d/%d", x, y);

	return 0;
}