#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
using std::queue; using std::vector; using std::pair;
int K, V, E;
int visit[20001];
vector<int> edge[200001];

bool BFS(int start) {

	queue<pair<int, int>> q;
	q.push({ start, 0 });
	visit[start] = true;

	while (!q.empty()) {
		int v = q.front().first;
		int c = q.front().second;
		q.pop();

		for (int i = 0; i < edge[v].size(); i++) {
			int vv = edge[v][i];
			int cc = (c + 1) % 2; //0, 1로 기록함
			if (visit[vv] == -1) {
				visit[vv] = cc;
				q.push({vv, cc});
			}
			else if (visit[vv] != cc)
				return false;
		}
	}

	return true;
}

bool func() {
	for (int i = 1; i <= V; i++)
		visit[i] = -1;

	for (int i = 1; i <= V; i++) {
		if (visit[i] != -1) continue;
		if (!BFS(i)) return false;
	}
	return true;
}

int main(void) {
	scanf("%d", &K);
	while (K--) {
		scanf("%d%d", &V, &E);
		for (int i = 0, f, t; i < E; i++) {
			scanf("%d%d", &f, &t);
			edge[f].push_back(t);
			edge[t].push_back(f);
		}
		
		printf(func() ? "YES\n" : "NO\n");
	}

	return 0;
}