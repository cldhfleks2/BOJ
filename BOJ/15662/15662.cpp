#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using std::vector;
int t, k;
vector<int> gear[1001];
int right[1001], left[1001], top[1001];
void init();
void clockRotate(int g, int side);
void func();

void func() {
	while (k--) {
		int g, side, g_left, g_right;
		scanf("%d%d", &g, &side);
		g_left = g; //�������� ���ʱ���ȣ
		g_right = g; //�������� �����ʱ���ȣ
		while (1 <= g_left - 1) {
			if (gear[g_left - 1][right[g_left - 1]] == gear[g_left][left[g_left]]) break; //���� ���̸� �ȵ��ư�
			g_left--; 
		}
		while (g_right + 1 <= t) {
			if (gear[g_right][right[g_right]] == gear[g_right + 1][left[g_right + 1]]) break;
			g_right++; 
		}
		//g_left~ g_right ���� ��� �� ��������
		bool _ = true;
		for (int i = g - 1; g_left <= i; i--) {
			if(_)
				clockRotate(i, side * (-1));
			else
				clockRotate(i, side);
			_ = !_;
		}
		clockRotate(g, side); //����� ����
		_ = true;
		for (int i = g + 1; i <= g_right; i++) {
			if (_)
				clockRotate(i, side * (-1));
			else
				clockRotate(i, side);
			_ = !_;
		}
	}

	int res = 0;
	for (int i = 1; i <= t; i++)
		res += gear[i][top[i]];

	printf("%d", res);
}

//����ȣ, ������ �Է¹޾Ƽ� �� ����
void clockRotate(int g, int side) {
	//�����δ� ����� �������� ����Ű�� �����͸� ȸ��
	if (side == -1) {
		top[g] = (top[g] + 1) % 8;
		right[g] = (right[g] + 1) % 8;
		left[g] = (left[g] + 1) % 8;
	}
	else {
		top[g] = (top[g] + 7) % 8;
		right[g] = (right[g] + 7) % 8;
		left[g] = (left[g] + 7) % 8;
	}
}

void init() {
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		char _;
		scanf("%c", &_);
		for (int j = 0; j < 8; j++) {
			scanf("%c", &_);
			if (_ == '0')
				gear[i].push_back(0);
			else if (_ == '1')
				gear[i].push_back(1);
		}
		top[i] = 0;
		right[i] = 2;
		left[i] = 6;
	}
	scanf("%d", &k);
}


int main(void) {
	init();
	func();

	return 0;
}