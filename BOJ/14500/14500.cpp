#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using std::vector; using std::pair;
typedef pair<int, int> pii;
int n, m, **map, max=0;

int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };
void init();
void func();
void pinkTetromino(int x, int y, vector<pii>& v, int cnt);
void tetromino(int X, int Y, vector<pii>& v, int cnt);

void init() {
	scanf("%d%d", &n, &m);
	map = new int* [n];
	for (int i = 0; i < n; i++) {
		map[i] = new int[m];
		for (int j = 0; j < m; j++)
			scanf("%d", &map[i][j]);
	}
}

void func() {
	vector<pii> v;
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < m; y++) {
			v.push_back({ x, y });
			tetromino(x, y, v, 4);
			v.pop_back();

			v.push_back({ x, y });
			pinkTetromino(x, y, v, 4);
			v.pop_back();
		}
	}
	printf("%d", max);
}

void pinkTetromino(int x, int y, vector<pii> &v, int cnt) {
	if (cnt == 0) {
		int res = 0;
		for (int k = 0; k < 4; k++)
			res += map[v[k].first][v[k].second];

		if (max < res)
			max = res; //최댓값 갱신

		return;
	}
	if (cnt == 4) {
		for (int dir = 0; dir < 4; dir++) {
			int xx = x + dx[dir];
			int yy = y + dy[dir];
			bool exist = false;

			//올바른 인덱스인가
			if (xx < 0 || yy < 0 || xx == n || yy == m) continue;

			//이미 있는값인가
			for (int k = 0; k < v.size(); k++)
				if (v[k].first == xx && v[k].second == yy) exist = true;
			if (exist) continue;

			v.push_back({ xx, yy });
			pinkTetromino(xx, yy, v, cnt - 1); //재귀적호출
			v.pop_back();
		}
	}
	if (cnt == 3) {
		for (int dir1 = 0; dir1 < 4; dir1++) {
			for (int dir2 = dir1 + 1; dir2 < 4; dir2++) {
				int x1 = x + dx[dir1];
				int y1 = y + dy[dir1];
				int x2 = x + dx[dir2];
				int y2 = y + dy[dir2];
				bool exist = false;

				//올바른 인덱스인가
				if (x1 < 0 || y1 < 0 || x1 == n || y1 == m) continue;
				if (x2 < 0 || y2 < 0 || x2 == n || y2 == m) continue;

				//이미 있는값인가
				for (int k = 0; k < v.size(); k++) {
					if (v[k].first == x1 && v[k].second == y1) exist = true;
					if (v[k].first == x2 && v[k].second == y2) exist = true;
				}

				if (exist) continue;

				v.push_back({ x1, y1 });
				v.push_back({ x2, y2 });
				pinkTetromino(x1, y1, v, 0); //재귀적호출
				v.pop_back();
				v.pop_back();
			}
		}
	}


}

void tetromino(int x, int y, vector<pii> &v, int cnt) {
	if (cnt == 0) {
		int res = 0;
		for (int k = 0; k < 4; k++)
			res += map[v[k].first][v[k].second];

		if (max < res)
			max = res; //최댓값 갱신

		return;
	}
	for (int dir = 0; dir < 4; dir++) {
		int xx = x + dx[dir];
		int yy = y + dy[dir];
		bool exist = false;

		//올바른 인덱스인가
		if (xx < 0 || yy < 0 || xx == n || yy == m) continue;
		
		//이미 있는값인가
		for (int k = 0; k < v.size(); k++) 
			if (v[k].first == xx && v[k].second == yy) exist = true;
		if (exist) continue;

		v.push_back({ xx, yy });
		tetromino(xx, yy, v, cnt - 1); //재귀적호출
		v.pop_back();
	}

}

int main(void) {
	init();
	func();

	return 0;
}