#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using std::vector; using std::stack; using std::queue; using std::deque; using std::tuple;
using std::string; using std::pair; using std::make_tuple; using std::tie;
using std::sort;
using std::make_pair; using std::max_element; using std::min_element; using std::bitset; using std::to_string;
using std::fill; using std::priority_queue; using std::greater;
//using std::max; using std::min; using std::map;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, int> pdi;
typedef pair<int, double> pid;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<int, char> pic;
typedef pair<char, int> pci;
typedef pair<string, int> psi;
typedef pair<int, string> pis;
typedef pair<string, string> pss;

int N, M, R, dir, **A, min;
int dxy[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} }; //µ¿ºÏ ¼­³²
void rotate(int start_x, int start_y, int R, int C);
void func();
void printAll(int**& C);
void init();

void init() {
	scanf("%d%d%d", &N, &M, &R);
	if (N > M)
		min = M;
	else
		min = N;
	A = new int* [N];
	for (int i = 0; i < N; i++) {
		A[i] = new int[M];
		for (int j = 0; j < M; j++)
			scanf("%d", &A[i][j]);
	}
}

void printAll(int**& C) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			printf("%d ", C[i][j]);
		printf("\n");
	}
}

void func() {
	while (R--) {
		for (int k = 0; k < min / 2; k++) {
			dir = 0;
			rotate(k, k, N - 2 * k, M - 2 * k);
		}
	}
}

vector<int>

//void rotate(int start_x, int start_y, int R, int C) {
//	int x, y, end_x, end_y;
//	tie(x, y, end_x, end_y) = make_tuple(start_x, start_y, R, C);
//	int cnt = 2 * (R - 1) + 2 * (C - 1);
//	while (cnt--) {
//		int xx = x + dxy[dir][0];
//		int yy = y + dxy[dir][1];
//		if (xx < start_x || yy < start_y || xx == end_x || yy == end_y) {
//			dir = (dir + 1) % 4;
//			xx = x + dxy[dir][0];
//			yy = y + dxy[dir][1];
//		}
//		int num = A[x][y];
//		B[xx][yy] = num;
//		x = xx;
//		y = yy;
//	}
//	x = start_x;
//	y = start_y;
//	end_x = start_x + R;
//	end_y = start_y + C;
//	cnt = 2 * (R - 1) + 2 * (C - 1);
//	while (cnt--) {
//		int xx = x + dxy[dir][0];
//		int yy = y + dxy[dir][1];
//		if (xx < start_x || yy < start_y || xx == end_x || yy == end_y) {
//			dir = (dir + 1) % 4;
//			xx = x + dxy[dir][0];
//			yy = y + dxy[dir][1];
//		}
//		A[xx][yy] = B[xx][yy];
//		x = xx;
//		y = yy;
//	}
//}

int main(void) {
	init();
	func();

	return 0;
}