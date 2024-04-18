#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using std::vector; using std::pair;
typedef pair<int, int> pii;
int t;


int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };




//현재 X오미노의 최대크기를 계산
pii findMaxSize(vector<pii> &v) { 
	int max_x = 0, max_y = 0;
	for (int i = 0; i < v.size(); i++) {
		if (max_x < v[i].first) max_x = v[i].first;
		if (max_y < v[i].second) max_y = v[i].second;
	}
	return { max_x, max_y };
}

void init() {
	scanf("%d", &t);
}

void func() {
	vector<pii> v;
	while (t--) {
		int X, r, c;
		scanf("%d%d%d", &X, &r, &c);
		v.push_back({ 0, 0 });
		Xomino(0, 0, r, c, v, 4);
		v.pop_back();


		v.push_back({ 0, 0 });
		Xomino2(0, 0, r, c, v, 4, 4);
		v.pop_back();


	}

	
}

void Xomino2(int x, int y, int r, int c, vector<pii>& v, int cnt, int X) {
	if (cnt == 0) {
		



		return;
	}
	if (cnt == X) {
		for (int dir = 0; dir < 4; dir++) {
			int xx = x + dx[dir];
			int yy = y + dy[dir];
			bool exist = false;

			//올바른 인덱스인가
			if (xx < 0 || yy < 0 || xx == r || yy == c) continue;

			//이미 있는값인가
			for (int k = 0; k < v.size(); k++)
				if (v[k].first == xx && v[k].second == yy) exist = true;
			if (exist) continue;

			v.push_back({ xx, yy });
			Xomino2(xx, yy, r, c, v, cnt - 1, X); //재귀적호출
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
				if (x1 < 0 || y1 < 0 || x1 == r || y1 == c) continue;
				if (x2 < 0 || y2 < 0 || x2 == r || y2 == c) continue;

				//이미 있는값인가
				for (int k = 0; k < v.size(); k++) {
					if (v[k].first == x1 && v[k].second == y1) exist = true;
					if (v[k].first == x2 && v[k].second == y2) exist = true;
				}

				if (exist) continue;

				v.push_back({ x1, y1 });
				v.push_back({ x2, y2 });
				Xomino2(x1, y, r, c, v, 0, X); //재귀적호출
				v.pop_back();
				v.pop_back();
			}
		}
	}


}

void Xomino(int x, int y, int r, int c, vector<pii>& v, int cnt) {
	if (cnt == 0) {
		



		return;
	}
	for (int dir = 0; dir < 4; dir++) {
		int xx = x + dx[dir];
		int yy = y + dy[dir];
		bool exist = false;

		//올바른 인덱스인가
		if (xx < 0 || yy < 0 || xx == r || yy == c) continue;

		//이미 있는값인가
		for (int k = 0; k < v.size(); k++)
			if (v[k].first == xx && v[k].second == yy) exist = true;
		if (exist) continue;

		v.push_back({ xx, yy });
		Xomino(xx, yy, r, c, v, cnt - 1); //재귀적호출
		v.pop_back();
	}

}

int main(void) {
	init();
	func();

	return 0;
}
