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
		g_left = g; //현재기어의 왼쪽기어번호
		g_right = g; //현재기어의 오른쪽기어번호
		while (1 <= g_left - 1) {
			if (gear[g_left - 1][right[g_left - 1]] == gear[g_left][left[g_left]]) break; //같은 극이면 안돌아감
			g_left--; 
		}
		while (g_right + 1 <= t) {
			if (gear[g_right][right[g_right]] == gear[g_right + 1][left[g_right + 1]]) break;
			g_right++; 
		}
		//g_left~ g_right 까지 모두 기어를 돌려야함
		bool _ = true;
		for (int i = g - 1; g_left <= i; i--) {
			if(_)
				clockRotate(i, side * (-1));
			else
				clockRotate(i, side);
			_ = !_;
		}
		clockRotate(g, side); //현재기어를 돌림
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

//기어번호, 방향을 입력받아서 기어를 돌림
void clockRotate(int g, int side) {
	//실제로는 기어의 각방향을 가리키는 포인터를 회전
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