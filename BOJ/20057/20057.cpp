#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
int n, **sand, dir=0; //�����γ������� ����ϱ����� 4��ŭ��ũ�� ����
int limit[] = {0, 0, 0, 0}; //��

int dx[] = {0, 1, 0, -1}; //���Ͽ��
int dy[] = {-1, 0, 1, 0};
void printAll();
void init();
void hurricane();
void sandFlying(int x, int y, int dir);

void calculate() {
	int res = 0;
	for (int k = 2; k <= n + 3; k++) {
		res += sand[0][k]; res += sand[1][k];
	}
	for (int k = 2; k <= n + 3; k++) {
		res += sand[k][n + 2]; res += sand[k][n + 3];
	}
	for (int k = n + 1; k >= 0 ; k--) {
		res += sand[n + 2][k]; res += sand[n + 3][k];
	}
	for (int k = n + 1; k >= 0; k--) {
		res += sand[k][0]; res += sand[k][1];
	}
	printf("%d", res);
}

void init() {
	scanf("%d", &n);
	sand = new int* [n + 4];
	for (int i = 0; i < n + 4; i++) {
		sand[i] = new int[n + 4];
		for (int j = 0; j < n + 4; j++)
			sand[i][j] = 0; //�ʱ�ȭ
	}

	for (int i = 2; i < n + 2; i++)
		for (int j = 2; j < n + 2; j++)
			scanf("%d", &sand[i][j]);
}

void hurricane() {
	int x = (n + 4) / 2, y = (n + 4) / 2;
	limit[0] = (n + 4) / 2 - 2;
	limit[1] = (n + 4) / 2 + 2;
	limit[2] = (n + 4) / 2 + 2;
	limit[3] = (n + 4) / 2 - 2;
	int cnt = n * n - 1;
	while (cnt--) {
		int xx = x + dx[dir];
		int yy = y + dy[dir];
		if ((dir == 0 && limit[dir] == yy) || //�����ؾ��ϴ»�Ȳ�̸�
			(dir == 1 && limit[dir] == xx) ||
			(dir == 2 && limit[dir] == yy) ||
			(dir == 3 && limit[dir] == xx)) {
			if (dir == 0) limit[dir]--;
			if (dir == 1) limit[dir]++;
			if (dir == 2) limit[dir]++;
			if (dir == 3) limit[dir]--;

			dir = (dir + 1) % 4; //������ȯ
			xx = x + dx[dir]; //������ġ �缳��
			yy = y + dy[dir]; 
		}

		x = xx;
		y = yy;
		sandFlying(x, y, dir);
	}

	calculate();
}

void sandFlying(int xx, int yy, int ddir) {
	int amount = sand[xx][yy]; //���Ǿ�
	sand[xx][yy] = 0; 
	int a=(int)(amount * 0.1), b=(int)(amount * 0.01),
		c=(int)(amount * 0.02), d=(int)(amount * 0.07),
		e=(int)(amount * 0.05);

	if (dir % 2 == 0) { //�� ��
		sand[xx + dx[(ddir + 3) % 4]][yy + dy[ddir]] += a;
		sand[xx + dx[(ddir + 3) % 4]][yy + dy[(ddir + 2) % 4]] += b;
		sand[xx + 2 * dx[(ddir + 3) % 4]][yy] += c;
		sand[xx + dx[(ddir + 3) % 4]][yy] += d;

		sand[xx][yy + 2 * dy[ddir]] += e;

		sand[xx + dx[(ddir + 1) % 4]][yy] += d;
		sand[xx + 2 * dx[(ddir + 1) % 4]][yy] += c;
		sand[xx + dx[(ddir + 1) % 4]][yy + dy[(ddir + 2) % 4]] += b;
		sand[xx + dx[(ddir + 1) % 4]][yy + dy[ddir]] += a;
	}
	else { //�� ��
		sand[xx + dx[ddir]][yy + dy[(ddir + 3) % 4]] += a;
		sand[xx + dx[(ddir + 2) % 4]][yy + dy[(ddir + 3) % 4]] += b;
		sand[xx][yy + 2 * dy[(ddir + 3) % 4]] += c;
		sand[xx][yy + dy[(ddir + 3) % 4]] += d;

		sand[xx + 2 * dx[ddir]][yy] += e;

		sand[xx][yy + dy[(ddir + 1) % 4]] += d;
		sand[xx][yy + 2 * dy[(ddir + 1) % 4]] += c;
		sand[xx + dx[(ddir + 2) % 4]][yy + dy[(ddir + 1) % 4]] += b;
		sand[xx + dx[ddir]][yy + dy[(ddir + 1) % 4]] += a;
	}

	amount = amount - (a + b + c + d + e + d + c + b + a);
	//����
	sand[xx + dx[ddir]][yy + dy[ddir]] += amount;
}

int main(void) {
	init();
	hurricane();

	return 0;
}