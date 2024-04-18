#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using std::queue; using std::pair; using std::stack;
int n, ** map;
bool** visited;
int dx[2] = { 0, 1 };
int dy[2] = { 1, 0 };

bool bfs() {
	queue<pair<int, int>> q;
	q.push({ 0, 0 });
	visited[0][0] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (map[x][y] == -1) //���������ϰ�� ��������
			return true;

		for (int i = 0; i < 2; i++) { //������, �Ʒ��θ� �̵�
			//���� ��ǥ : ���� �Ǵ� �Ʒ��� map�� ������ŭ �̵�
			int xx = x + dx[i] * map[x][y];
			int yy = y + dy[i] * map[x][y];

			//�f���� ��ȿ�� ����ǥ�� ��������
			if (0 <= xx && xx <= n - 1 && 0 <= yy && yy <= n - 1) {
				if (!visited[xx][yy]) {
					visited[xx][yy] = true;
					q.push({ xx, yy }); //ť���ְ� �ݺ�
				}
			}

		}
	}

	return false;
}

bool dfs() {
	stack<pair<int, int>> s;
	s.push({ 0, 0 });
	visited[0][0] = true;

	while (!s.empty()) {
		int x = s.top().first;
		int y = s.top().second;
		s.pop();

		if (map[x][y] == -1)
			return true;

		for (int i = 0; i < 2; i++) {
			int xx = x + dx[i] * map[x][y];
			int yy = y + dy[i] * map[x][y];

			if (0 <= xx && xx <= n - 1 && 0 <= yy && yy <= n - 1) {
				if (!visited[xx][yy]) {
					visited[xx][yy] = true;
					s.push({ xx, yy });
				}
			}

		}

	}

	return false;
}

int main(void) {
	scanf("%d", &n);
	map = new int* [n];
	visited = new bool* [n];
	for (int i = 0; i < n; i++) {
		map[i] = new int[n];
		visited[i] = new bool[n];
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
			visited[i][j] = false;
		}
	}

	//if (bfs())
	//	printf("HaruHaru");
	//else
	//	printf("Hing");

	if (dfs())
		printf("HaruHaru");
	else
		printf("Hing");


	return 0;
}