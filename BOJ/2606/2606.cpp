#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>
using std::vector; using std::queue;
int n, r, res = 0;
vector<int> edge[101];
bool *visited; //방문했는지확인

void virus() {
	queue<int> list;
	list.push(1);
	visited[1] = true;

	while (!list.empty()) {
		int from = list.front();
		list.pop();

		for (int i = 0; i < edge[from].size(); i++) {
			int to = edge[from][i];
			if (!visited[to]) {
				visited[to] = true;
				list.push(to);
				res++;
			}
		}
	}
}

int main(int a, int b) {
	scanf("%d%d", &n, &r);
	visited = new bool[n + 1];
	for (int i = 1; i <= n; i++)
		visited[i] = false;

	while (r--) {
		scanf("%d%d", &a, &b);
		edge[a].push_back(b);
		edge[b].push_back(a);
	}

	virus();

	printf("%d", res);

	return 0;
}