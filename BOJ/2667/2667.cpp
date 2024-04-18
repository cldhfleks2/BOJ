#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using std::queue; using std::pair; using std::sort;
typedef pair<int, int> pii;
int n, ** map, num=2, *res;
bool** visited;

int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

void init() {
	scanf("%d", &n);
	map = new int* [n];
	visited = new bool* [n];
	for (int i = 0; i < n; i++) {
		map[i] = new int[n];
		visited[i] = new bool[n];
		char _;
		scanf("%c", &_);
		for (int j = 0; j < n; j++) {
			scanf("%c", &_);
			if (_ == '0')
				map[i][j] = 0;
			else if (_ == '1')
				map[i][j] = 1;
		}
	}
}

void clear() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			visited[i][j] = false;
}

void printAll() {
	res = new int[num - 2];
	for (int k = 0; k < num - 2; k++) {
		int cnt = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (map[i][j] == k + 2)
					cnt++;
		res[k] = cnt;
	}
	
	sort(res, res + num - 2);

	printf("%d\n", num - 2);

	for (int k = 0; k < num - 2; k++)
		printf("%d\n", res[k]);
}

void func() {
	queue<pii> home;
	while (1) {
		clear();
		bool find = false;
		pii p;
		for (int i = 0; i < n; i++) {
			if (find)
				break;
			for (int j = 0; j < n; j++) {
				if (map[i][j] == 1) {
					p = { i, j };
					find = true;
					break;
				}
			}
		}
		if (!find) {
			printAll();
			break;
		}
		home.push(p);
		visited[p.first][p.second];
		map[p.first][p.second] = num;

		while (!home.empty()) {
			int x = home.front().first;
			int y = home.front().second;
			home.pop();

			for (int d = 0; d < 4; d++) {
				int xx = x + dx[d];
				int yy = y + dy[d];

				if (xx < 0 || yy < 0 || xx == n || yy == n) continue;

				if (map[xx][yy] == 0) continue;

				if (!visited[xx][yy]) {
					visited[xx][yy] = true;
					map[xx][yy] = num; //단지수로 색칠
					home.push({ xx, yy });
				}
			}
		}

		num++;
	}

}


int main(void) {
	init();
	func();

	return 0;
}