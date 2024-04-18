#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
using std::vector;
vector<int> edge[101];
int n, m, v1, v2;
bool visited[101];

void DFS(int x, int y, int cnt, bool& end) {
	if (x == y) {
		printf("%d\n", cnt);
		end = true;
		return;
	}

	visited[x] = true;

	for (int i = 0; i < edge[x].size(); i++) {
		int xx = edge[x][i];
		if (visited[xx]) continue;
		if (end) return;
		DFS(xx, y, cnt + 1, end);
	}
}

int main(void) {
	scanf("%d%d%d%d", &n, &v1, &v2, &m);
	while (m--) {
		int x, y;
		scanf("%d%d", &x, &y);
		edge[x].push_back(y);
		edge[y].push_back(x);
	}

	bool end = false;
	DFS(v1, v2, 0, end);
	if (!end) printf("-1");

	return 0;
}

